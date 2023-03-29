#pragma once

#include <map>
#include <initializer_list>
#include <vector>
#include <asio.hpp>

#include "messages.pb.h"


class Server{
private:
    JsonRPC *jrpc = new JsonRPC;
    unsigned short port{};
    std::map<std::string, std::function<std::string(std::vector<double>)>> calc_functions;
    void serve_client(asio::ip::tcp::socket&& sock);

public:
    Server(unsigned short port) : port{port}{}
    ~Server(){
        delete jrpc;
    }
    void start();
    void register_calc_function(std::string tag, std::function<std::string(std::vector<double>)> list);
    std::string start_calc_function(std::string tag, std::vector<double>);
};