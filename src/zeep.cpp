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

void writeToFile(const string &path, const string &content) {
    ofstream ofs;
    ofs.open(path);
    ofs.write(content.c_str(), content.size());
    ofs.close();
}

int main(int argsCount, char **args) {
    string content = readFromFile(args[2]);
    printf("%s", content.c_str());
    writeToFile(args[3], content);
    return 0;
}