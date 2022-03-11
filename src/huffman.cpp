#include "huffman.h"
#include <iostream>
#include <algorithm>

string operator*(string a, unsigned int b) {
    string output = "";
    while (b--) {
        output += a;
    }
    return output;
}

bool cmp(pair<char, int> &a, pair<char, int> &b) {
    return a.second < b.second;
}

vector<pair<char, int>> Huffman::sort(map<char, int> &M) {
    vector<pair<char, int>> A;

    for (auto &it: M) {
        A.push_back(it);
    }

    std::sort(A.begin(), A.end(), cmp);

    return A;
}

string Huffman::compress(string &src) {
    int srcCount = src.size();
    map<char, int>::iterator iter;
    for (auto &c : src) {
        iter = charCount.find(c);
        if (iter == charCount.end()) {
            charCount.insert(pair<char, int>(c, 1));
        } else {
            iter->second++;
        }
    }
    sortResult = this->sort(charCount);
    for (auto &it: sortResult) {
        cout << it.first << ' '
             << it.second << endl;
    }
    cout << "---------------------------------" << endl;
    for (auto &it: sortResult) {
        int index = &it - &sortResult[0];
        string code = "0";
        if (index == 0) {
            outputCode.insert(pair<char, string>(it.first, code * (sortResult.size() - 1)));
        } else {
            outputCode.insert(pair<char, string>(it.first, (code * (sortResult.size() - index - 1)) + "1"));
        }
    }
    for (auto &it: outputCode) {
        outputCode_invert.insert(pair<string, char>(it.second, it.first));
        string output = it.second + " ";
        output.push_back(it.first);

        cout << output << endl;
    }
    cout << "---------------------------------" << endl;
    string dst = "";
    for (auto &c: src) {
        //cout << c << " " << outputCode.find(c)->second << endl;
        dst += outputCode.find(c)->second;
    }
    cout << dst << endl;
    cout << "---------------------------------" << endl;
    return dst;
}

string Huffman::decompress(string &src) {
    string code = "";
    string dst = "";
    for (auto &c : src) {
        if (c == '1') {
            code += "1";
            //cout << code << endl;
            dst.push_back(outputCode_invert.find(code)->second);
            code = "";
        }
        else if(code.size() == (outputCode.size() - 2)) {
            code += "0";
            //cout << code << endl;
            dst.push_back(outputCode_invert.find(code)->second);
            code = "";
        }
        else {
            code += "0";
        }
    }
    return dst;
}
