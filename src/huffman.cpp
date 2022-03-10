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
    return src;
}

string Huffman::decompress(string &src) {
    return src;
}
