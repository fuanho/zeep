#pragma once
#include "compressor.h"
#include <map>
#include <vector>

class Huffman:public Compressor
{
private:
    map<char, int> charCount;
    map<int, vector<char>> probability;
    void sort(map<char, int>& M);
public:
    Huffman();
    ~Huffman();
    string compress(string &src) override;
    string decompress(string &src) override;
};
