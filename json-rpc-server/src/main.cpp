
#include <iostream>
#include <thread>
#include <asio.hpp>
#include <spdlog/spdlog.h>

#include "messages.pb.h"

using namespace std;
using namespace asio::ip;

//int main(int argc, char* argv[]) {
int main() {
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    spdlog::info("Server is running on port 9999");
    
    // change log pattern
    //spdlog::set_pattern("[%H:%M:%S %z] [%n] [%^---%L---%$] [thread %t] %v");
    
    // Compile time log levels
    // define SPDLOG_ACTIVE_LEVEL to desired level
    SPDLOG_TRACE("Some trace message with param {}", 42);
    SPDLOG_DEBUG("Some debug message");


    JsonRPC *jrpc = new JsonRPC;
    //jrpc->set_text("Hallo")
    asio::io_context ctx;
    tcp::endpoint ep{tcp::v4(), 9999};
    tcp::acceptor acceptor{ctx, ep}; // IO object
    acceptor.listen();
    tcp::socket sock{ctx};
    acceptor.accept(sock);
    tcp::iostream *strm = new tcp::iostream(std::move(sock));
    //shorter: tcp::iostream strm{acceptor.accept()};
    jrpc->ParseFromIstream(strm);
    strm->close();

    spdlog::info(jrpc->text());

    /*
    cout << jrpc->text() << endl;
    jrpc->SerializeToOstream(&cout);

    jrpc->ParseFromIstream(&cin);
    */
    delete jrpc;
    return 0;
}
