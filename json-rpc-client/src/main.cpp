
#include <iostream>
#include <ostream>
#include <thread>
#include <asio.hpp>

#include "messages.pb.h"

using namespace std;
using namespace asio::ip;

//int main(int argc, char* argv[]) {
int main() {
    GOOGLE_PROTOBUF_VERIFY_VERSION;
    JsonRPC *jrpc = new JsonRPC();
    jrpc->set_text("HELO");
    tcp::iostream *strm = new tcp::iostream("localhost", "9999");
    //ostream str{};
    if(strm){
        jrpc->SerializeToOstream(strm);
        //strm << str;
    }

    delete jrpc;
    delete strm;
    return 0;
}
