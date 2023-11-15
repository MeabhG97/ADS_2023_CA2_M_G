#pragma once

#include <vector>

#include "Node.hpp"

using namespace std;

class Dir : public Node {
public:
    vector<Node*> children;
    Dir(string);
};