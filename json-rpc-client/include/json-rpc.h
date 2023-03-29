#pragma once

#include "messages.pb.h"

#include <iostream>
#include <ostream>
#include <thread>
#include <asio.hpp>
#include <spdlog/spdlog.h>
#include <json.hpp>

double send_to_server(std::vector<double> values);

double add(std::vector<double> values);
double subtract(std::vector<double> values);
double mulitply(std::vector<double> values);
double divide(std::vector<double> values);