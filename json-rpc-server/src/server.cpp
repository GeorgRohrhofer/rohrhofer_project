#include "server.h"

#include <asio.hpp>
#include <spdlog/spdlog.h>
#include <string>

void Server::start(){
    spdlog::info("Server is running on port " + std::to_string(this->port));

    while(true){
        asio::io_context ctx;
        asio::ip::tcp::endpoint ep{asio::ip::tcp::v4(), this->port};
        asio::ip::tcp::acceptor acceptor{ctx, ep};
        acceptor.listen();
        asio::ip::tcp::socket sock{ctx};
        acceptor.accept(sock);
        asio::ip::tcp::iostream *strm = new asio::ip::tcp::iostream(std::move(sock));
        jrpc->ParseFromIstream(strm);
        strm->close();

        spdlog::info(start_calc_function(jrpc->text(), 1,1));
    }
}

void Server::register_calc_function(std::string tag, std::function<double(double,double)> func){
    this->calc_functions[tag] = func;
}

double Server::start_calc_function(std::string tag, double value_1, double value_2){
    return calc_functions[tag](value_1, value_2);
}