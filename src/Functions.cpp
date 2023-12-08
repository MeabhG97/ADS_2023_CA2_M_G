#include "Functions.hpp"

// Returns number of files or -1 if not found.
int Functions::countItems(Node *node, string name) {
    node = findDir(node, name);

    if (node == nullptr) {
        return -1;
    }

    // Subtract one as the count memeber function will
    // include the starting node rather than just its contents.
    return node->count() - 1;
}

// Returns memory size of -1 if not found
int Functions::memorySize(Node *node, string name) {
    node = findDir(node, name);

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

// Removes empty directories
Node *Functions::pruneEmpty(Node *node) {
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

    // Root is empty
    if (d->children.size() == 0) {
        delete (d);
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

// returns empty string if item not found
string Functions::findPath(Node *node, string name) {
    string path = "/";

    if (node->name == name) {
        return path += node->name;
    }

    if (dynamic_cast<File *>(node)) {
        return "";
    }

    Dir *d = dynamic_cast<Dir *>(node);

    path += node->name + "/";

    for (int i = 0; i < d->children.size(); i++) {
        string s = findPath(d->children[i], name, path);
        if (s != "") {
            return s;
        }
    }

    path = path.substr(0, node->name.length() + 1);

    return "";
}

string Functions::findPath(Node *node, string name, string path) {
    if (node->name == name) {
        return path += node->name;
    }

    if (dynamic_cast<File *>(node)) {
        return "";
    }

    Dir *d = dynamic_cast<Dir *>(node);

    path += node->name + "/";

    for (int i = 0; i < d->children.size(); i++) {
        string s = findPath(d->children[i], name, path);
        if (s != "") {
            return s;
        }
    }

    path = path.substr(0, path.length() - (node->name.length() + 1));

    return "";
}

// Doesn't print if not found
string Functions::printDir(Node *node, string name) {
    node = findDir(node, name);

    if (node == nullptr) {
        return "";
    }

    string indent = "";
    string tree = "";

    return printTree(node, indent, tree);
}

string Functions::printTree(Node *node, string &indent, string &tree) {
    if (node == nullptr) {
        return tree;
    }

    if (dynamic_cast<Dir *>(node)) {
        Dir *d = dynamic_cast<Dir *>(node);

        tree += indent + "|" + "-" + d->name + "\n";

        indent += " ";

        for (int i = 0; i < d->children.size(); i++) {
            printTree(d->children[i], indent, tree);
        }

        indent.pop_back();
    }

    if (dynamic_cast<File *>(node)) {
        File *f = dynamic_cast<File *>(node);

        tree += indent + "|" + f->name + " #" + to_string(f->size) + "b\n";
    }

    return tree;
}

Node *Functions::findDir(Node *node, string name) {
    if (node == nullptr) {
        return nullptr;
    }

    if (node->name == name) {
        return node;
    }

    if (!dynamic_cast<Dir *>(node)) {
        return nullptr;
    }

    Dir *d = dynamic_cast<Dir *>(node);
    for (int i = 0; i < d->children.size(); i++) {
        node = findDir(d->children[i], name);
        if (node != nullptr) {
            return node;
        }
    }

    return nullptr;
}