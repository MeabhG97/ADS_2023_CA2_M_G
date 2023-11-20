#pragma once

#include <stack>
#include <string>
#include <vector>

#include "Node.hpp"
#include "Dir.hpp"
#include "File.hpp"

using namespace std;

class ConstructTree {
public:
    Node* constructTree(vector<string>);
private:
    void addDirNode(string);
    void addFileNode(string, int, string);
    Node* completeDirNode();
    stack<Node*> nodeStack;
    string parseLine(string);
};