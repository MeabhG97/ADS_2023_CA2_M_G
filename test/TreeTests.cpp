#include <gtest/gtest.h>

#include "../src/Node.hpp"
#include "../src/Dir.hpp"
#include "../src/File.hpp"

TEST(TreeTests, ConstructorTest){
    Node* dir = new Dir("dir");
    EXPECT_EQ(dir->name, "dir");
    EXPECT_TRUE(dynamic_cast<Dir*>(dir));

    Node* file = new File("file", 10, "type");
    EXPECT_EQ(file->name, "file");
    EXPECT_TRUE(dynamic_cast<File*>(file));

    Dir* d = dynamic_cast<Dir*>(dir);

    EXPECT_EQ(d->children.size(), 0);
    d->children.push_back(file);
    EXPECT_EQ(d->children.size(), 1);

    File* f = dynamic_cast<File*>(file);
    EXPECT_EQ(f->size, 10);
    EXPECT_EQ(f->type, "type");
}