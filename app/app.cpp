#include "../src/ConstructTree.hpp"
#include "../src/FileReader.hpp"
#include "../src/Functions.hpp"
#include "../src/Menu.hpp"
#include "../src/Node.hpp"
#include "../src/XMLValidator.hpp"

int main() {
    string file = "";
    string opt;

    while(file == ""){
        Menu::displayFiles();
        cin.clear();
        cin >> opt;
        file = Menu::selectFile(opt);
        opt.clear();
    }

    XMLValidator v;
    FileReader fr;
    vector<string> fileContents = fr.readFile(file);

    bool valid = v.validateXML(fileContents);
    if (!valid) {
        cout << "Invalid XML" << endl;
        return 1;
    } else {
        cout << "Valid XML" << endl;
    }

    Menu::root = ConstructTree::constructTree(fileContents);;

    string dirTree = Functions::printDir(Menu::root, Menu::root->name);
    cout << dirTree << endl;

    while(!Menu::quit){
        Menu::displayMenu();
        cin.clear();
        cin >> opt;
        Menu::selectOption(opt);
        opt.clear();
    }
}
