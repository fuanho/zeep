#pragma once

#include <iostream>
#include "compressor.h"

class Node {
public:
    string value;
    unsigned int weight = 0;
    Node *left = nullptr;
    Node *right = nullptr;
};

class Huffman : public Compressor {
private:
    Node *tree = nullptr;

    Node *releaseTree(Node *root);

public:

    Huffman();

    ~Huffman();

    string compress(string &src) override;

    string decompress(string &src) override;

    void readTree(basic_iostream<char> stream);

    void writeTree(basic_iostream<char> stream);
};