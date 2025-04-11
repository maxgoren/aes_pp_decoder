#ifndef packet_fields_hpp
#define packet_fields_hpp
#include "util.hpp"
/*
    offsets in hex string
*/
const int PACKET_START_POS = 8; //What _is_ all that other junk?

/*      
    offsets in byte array

         Packet field offsets        Description                 # bytes  */
const int TO = 0;                     /*  TO address                  2       */
const int FROM = 2;                   /*  FROM Address                2       */
const int LL = 4;                     /*  Link Layer of FROM station  1       */
const int ORIG = 5;                   /*  Address of originator       2       */
const int DEST = 7;                   /*  Final destination address   2       */
const int P_FLAGS = 9;                /*  Net ID                      1       */
const int TTYPE = 10;                 /*  TNC Type of FROM unit       1       */
const int uSTATUS = 11;               /*  Status of FROM unit         1       */
const int PID = 12;                   /*  Packet type identifier      1       */
const int PNUM = 13;                  /*  Packet Sequence # of orig   1       */
const int LEN = 14;                  /*  Data field length in bytes  1       */
const int DATA = 15;                  /*  start of data bytes         0 - 200 */

/*  
    

     PP00003C 3333 0000  00   4084  4084 00 00 00 A5  00  06      62545454545406A15793635055    063F
    "PP02001a 0000 1337  00   EF13  0000 83 00 20 50  00  08      018000200206010000            AEF3"
              {TO}{from}{LL}{origin}{DEST}       {PT}{SN}{LEN}       {payload}                 {check sum}
                                   (packet Type)(sequence number)(length)

*/ 

struct Packet {
    string hexCkSum;
    int cksum;
    string toId;
    string fromId;
    string originId;
    string destId;
    string body;
    int linkLayer;
    string packetType;
    int sequenceNumber;
    int payLoadLength;
    Packet() { } 
};


Packet hexStringToPacket(string hexString, bool verbose) {
    if (hexString.substr(0, 2) != "PP") {
        cout<<"Error: This Utility Only supports PP packets."<<endl;
        exit(0);
    }
    vector<Byte> bytes = hexStringToByteArray(hexString.substr(PACKET_START_POS), verbose);
    Packet p;
    p.cksum = calculateChecksum(bytes, bytes.size()-2);
    p.toId = extractString(bytes, TO, 2);
    p.fromId = extractString(bytes, FROM, 2);
    p.originId = extractString(bytes, ORIG, 2);
    p.destId = extractString(bytes, DEST, 2);
    p.linkLayer = byteToInt(bytes[LL]);
    p.packetType = extractString(bytes, PID, 1);
    p.sequenceNumber = byteToInt(bytes[PNUM]);
    p.payLoadLength = byteToInt(bytes[LEN]);
    string body;
    for (auto i = DATA; i < bytes.size()-2; i++) {
        body.push_back(bytes[i]);
    }
    p.body = body;
    p.hexCkSum = extractString(bytes,bytes.size()-2, 2);
    return p;
}

void printPacket(const Packet& p) {
    cout<<"Calculated Checksum:   "<<p.cksum<<", Hex Challenge:  "<<p.hexCkSum<<", Checksums match? "<<((p.cksum == stoul(p.hexCkSum, nullptr, 16)) ? "true":"false")<<endl;
    cout<<"        To ID: "<<p.toId<<endl;
    cout<<"      From ID: "<<p.fromId<<endl;
    cout<<"   Link Layer: "<<p.linkLayer<<endl;
    cout<<    "Origin ID: "<<p.originId<<endl;
    cout<<"      Dest ID: "<<p.destId<<endl;
    cout<<"  Packet Type: "<<p.packetType<<endl;
    cout<<" Sequence Num: "<<p.sequenceNumber<<endl;
    cout<<"Payload length: "<<p.payLoadLength<<endl;
    cout<<"Payload Data: "<<p.body<<endl;
}

#endif