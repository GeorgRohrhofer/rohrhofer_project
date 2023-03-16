
#include <iostream>
#include <thread>
#include <asio.hpp>

#include "messages.pb.h"

using namespace std;

//int main(int argc, char* argv[]) {
int main() {
    GOOGLE_PROTOBUF_VERIFY_VERSION;
    JsonRPC *jrpc = new JsonRPC;
    jrpc->set_text("Hallo");

    cout << jrpc->text() << endl;
    jrpc->SerializeToOstream(&cout);

    jrpc->ParseFromIstream(&cin);
    delete jrpc;
    return 0;
}
