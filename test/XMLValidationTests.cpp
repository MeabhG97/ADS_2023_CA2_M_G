#include <gtest/gtest.h>

#include "../src/XMLValidator.hpp"

TEST(XMLValidatorTests, RootElement){
    XMLValidator v;
    vector<string> s;
    s.push_back("<dir>");
    s.push_back("</dir>");
    ASSERT_TRUE(v.validateXML(s));

    s.clear();
    s.push_back("<dir>");
    s.push_back("<dir>");
    s.push_back("</dir>");
    s.push_back("</dir>");
    ASSERT_TRUE(v.validateXML(s));

    s.clear();
    s.push_back("<dir>");
    s.push_back("</dir>");
    s.push_back("<dir>");
    s.push_back("</dir>");
    ASSERT_FALSE(v.validateXML(s));

    s.clear();
    s.push_back("");
    ASSERT_FALSE(v.validateXML(s));
}

TEST(XMLValidatorTests, ClosingTag){
    XMLValidator v;
    vector<string> s;
    s.push_back("<dir>");
    s.push_back("</dir>");
    ASSERT_TRUE(v.validateXML(s));

    s.clear();
    s.push_back("<dir>");
    s.push_back("<file>");
    s.push_back("</file>");
    s.push_back("</dir>");
    ASSERT_TRUE(v.validateXML(s));

    s.clear();
    s.push_back("<dir>");
    s.push_back("<dir>");
    s.push_back("</dir>");
    ASSERT_FALSE(v.validateXML(s));

    s.clear();
    s.push_back("<dir>");
    s.push_back("</dir>");
    s.push_back("</dir>");
    ASSERT_FALSE(v.validateXML(s));
}

TEST(XMLValidatorTests, Nesting){
    XMLValidator v;
    vector<string> s;

    s.push_back("<dir>");
    s.push_back("</dir>");
    ASSERT_TRUE(v.validateXML(s));

    s.clear();
    s.push_back("<dir>");
    s.push_back("<file>");
    s.push_back("</file>");
    s.push_back("</dir>");
    ASSERT_TRUE(v.validateXML(s));

    s.clear();
    s.push_back("<dir>");
    s.push_back("<file>");
    s.push_back("</file>");
    s.push_back("<file>");
    s.push_back("</file>");
    s.push_back("</dir>");
    ASSERT_TRUE(v.validateXML(s));

    s.clear();
    s.push_back("<dir>");
    s.push_back("<dir>");
    s.push_back("<file>");
    s.push_back("</file>");
    s.push_back("</dir>");
    s.push_back("</dir>");
    ASSERT_TRUE(v.validateXML(s));

    s.clear();
    s.push_back("<dir>");
    s.push_back("<dir>");
    s.push_back("</dir>");
    s.push_back("<file>");
    s.push_back("</file>");
    s.push_back("</dir>");
    ASSERT_TRUE(v.validateXML(s));

    s.clear();
    s.push_back("<dir>");
    s.push_back("<dir>");
    s.push_back("<file>");
    s.push_back("</dir>");
    s.push_back("</file>");
    s.push_back("</dir>");
    ASSERT_FALSE(v.validateXML(s));
}