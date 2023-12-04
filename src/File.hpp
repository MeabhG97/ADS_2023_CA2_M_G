#pragma once

#include <string>

#include "Node.hpp"

using namespace std;

class File : public Node {
public:
    int size;
    string type;
    File(string, int, string);
    int count();
    int getSize();
};