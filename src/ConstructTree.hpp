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
    static Node* constructTree(vector<string>);
private:
    static void addDirNode(string, stack<Node*>&);
    static void addFileNode(string, string, string, stack<Node*>&);
    static Node* completeDirNode(stack<Node*>&);
    static string parseLine(string);
};