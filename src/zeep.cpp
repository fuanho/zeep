
#include <string>
#include <huffman.h>
#include <compressor.h>
#include <util.h>

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

int main(int argsCount, char **args) {
    string content = readFromFile(args[2]);
    Compressor *cmp = new Huffman();
    string tmp = cmp->compress(content);
    string dst = cmp->decompress(tmp);
    printf("input :\n%s\n", content.c_str());
    printf("output:\n%s\n", dst.c_str());
    writeToFile(args[3], content);
    delete cmp;
    return 0;
}