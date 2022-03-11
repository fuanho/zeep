#include "util.h"

void writeToFile(const string &path, const string &content) {
    ofstream ofs;
    ofs.open(path);
    ofs.write(content.c_str(), content.size());
    ofs.close();
}

