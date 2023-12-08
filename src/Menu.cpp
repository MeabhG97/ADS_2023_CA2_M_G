#include "Menu.hpp"

Node *Menu::root = nullptr;
string Menu::input = "";

void Menu::displayMenu() {
    cout << "\n\n"
         << "1. Number of items in a folder\n"
         << "2. Memory used by a folder\n"
         << "3. Remove empty folders\n"
         << "4. Print path of folder or file\n"
         << "5. Display contents of a folder\n"
         << "Enter number of chosen option"
         << endl;
}

void Menu::selectOption(string &opt) {
    try {
        int o = stoi(opt);
        switch (o) {
        case 1: {
            cout << "Folder name: " << endl;
            cin.clear();
            cin >> input;
            int res = Functions::countItems(root, input);
            if (res > -1) {
                cout << "Number of items : " << res << endl;
            } else {
                cout << "Invalid folder name" << endl;
            }
            break;
        }
        case 2: {
            cout << "Folder name: " << endl;
            cin.clear();
            cin >> input;
            int res = Functions::memorySize(root, input);
            if (res > -1) {
                cout << "Memory size : " << res << "b" << endl;
            } else {
                cout << "Invalid folder name" << endl;
            }
            break;
        }
        case 3: {
            Functions::pruneEmpty(root);
            cout << "Pruned empty folders" << endl;
            break;
        }
        case 4: {
            cout << "Folder or file name: " << endl;
            cin.clear();
            cin >> input;
            string res = Functions::findPath(root, input);
            if (res.length() > 0) {
                cout << "Path : " << res << endl;
            } else {
                cout << "Item not found" << endl;
            }
            break;
        }
        case 5: {
            cout << "Folder name: " << endl;
            cin.clear();
            cin >> input;
            string res = Functions::printDir(root, input);
            if (res.length() > 0) {
                cout << res << endl;
            } else {
                cout << "Item not found" << endl;
            }
            break;
        }
        default: {
            cout << "Not an option" << endl;
            break;
        }
        }
    } catch (invalid_argument &e) {
        cout << "Invalid option" << endl;
    } catch (out_of_range &e) {
        cout << "Invalid option" << endl;
    }
}