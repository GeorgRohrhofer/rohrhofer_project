
#include <iostream>

#include "messages.pb.h"
#include "server.h"
#include "utils.h"

using namespace std;

//int main(int argc, char* argv[]) {
int main() {
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    Server s{9999};

    s.register_calc_function("add", add);

    s.start();

    return 0;
}
