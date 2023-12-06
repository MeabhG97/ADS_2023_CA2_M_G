#include "../src/ConstructTree.hpp"
#include "../src/FileReader.hpp"
#include "../src/Functions.hpp"
#include "../src/Node.hpp"
#include "../src/XMLValidator.hpp"

int main() {
    const string file = "../../files/vs_sample_simple.xml";
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

    Node *root = ConstructTree::constructTree(fileContents);
    Functions::displayString(root, "ADS_Single_LinkedList_Exercises");
}
