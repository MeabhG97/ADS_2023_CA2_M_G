#include <gtest/gtest.h>

#include "../src/ConstructTree.hpp"
#include "../src/Dir.hpp"

TEST(ConstructTreeTests, AddingDirNode) {
    vector<string> vs;
    vs.push_back("<dir>");
    vs.push_back("<name>dir</name>");
    vs.push_back("</dir>");
    Node *root = ConstructTree::constructTree(vs);

    ASSERT_NE(root, nullptr);
    EXPECT_EQ(root->name, "dir");
    EXPECT_TRUE(dynamic_cast<Dir *>(root));

    Dir *d = dynamic_cast<Dir *>(root);
    EXPECT_EQ(d->children.size(), 0);

    vs.clear();
    vs.push_back("<dir>");
    vs.push_back("<name>root</name>");
    vs.push_back("<dir>");
    vs.push_back("<name>child</name>");
    vs.push_back("</dir>");
    vs.push_back("</dir>");
    root = ConstructTree::constructTree(vs);

    ASSERT_NE(root, nullptr);
    EXPECT_EQ(root->name, "root");
    EXPECT_TRUE(dynamic_cast<Dir *>(root));

    d = dynamic_cast<Dir *>(root);
    EXPECT_EQ(d->children.size(), 1);
    EXPECT_EQ(d->children[0]->name, "child");

    vs.clear();
    vs.push_back("<dir>");
    vs.push_back("<name>root</name>");
    vs.push_back("<dir>");
    vs.push_back("<name>child0</name>");
    vs.push_back("<dir>");
    vs.push_back("<name>child</name>");
    vs.push_back("</dir>");
    vs.push_back("</dir>");
    vs.push_back("<dir>");
    vs.push_back("<name>child1</name>");
    vs.push_back("</dir>");
    vs.push_back("</dir>");
    root = ConstructTree::constructTree(vs);

    ASSERT_NE(root, nullptr);
    EXPECT_EQ(root->name, "root");
    EXPECT_TRUE(dynamic_cast<Dir *>(root));

    d = dynamic_cast<Dir *>(root);
    EXPECT_EQ(d->children.size(), 2);
    EXPECT_EQ(d->children[0]->name, "child0");
    EXPECT_EQ(d->children[1]->name, "child1");

    EXPECT_TRUE(dynamic_cast<Dir *>(d->children[0]));
    d = dynamic_cast<Dir *>(d->children[0]);

    EXPECT_EQ(d->children.size(), 1);

    vs.clear();
    root = ConstructTree::constructTree(vs);
    EXPECT_EQ(root, nullptr);
}

TEST(ConstructTreeTests, AddingFileNode) {
    vector<string> vs;
    vs.push_back("<dir>");
    vs.push_back("<name>dir</name>");
    vs.push_back("<file>");
    vs.push_back("<name>file</name>");
    vs.push_back("<length>100 b</length>");
    vs.push_back("<type>config</type");
    vs.push_back("</dir>");
    Node *root = ConstructTree::constructTree(vs);

    ASSERT_NE(root, nullptr);
    EXPECT_EQ(root->name, "dir");
    EXPECT_TRUE(dynamic_cast<Dir *>(root));

    Dir* d = dynamic_cast<Dir*>(root);
    EXPECT_EQ(d->children.size(), 1);
    EXPECT_TRUE(dynamic_cast<File*>(d->children[0]));

    File* f = dynamic_cast<File*>(d->children[0]);
    EXPECT_EQ(f->name, "file");
    EXPECT_EQ(f->size, 100);
    EXPECT_EQ(f->type, "config");
}
