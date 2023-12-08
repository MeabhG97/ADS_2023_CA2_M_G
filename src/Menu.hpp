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

private:
    static string input;
};