#include <gtest/gtest.h>

#include "../src/FileReader.hpp"

TEST(FileReaderTests, readFileTests){
    FileReader fr;
    vector<string> vs;
    vs = fr.readFile("not found");
    EXPECT_EQ(vs.size(), 0);

    vs = fr.readFile("../../files/vs_sample_simple.xml");
    EXPECT_EQ(vs.size(), 48);

    vs = fr.readFile("../../files/vs_sample.xml");
    EXPECT_EQ(vs.size(), 722);

    vs = fr.readFile("../../files/unity_sample.xml");
    EXPECT_EQ(vs.size(), 157010);
}

TEST(FileReaderTests, trimTests){
    FileReader fr;
    string s;

    s = fr.trim(" <str>");
    EXPECT_EQ(s, "<str>");

    s = fr.trim("<str> ");
    EXPECT_EQ(s, "<str>");

    s = fr.trim(" <str> ");
    EXPECT_EQ(s, "<str>");

    s = fr.trim("\t<str>");
    EXPECT_EQ(s, "<str>");

    s = fr.trim("<str>\t");
    EXPECT_EQ(s, "<str>");

    s = fr.trim("\t<str>\t");
    EXPECT_EQ(s, "<str>");

    s = fr.trim("\n<str>");
    EXPECT_EQ(s, "<str>");

    s = fr.trim("<str>\n");
    EXPECT_EQ(s, "<str>");

    s = fr.trim("\n<str>\n");
    EXPECT_EQ(s, "<str>");

    s = fr.trim("\n\t <str> \t\n");
    EXPECT_EQ(s, "<str>");
}