#ifndef util_hpp
#define util_hpp
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

typedef unsigned char Byte;

int byteToInt(Byte b) {
    return (unsigned int) b;
}

string intToHex(int number) {
    stringstream ss;
    ss << hex << number;
    return ss.str();
}

string byteToHex(Byte b) {
    return intToHex(byteToInt(b));
}

static int calculateChecksum(vector<Byte> body, int slen) {
    int c1 = 0, c0 = 0, i = 0;
    do {
        c0 = (c0 + byteToInt(body[i++])) % 255;
        c1 = (c0 + c1) % 255;
    } while (--slen > 0);
    return (c1 * 256 + c0);    // c1 is high order byte, c0 is low order byte
}

string extractString(vector<Byte>& bytes, int offset, int len) {
    string str;
    for (int i = offset, j = 0; j < len; j++) {
        str += byteToHex(bytes[offset+j]);
    }
    return str;
}

vector<Byte> hexStringToByteArray(string s) {
    int len = s.length();
    vector<Byte> byteArray;
    for (int i = 0, bn = 0; i < len; i += 2, bn++) {
        string bs = s.substr(i, 2);
        unsigned char byte = (unsigned char)stoi(bs, 0, 16);
        cout<<bn<<": "<<bs<<" -> c: '"<<byte<<"', i:"<<byteToInt(byte)<<endl;
        byteArray.push_back(byte);
    }
    return byteArray;
}

#endif