#include <gtest/gtest.h>

#include "../src/ConstructTree.hpp"
#include "../src/Dir.hpp"

TEST(ConstructTreeTests, AddingDirNode) {
    ConstructTree ct;
    vector<string> vs;
    vs.push_back("<dir>");
    vs.push_back("dir");
    vs.push_back("</dir>");
    Node* root = ct.constructTree(vs);

    ASSERT_NE(root, nullptr);
    EXPECT_EQ(root->name, "dir");
    EXPECT_TRUE(dynamic_cast<Dir*>(root));

    Dir* d = dynamic_cast<Dir*>(root);
    EXPECT_EQ(d->children.size(), 0);

    vs.clear();
    vs.push_back("<dir>");
    vs.push_back("root");
    vs.push_back("<dir>");
    vs.push_back("child");
    vs.push_back("</dir>");
    vs.push_back("</dir>");
    root = ct.constructTree(vs);

    ASSERT_NE(root, nullptr);
    EXPECT_EQ(root->name, "root");
    EXPECT_TRUE(dynamic_cast<Dir*>(root));

    d = dynamic_cast<Dir*>(root);
    EXPECT_EQ(d->children.size(), 1);
    EXPECT_EQ(d->children[0]->name, "child");

    vs.clear();
    vs.push_back("<dir>");
    vs.push_back("root");
    vs.push_back("<dir>");
    vs.push_back("child0");
    vs.push_back("<dir>");
    vs.push_back("child");
    vs.push_back("</dir>");
    vs.push_back("</dir>");
    vs.push_back("<dir>");
    vs.push_back("child1");
    vs.push_back("</dir>");
    vs.push_back("</dir>");
    root = ct.constructTree(vs);

    ASSERT_NE(root, nullptr);
    EXPECT_EQ(root->name, "root");
    EXPECT_TRUE(dynamic_cast<Dir*>(root));

    d = dynamic_cast<Dir*>(root);
    EXPECT_EQ(d->children.size(), 2);
    EXPECT_EQ(d->children[0]->name, "child0");
    EXPECT_EQ(d->children[1]->name, "child1");

    EXPECT_TRUE(dynamic_cast<Dir*>(d->children[0]));
    d = dynamic_cast<Dir*>(d->children[0]);

    EXPECT_EQ(d->children.size(), 1);
}
