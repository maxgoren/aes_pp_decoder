#include <iostream>
#include "packet.hpp"
#include "util.hpp"
using namespace std;

void printUsage() {
    cout<<" PP Packet decoder.\n AES INTERNAL USE ONLY."<<endl;
    cout<<" Usage:  ./pp_decoder \"PP...\""<<endl;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printUsage();
        return -1;
    }
    printPacket(hexStringToPacket(argv[1]));
    return 0;
}
