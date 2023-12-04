#include "Functions.hpp"

int Functions::countItems(Node *node, string dir) {
    node = findDir(node, dir);
    return 0;
}

int Functions::memorySize(Node *node, string dir) {
    return 0;
}

void Functions::pruneEmpty(Node *node) {
}

string Functions::findPath(Node *node, string dir) {
    return "";
}

void Functions::displayString(Node *node, string dir) {
}

Node *Functions::findDir(Node *node, string dir) {
    if (node == nullptr) {
        return nullptr;
    }

    if (node->name == dir) {
        return node;
    }

    if (!dynamic_cast<Dir *>(node)) {
        return nullptr;
    }

    Dir *d = dynamic_cast<Dir *>(node);
    for (int i = 0; i < d->children.size(); i++) {
        node = findDir(d->children[i], dir);
        if(node != nullptr){
            return node;
        }
    }

    return nullptr;
}