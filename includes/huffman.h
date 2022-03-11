#pragma once
#include "compressor.h"
#include "util.h"
#include <map>
#include <vector>

bool cmp(pair<char, int>& a, pair<char, int>& b);

class Huffman : public Compressor {
protected:
    map<char, int> charCount;
    vector<pair<char, int>> sortResult;
    map<char, string> outputCode;
    map<string , char> outputCode_invert;
    vector<pair<char, int>> sort(map<char, int>& M);

public:
    string compress(string& src) override;

    string decompress(string& src) override;
};
