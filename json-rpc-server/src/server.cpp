#include "server.h"

#include <asio.hpp>

#include <initializer_list>
#include <spdlog/spdlog.h>
#include <string>
#include <thread>
#include <json.hpp>
#include <vector>

//Synchroner Multi-Threading Server
void Server::start(){
    spdlog::info("Server is running on port " + std::to_string(this->port));

    asio::io_context ctx; 
    asio::ip::tcp::endpoint ep{asio::ip::tcp::v4(), 9999};
    asio::ip::tcp::acceptor acceptor{ctx, ep}; 
    acceptor.listen();
    while (true) {
        asio::ip::tcp::socket sock{ctx}; 
        acceptor.accept(sock);
        std::thread thd{&Server::serve_client, this, std::move(sock)}; //Neuer Thread für neue Verbindung
        thd.detach();
    }
}

//Funktion für die Bearbeitung einer Anfrage
void Server::serve_client(asio::ip::tcp::socket&& sock) {
    asio::streambuf buf;
    asio::read_until(sock, buf, '\n');
    std::istream is{&buf};
    jrpc->ParseFromIstream(&is);

    nlohmann::json j = nlohmann::json::parse(jrpc->text());

    spdlog::info(j.dump());

    std::vector v = j["params"].get<std::vector<double>>();
    //sock.close();
    nlohmann::json j2;
    j2["jsonrpc"] = 2.0;
    j2["result"] = stod(start_calc_function(j["method"], v));
    j2["id"] = 1;

    jrpc->set_text(j2.dump());

    asio::streambuf b;
    std::ostream os(&b);
    jrpc->SerializeToOstream(&os);

    asio::write(sock, b);
}

//Funktion für das Registrieren einer Funktion am Server
void Server::register_calc_function(std::string tag, std::function<std::string(std::vector<double>)> func){
    this->calc_functions[tag] = func; //Registrierte Funktion -> Dictionary (Bezeichnung, Funktion)
}

//Funktion für das Starten einer zuvor registrierten Funktion
std::string Server::start_calc_function(std::string tag, std::vector<double> list){
    return calc_functions[tag](list);
}