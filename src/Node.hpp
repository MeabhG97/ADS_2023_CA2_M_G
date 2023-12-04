#pragma once

#include <string>
#include <queue>

using namespace std;

class Node {
public:
    string name;
    Node(string);
    virtual int count() = 0;
    virtual int getSize() = 0;

    virtual ~Node() = 0;
};