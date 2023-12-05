#include "Dir.hpp"

Dir::Dir(string name) : Node(name) {
}

int Dir::count() {
    int total = 1;

    for (int i = 0; i < children.size(); i++) {
        total += children[i]->count();
    }

    return total;
}

int Dir::getSize() {
    return 0;
}

void Dir::prune(Node* node, Dir *parent) {
    auto n = find(parent->children.begin(), parent->children.end(), node);
    parent->children.erase(n);
}