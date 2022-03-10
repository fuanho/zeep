#include "huffman.h"
#include <iostream>
#include <vector>
#include <algorithm>

bool cmp(pair<char, int>& a, pair<char, int>& b)
{
    return a.second < b.second;
}

void Huffman::sort(map<char, int>& M)
{
    vector<pair<char, int>> A;

    for (auto& it : M) {
        A.push_back(it);
    }

    cout << "I'm in" << endl;
    std::sort(A.begin(), A.end(), cmp);
    cout << "I'm out" << endl;

    for (auto& it : A) {

        cout << it.first << ' '
            << it.second << endl;
    }
}

string Huffman::compress(string& src) {
    int srcCount = src.size();
    map<char, int>::iterator iter;
    for (size_t i = 0; i < srcCount; i++)
    {
        char c = src.at(i);
        cout << c << endl;
        iter = charCount.find(c);
        if (iter != charCount.end())
        {
            charCount.insert(pair<char, int>(c, 1));
        }
        else
        {
            iter->second++;
        }
    }
    this->sort(charCount);
    return src;
}

string Huffman::decompress(string& src) {
    return src;
}
