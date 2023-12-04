#include "Dir.hpp"

Dir::Dir(string name) : Node(name) {
}

int Dir::count() {
    int total = 1;

    for(int i = 0; i < children.size(); i++){
        total += children[i]->count();
    }

    return total;
}

int Dir::getSize() {
    int total = 0;

    for(int i = 0; i < children.size(); i++){
        total += children[i]->getSize();
    }

    return total;
}