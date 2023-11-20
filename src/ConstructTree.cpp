#include "ConstructTree.hpp"

Node *ConstructTree::constructTree(vector<string> file) {
    Node* root = nullptr;

    for (int i = 0; i < file.size(); i++) {
        if(file[i] == "<dir>"){
            addDirNode(parseLine(file[i + 1]));
            i++;
            continue;   
        }

        if(file[i] == "<file>"){
            continue;
        }

        if(file[i] == "</dir>"){
            root = completeDirNode();
            continue;
        }
    }

    return root;
}

void ConstructTree::addDirNode(string name) {
    Node* node = new Dir(name);

    if(nodeStack.empty()){
        nodeStack.push(node);
        return;
    }

    Dir* parent = dynamic_cast<Dir*>(nodeStack.top());
    parent->children.push_back(node);
    nodeStack.push(node);
}

void ConstructTree::addFileNode(string name, int size, string type) {

}

Node* ConstructTree::completeDirNode() {
    Node* node = nullptr;

    if(nodeStack.size() == 1) {
        node = nodeStack.top();
    }

    nodeStack.pop();

    return node;
}

string ConstructTree::parseLine(string line){
    int start = line.find_first_of('>') + 1;
    int end = line.find_last_of('<') - 1;
    int range = end - start;

    return line.substr(start, range);
}
