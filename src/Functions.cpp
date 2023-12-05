#include "Functions.hpp"

#include <iostream>

int Functions::countItems(Node *node, string dir) {
    node = findDir(node, dir);

    if (node == nullptr) {
        return -1;
    }

    // Subtract one as the count memeber function will
    // include the starting node rather than just its contents.
    return node->count() - 1;
}

int Functions::memorySize(Node *node, string dir) {
    node = findDir(node, dir);

    if (node == nullptr) {
        return -1;
    }

    queue<Node *> q;
    int totalSize = 0;
    q.push(node);

    while (q.size() > 0) {
        node = q.front();
        q.pop();

        totalSize += node->getSize();

        if (dynamic_cast<Dir *>(node)) {
            Dir *d = dynamic_cast<Dir *>(node);
            for (int i = 0; i < d->children.size(); i++) {
                q.push(d->children[i]);
            }
        }
    }

    return totalSize;
}

Node* Functions::pruneEmpty(Node *node) {
    if (node == nullptr) {
        return nullptr;
    }

    if (dynamic_cast<File *>(node)) {
        return nullptr;
    }

    Dir *d = dynamic_cast<Dir *>(node);

    for (int i = 0; i < d->children.size(); i++) {
        pruneEmpty(d->children[i], d);
    }

    //Root is empty
    if (d->children.size() == 0) {
        delete(d);
        return nullptr;
    }

    return node;
}

void Functions::pruneEmpty(Node *node, Dir *parent) {
    if (node == nullptr) {
        return;
    }

    if (dynamic_cast<File *>(node)) {
        return;
    }

    Dir *d = dynamic_cast<Dir *>(node);

    for (int i = 0; i < d->children.size(); i++) {
        pruneEmpty(d->children[i], d);
    }
    
    if (d->children.size() == 0) {
        d->prune(node, parent);
    }

    return;
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
        if (node != nullptr) {
            return node;
        }
    }

    return nullptr;
}