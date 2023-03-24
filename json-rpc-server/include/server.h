#pragma once

#include <map>

#include "messages.pb.h"

class Server{
private:
    JsonRPC *jrpc = new JsonRPC;
    unsigned short port{};
    std::map<std::string, std::function<double(double, double)>> calc_functions; 

public:
    Server(unsigned short port) : port{port}{}
    ~Server(){
        delete jrpc;
    }
    void start();
    void register_calc_function(std::string tag, std::function<double(double, double)> func);
    double start_calc_function(std::string tag, double value_1, double value_2);
};