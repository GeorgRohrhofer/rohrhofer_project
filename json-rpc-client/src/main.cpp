
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
    jrpc->set_text("add");
    asio::io_context ctx;
    tcp::resolver resolver{ctx};
    try{
        auto results = resolver.resolve("localhost", "9999");
        tcp::socket sock{ctx};

        asio::connect(sock, results);

        spdlog::info("Connected to Server");

        asio::streambuf b;
        ostream os(&b);
        jrpc->SerializeToOstream(&os);

        asio::write(sock, b);
        spdlog::info("Request Sent");
    }
    catch(asio::system_error& e){
        spdlog::error(e.what());
    }

    delete jrpc;
    return 0;
}
