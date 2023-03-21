
#include <iostream>
#include <ostream>
#include <thread>
#include <asio.hpp>
#include <spdlog/spdlog.h>

#include "messages.pb.h"

using namespace std;
using namespace asio::ip;

//int main(int argc, char* argv[]) {
int main() {
    GOOGLE_PROTOBUF_VERIFY_VERSION;
    JsonRPC *jrpc = new JsonRPC();
    jrpc->set_text("HELO");
    asio::io_context ctx;
    tcp::resolver resolver{ctx};
    try{
        auto results = resolver.resolve("localhost", "9999");
        tcp::socket sock{ctx};

        asio::connect(sock, results);

        spdlog::info("Connected to Server");

        const char request[]{jrpc->text()};
        size_t request_size = strlen(request);

        asio::write(sock, asio::buffer(request, request_size));
        spdlog::info("Request Sent");
    }
    catch(asio::system_error& e){
        spdlog::error(e.what());
    }

    delete jrpc;
    return 0;
}
