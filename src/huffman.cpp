#include "huffman.h"

Huffman::Huffman() {
    tree = new Node();
}

Huffman::~Huffman() {
    releaseTree(tree);
}

Node *Huffman::releaseTree(Node *root) {
    if (!root) return nullptr;
    if (!root->left && !root->right) return root;
    delete releaseTree(root->left);
    delete releaseTree(root->right);
    delete root;
}

string Huffman::compress(string &src) {
    // TODO: Implement Huffman Coding compress.
    return src;
}

string Huffman::decompress(string &src) {
    // TODO: Implement Huffman Coding decompress.
    return src;
}

void Huffman::readTree(basic_iostream<char> stream) {
    // TODO: Load Huffman tree from a stream.
}

void Huffman::writeTree(basic_iostream<char> stream) {
    // TODO: Write Huffman tree to a stream.
}
