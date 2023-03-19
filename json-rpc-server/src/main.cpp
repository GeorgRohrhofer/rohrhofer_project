
#include <iostream>
#include <thread>
#include <asio.hpp>

#include "messages.pb.h"

using namespace std;
using namespace asio::ip;

//int main(int argc, char* argv[]) {
int main() {
    GOOGLE_PROTOBUF_VERIFY_VERSION;
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

    cout << jrpc->text() << endl;

    /*
    cout << jrpc->text() << endl;
    jrpc->SerializeToOstream(&cout);

    jrpc->ParseFromIstream(&cin);
    */
    delete jrpc;
    return 0;
}
