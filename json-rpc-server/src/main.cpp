
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
    s.register_calc_function("subtract", subtract);
    s.register_calc_function("multiply", multiply);
    s.register_calc_function("divide", divide);
    
    s.start();

    return 0;
}
