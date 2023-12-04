#pragma once

#include <queue>
#include <string>

#include "Node.hpp"
#include "Dir.hpp"

using namespace std;

class Functions {
public:
    static int countItems(Node*, string);
    static int memorySize(Node*, string);
    static void pruneEmpty(Node*);
    static string findPath(Node*, string);
    static void displayString(Node*, string);
    static Node* findDir(Node*, string);
};