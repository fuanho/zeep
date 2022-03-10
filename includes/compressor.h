#pragma once
#include <string>

using namespace std;

class Compressor {
public:
    virtual string compress(string &src) = 0;

    virtual string decompress(string &src) = 0;
};
