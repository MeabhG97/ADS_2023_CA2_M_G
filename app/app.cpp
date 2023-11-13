#include "../src/XMLValidator.hpp"
#include "../src/FileReader.hpp"

int main(){
    const string file = "../../files/vs_sample_simple.xml";
    XMLValidator v;
    FileReader fr;
    vector<string> fileContents = fr.readFile(file);
    bool valid = v.validateXML(fileContents);
    cout << valid << endl;
}

