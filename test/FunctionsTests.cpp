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

TEST(FunctionsTests, countItemsTests){
    vector<string> vs;
    vs.push_back("<dir>");
    vs.push_back("<name>dir</name>");
    vs.push_back("</dir>");
    Node* root = ConstructTree::constructTree(vs);

    int items = Functions::countItems(root, "dir");
    EXPECT_EQ(items, 0);

    vs.clear();
    vs.push_back("<dir>");
    vs.push_back("<name>root</name>");
    vs.push_back("<dir>");
    vs.push_back("<name>child</name>");
    vs.push_back("</dir>");
    vs.push_back("</dir>");
    root = ConstructTree::constructTree(vs);

    items = Functions::countItems(root, "root");
    EXPECT_EQ(items, 1);

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

    items = Functions::countItems(root, "root");
    EXPECT_EQ(items, 3);

    items = Functions::countItems(root, "dir");
    EXPECT_EQ(items, -1);
}

TEST(FunctionsTests, memorySizeTests){
    vector<string> vs;
    vs.push_back("<dir>");
    vs.push_back("<name>dir</name>");
    vs.push_back("</dir>");
    Node* root = ConstructTree::constructTree(vs);

    int size = Functions::memorySize(root, "dir");
    EXPECT_EQ(size, 0);

    vs.clear();
    vs.push_back("<dir>");
    vs.push_back("<name>dir</name>");
    vs.push_back("<file>");
    vs.push_back("<name>file1</name>");
    vs.push_back("<length>100 b</length>");
    vs.push_back("<type>type</type>");
    vs.push_back("</file>");
    vs.push_back("</dir>");
    root = ConstructTree::constructTree(vs);

    size = Functions::memorySize(root, "dir");
    EXPECT_EQ(size, 100);

    vs.clear();
    vs.push_back("<dir>");
    vs.push_back("<name>dir</name>");
    vs.push_back("<file>");
    vs.push_back("<name>file1</name>");
    vs.push_back("<length>100 b</length>");
    vs.push_back("<type>type</type>");
    vs.push_back("</file>");
    vs.push_back("<file>");
    vs.push_back("<name>file2</name>");
    vs.push_back("<length>200 b</length>");
    vs.push_back("<type>type</type>");
    vs.push_back("</file>");
    vs.push_back("<file>");
    vs.push_back("<name>file3</name>");
    vs.push_back("<length>300 b</length>");
    vs.push_back("<type>type</type>");
    vs.push_back("</file>");
    vs.push_back("</dir>");
    root = ConstructTree::constructTree(vs);

    size = Functions::memorySize(root, "dir");
    EXPECT_EQ(size, 600);

    size = Functions::memorySize(root, "no dir");
    EXPECT_EQ(size, -1);
}