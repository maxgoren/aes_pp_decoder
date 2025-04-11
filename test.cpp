#include <iostream>
#include "packet.hpp"
#include "util.hpp"
using namespace std;


void test() {
    string packetBody[] =  {
        "PP00003C333300000040844084000000A5000662545454545406A15793635055063F",
        "PP9200340000A1110110000000820C055092080180001FFE0001000045E2",
        "PP02001a0000133700EF130000830020500008018000200206010000AEF3",
        "PPff00300000001100014500008300005E4A1E0180001FFE0A30302030313435203138204531313520303020433136300D00BAA5"
    };
    for (int i = 0; i < 4; i++) {
        Packet p = hexStringToPacket(packetBody[i]);
        cout<<"Packet: "<<packetBody[i]<<endl;
        printPacket(p);
    }
}

int main() {
    test();
}