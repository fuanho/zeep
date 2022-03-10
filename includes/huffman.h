#pragma once
#include "compressor.h"
#include <map>

bool cmp(pair<char, int>& a, pair<char, int>& b);

class Huffman : public Compressor {
protected:
    map<char, int> charCount;
    void sort(map<char, int>& M);

public:
    string compress(string& src) override;

    string decompress(string& src) override;
};
