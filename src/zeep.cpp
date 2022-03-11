#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <huffman.h>
#include <compressor.h>

using namespace std;

string readFromFile(const string &path) {
    ifstream ifs;
    ifs.open(path);
    stringstream str;
    char c;
    while (ifs.get(c)) {
        str << c;
    }
    ifs.close();
    return str.str();
}

void writeToFile(const string &path, const string &content) {
    ofstream ofs;
    ofs.open(path);
    ofs.write(content.c_str(), content.size());
    ofs.close();
}

int main(int argsCount, char **args) {
    string content = readFromFile(args[1]);
    Huffman *hf = new Huffman();
    Compressor *cmp = hf;
    string compressedData = cmp->compress(content);
    string decompressedData = cmp->decompress(compressedData);
    printf("Before compress: %s\n", content.c_str());
    printf("After decompress: %s\n", decompressedData.c_str());
    writeToFile(args[2], decompressedData);
    delete cmp;
    return 0;
}