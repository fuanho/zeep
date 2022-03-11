#include "huffman.h"

#include <algorithm>
#include <deque>
#include <map>

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
    this->tree = buildHuffmanTree(src);
    // TODO: Encoding string from src to dst
    return src;
}

Node *Huffman::buildHuffmanTree(string &src) {
    // Calculate show times of each character
    map<char, Node *> nodes;
    for (char c : src) {
        if (nodes.find(c) == nodes.end()) {
            Node *n = new Node();
            n->value = c;
            n->weight = 1;
            nodes.insert(pair<char, Node *>(c, n));
            continue;
        }
        ++nodes.at(c)->weight;
    }
    // Transform the map to a list
    deque<Node *> sortedNodes;
    for (pair<char, Node *> p : nodes) {
        sortedNodes.push_back(p.second);
    }
    // Sort the list
    sort(sortedNodes.begin(), sortedNodes.end(), nodeComparator);
    // Build Huffman tree
    while (sortedNodes.size() > 1) {
        // Pop first two nodes
        Node *first = sortedNodes.front();
        sortedNodes.pop_front();
        Node *second = sortedNodes.front();
        sortedNodes.pop_front();
        // Combine the nodes
        Node *combined = new Node();
        combined->left = first;
        combined->right = second;
        combined->weight = first->weight + second->weight;
        sortedNodes.push_front(combined);
        // Sort the list
        sort(sortedNodes.begin(), sortedNodes.end(), nodeComparator);
    }
    // The only one node in the list is the tree root
    return sortedNodes.front();
}

bool Huffman::nodeComparator(Node *a, Node *b) {
    // Sort by ASC
    return a->weight < b->weight;
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
