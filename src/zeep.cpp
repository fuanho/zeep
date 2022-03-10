#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

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
    printf("%s", content.c_str());
    return 0;
}