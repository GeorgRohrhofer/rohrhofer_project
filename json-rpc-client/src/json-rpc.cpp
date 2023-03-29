#include "json-rpc.h"
#include "messages.pb.h"

#include <iostream>
#include <ostream>
#include <thread>
#include <asio.hpp>
#include <spdlog/spdlog.h>
#include <json.hpp>
#include <vector>

using namespace std;

//Funktion um die Anfrage für einen Funktionsaufruf am Server zu versenden
double send_to_server(std::string method, std::vector<double> values){
    JsonRPC *jrpc = new JsonRPC();

    //JSON-Request
    nlohmann::json j;
    j["jsonrpc"] = 2.0;
    j["method"] = method;
    j["params"] = values;
    j["id"] = 1;

    jrpc->set_text(j.dump());
    asio::io_context ctx;
    asio::ip::tcp::resolver resolver{ctx};
    try{
        auto results = resolver.resolve("localhost", "9999");
        asio::ip::tcp::socket sock{ctx};

        asio::connect(sock, results);

        spdlog::info("Connected to Server");

        asio::streambuf b;
        ostream os(&b);
        jrpc->SerializeToOstream(&os);

        asio::write(sock, b);
        spdlog::info("Request Sent"); //Anfrage an den Server gesendet

        asio::streambuf buf;
        asio::read_until(sock, buf, '\n'); //Antwort einlesen
        std::istream is{&buf};
        jrpc->ParseFromIstream(&is);

        nlohmann::json j = nlohmann::json::parse(jrpc->text());

        spdlog::info(j.dump());

        double v = j["result"].get<double>();

        spdlog::info(v);
        sock.close();
        return v;
    }
    catch(asio::system_error& e){
        spdlog::error(e.what());
    }

    delete jrpc;
    return 0;
}

double add(std::vector<double> values){
    return send_to_server("add", values);
}
double subtract(std::vector<double> values){
    return send_to_server("subract", values);
}
double mulitply(std::vector<double> values){
    return send_to_server("multiply", values);
}
double divide(std::vector<double> values){
    return send_to_server("divide", values);
}