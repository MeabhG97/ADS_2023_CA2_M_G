#pragma once

#include <algorithm>
#include <vector>

#include "Node.hpp"

using namespace std;

class Dir : public Node {
public:
    vector<Node *> children;
    Dir(string);
    int count();
    int getSize();
    void prune(Node *, Dir *);
};