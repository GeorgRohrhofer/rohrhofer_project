
#include <iostream>
#include <thread>
#include <asio.hpp>

#include "messages.pb.h"

using namespace std;

//int main(int argc, char* argv[]) {
int main() {
    GOOGLE_PROTOBUF_VERIFY_VERSION;
    thread t{[]{ cout << "Hello"; }};
    t.join();
    cout << " world!" << endl;
    return 0;
}
