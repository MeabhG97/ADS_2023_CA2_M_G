#pragma once

#include <iostream>
#include <string>

#include "Functions.hpp"

using namespace std;

class Menu {
public:
    static Node *root;
    static void displayMenu();
    static void selectOption(string &);
    static bool quit;
    static void displayFiles();
    static string selectFile(string &);

private:
    static string input;
};