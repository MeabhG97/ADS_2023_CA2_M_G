#include <gtest/gtest.h>

#include "../src/Functions.hpp"
#include "../src/ConstructTree.hpp"

TEST(FunctionsTests, findDirTests){
    vector<string> vs;
    vs.push_back("<dir>");
    vs.push_back("<name>dir</name>");
    vs.push_back("</dir>");
    Node* root = ConstructTree::constructTree(vs);

    Node* node = Functions::findDir(root, "dir");
    EXPECT_NE(node, nullptr);
    EXPECT_EQ(node, root);
    EXPECT_EQ(node->name, "dir");

    node = Functions::findDir(root, "Not Found");
    EXPECT_EQ(node, nullptr);

    vs.clear();
    vs.push_back("<dir>");
    vs.push_back("<name>root</name>");
    vs.push_back("<dir>");
    vs.push_back("<name>child</name>");
    vs.push_back("</dir>");
    vs.push_back("</dir>");
    root = ConstructTree::constructTree(vs);

    node = Functions::findDir(root, "root");
    EXPECT_NE(node, nullptr);
    EXPECT_EQ(node, root);
    EXPECT_EQ(node->name, "root");

    node = Functions::findDir(root, "child");
    EXPECT_NE(node, nullptr);
    EXPECT_EQ(node->name, "child");

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

    node = Functions::findDir(root, "child");
    EXPECT_NE(node, nullptr);
    EXPECT_EQ(node->name, "child");

    node = Functions::findDir(root, "child1");
    EXPECT_NE(node, nullptr);
    EXPECT_EQ(node->name, "child1");

    node = Functions::findDir(root, "child2");
    EXPECT_EQ(node, nullptr);
}