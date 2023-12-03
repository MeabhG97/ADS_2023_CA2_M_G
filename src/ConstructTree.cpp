#include "ConstructTree.hpp"

Node *ConstructTree::constructTree(vector<string> file) {
    Node *root = nullptr;
    stack<Node *> nodeStack;

    for (int i = 0; i < file.size(); i++) {
        if (file[i] == "<dir>") {
            addDirNode(parseLine(file[i + 1]), nodeStack);
            i++;
            continue;
        }

        if (file[i] == "<file>") {
            addFileNode(parseLine(file[i + 1]), parseLine(file[i + 2]), parseLine(file[i + 3]), nodeStack);
            i += 3;
            continue;
        }

        if (file[i] == "</dir>") {
            root = completeDirNode(nodeStack);
            continue;
        }
    }

    return root;
}

void ConstructTree::addDirNode(string name, stack<Node *> &nodeStack) {
    Node *node = new Dir(name);

    if (nodeStack.empty()) {
        nodeStack.push(node);
        return;
    }

    Dir *parent = dynamic_cast<Dir *>(nodeStack.top());
    parent->children.push_back(node);
    nodeStack.push(node);
}

void ConstructTree::addFileNode(string name, string size, string type, stack<Node *> &nodeStack) {
    int sp = size.find_first_of(' ');
    size = size.substr(0, sp);
    Node *node = new File(name, stoi(size), type);

    if (nodeStack.empty()) {
        return;
    }

    if (!dynamic_cast<Dir *>(nodeStack.top())) {
        return;
    }

    Dir *parent = dynamic_cast<Dir *>(nodeStack.top());
    parent->children.push_back(node);
}

Node *ConstructTree::completeDirNode(stack<Node*> &nodeStack) {
    Node *node = nullptr;

    if (nodeStack.size() == 1) {
        node = nodeStack.top();
    }

    nodeStack.pop();

    return node;
}

string ConstructTree::parseLine(string line) {
    int start = line.find_first_of('>') + 1;
    int end = line.find_last_of('<') - 1;
    int range = end - start + 1;

    return line.substr(start, range);
}
