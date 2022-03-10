#pragma once
#include "compressor.h"

class Huffman : public Compressor{
public:
    string compress(string &src) override;

    string decompress(string &src) override;
};