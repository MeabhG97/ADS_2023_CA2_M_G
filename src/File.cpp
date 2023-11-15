#include "File.hpp"

File::File(string name, int size, string type) : Node(name) {
    this->size = size;
    this->type = type;  
}