#pragma once

#include <string>

using namespace std;

class Node {
public:
    string name;
    Node(string);

    virtual ~Node() = 0;
};