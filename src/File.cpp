#include "File.hpp"

File::File(string name, int size, string type) : Node(name) {
    this->size = size;
    this->type = type;
}

int File::count() {
    return 1;
}

int File::getSize() {
    return this->size;
}