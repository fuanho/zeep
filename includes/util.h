#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

//std::string operator*(std::string a, unsigned int b);
//bool cmp(std::pair<char, int> &a, std::pair<char, int> &b);
//std::string readFromFile(const std::string &path);
void writeToFile(const std::string &path, const std::string &content);
