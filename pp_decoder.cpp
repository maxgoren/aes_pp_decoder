#include <iostream>
#include "packet.hpp"
#include "util.hpp"
using namespace std;

void printBanner();

void printUsage() {
    cout<<" PP Packet decoder."<<endl;
    cout<<" Usage: \n";
    cout<<"          ./pp_decoder <optional flags> <packet string>\n"<<endl;
    cout<<" Options:   Flag  Description\n";
    cout<<"              -v  Verbose Mode, displays byte for byte decoding.\n"<<endl;
}

int main(int argc, char* argv[]) {
    printBanner();
    if (argc < 2) {
        printUsage();
        return -1;
    }
    if (argv[1][0] == '-' && argv[1][1] == 'v') {
        printPacket(hexStringToPacket(argv[2], true));
    } else {
        printPacket(hexStringToPacket(argv[1], false));
    }
    return 0;
}

void printBanner() {
    cout<<"\n---------------------------\n";
    cout<<"  aaaaaa   eeeeee   ssssss \n";
    cout<<" aa   aaa ee    ee s       \n";
    cout<<" aaaaaaaa eeeeeee   ssssss \n";
    cout<<" aa   aaa ee             ss\n";
    cout<<" aa   aaa  eeeeee  sssssss"<<endl;
    cout<<"-----INTERNAL USE ONLY----\n"<<endl;
}