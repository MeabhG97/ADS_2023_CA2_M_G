#pragma once

#include <iostream>
#include <queue>
#include <string>

#include "Dir.hpp"
#include "File.hpp"
#include "Node.hpp"

using namespace std;

class Functions {
public:
    static int countItems(Node *, string);
    static int memorySize(Node *, string);
    static Node *pruneEmpty(Node *);
    static string findPath(Node *, string);
    static void displayString(Node *, string);
    static Node *findDir(Node *, string);

private:
    static void pruneEmpty(Node *, Dir *);
    static string findPath(Node *, string, string);
    static void printNode(Node *, string&);
};