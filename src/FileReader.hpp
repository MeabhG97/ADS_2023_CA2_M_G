#pragma once

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class FileReader {
public:
    vector<string> readFile(string);

private:
    string trim(string);
};