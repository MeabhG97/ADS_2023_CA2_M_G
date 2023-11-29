#include "../src/FileReader.hpp"
#include "../src/XMLValidator.hpp"
#include "../src/ConstructTree.hpp"
#include "../src/Node.hpp"

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
    
    ConstructTree ct;
    Node* root = ct.constructTree(fileContents);
}
