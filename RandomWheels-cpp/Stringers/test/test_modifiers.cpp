#include "gtest/gtest.h"  
#include <string>  
  
// 假设trim函数已经定义在某个头文件中  
#include "modifiers.h"  // 假设trimTrial函数定义在这个头文件中
  
TEST(TrimTest, TrimBothSides) {  
  std::string s = "   Hello, World!   ";  
  trimTrial(s);
  EXPECT_EQ("Hello, World!", s);  
}  
  
TEST(TrimTest, TrimLeftSide) {  
  std::string s = "   Hello, World!";  
  trimTrial(s);
  EXPECT_EQ("Hello, World!", s);  
}  

TEST(TrimTest, TrimRightSide) {  
  std::string s = "Hello, World!   ";  
  trimTrial(s);
  EXPECT_EQ("Hello, World!", s);  
}  
  
TEST(TrimTest, NoTrim) {  
  std::string s = "Hello, World!";  
  trimTrial(s);
  EXPECT_EQ("Hello, World!", s);  
}  
  
TEST(TrimTest, PreserveInternalSpaces) {  
  std::string s = "Hello,   World!";  
  trimTrial(s);
  EXPECT_EQ("Hello,   World!", s);  
}  
  
TEST(TrimTest, EmptyString) {  
  std::string s = "";  
  trimTrial(s);
  EXPECT_EQ("", s);  
}


TEST(TrimTest, TrimBothSides2) {
  std::string s = "   Hello, World!   ";
  trimIter(s);
  EXPECT_EQ("Hello, World!", s);
}


TEST(TrimTest, TrimLeftSide2) {
  std::string s = "   Hello, World!";
  trimIter(s);
  EXPECT_EQ("Hello, World!", s);
}

TEST(TrimTest, TrimRightSide2) {
  std::string s = "Hello, World!   ";
  trimIter(s);
  EXPECT_EQ("Hello, World!", s);
}

TEST(TrimTest, NoTrim2) {
  std::string s = "Hello, World!";
  trimIter(s);
  EXPECT_EQ("Hello, World!", s);
}

TEST(TrimTest, PreserveInternalSpaces2) {
  std::string s = "Hello,   World!";
  trimIter(s);
  EXPECT_EQ("Hello,   World!", s);
}

TEST(TrimTest, EmptyString2) {
  std::string s = "";
  trimIter(s);
  EXPECT_EQ("", s);
}

// 如果trimIter函数预期处理非ASCII空格字符，可以添加以下测试
TEST(TrimTest, TrimNonASCIISpaces2) {
  std::string s = "\u3000Hello, World!\u3000";  // 使用Unicode全角空格
  trimIter(s);  // 注意：如果trimIter函数不处理非ASCII空格，此测试将失败
  EXPECT_EQ("Hello, World!", s);
}

TEST(TrimTest, TrimBothSides3) {
  std::string s = "   Hello, World!   ";
  trimStd(s);
  EXPECT_EQ("Hello, World!", s);
}

TEST(TrimTest, TrimLeftSide3) {
  std::string s = "   Hello, World!";
  trimStd(s);
  EXPECT_EQ("Hello, World!", s);
}

TEST(TrimTest, TrimRightSide3) {
  std::string s = "Hello, World!   ";
  trimStd(s);
  EXPECT_EQ("Hello, World!", s);
}

TEST(TrimTest, NoTrim3) {
  std::string s = "Hello, World!";
  trimStd(s);
  EXPECT_EQ("Hello, World!", s);
}

TEST(TrimTest, PreserveInternalSpaces3) {
  std::string s = "Hello,   World!";
  trimStd(s);
  EXPECT_EQ("Hello,   World!", s);
}

TEST(TrimTest, EmptyString3) {
  std::string s = "";
  trimStd(s);
  EXPECT_EQ("", s);
}

// 如果trimStd函数预期处理非ASCII空格字符，可以添加以下测试
TEST(TrimTest, TrimNonASCIISpaces3) {
  std::string s = "\u3000Hello, World!\u3000";  // 使用Unicode全角空格
  trimStd(s);  // 注意：如果trimStd函数不处理非ASCII空格，此测试将失败
  EXPECT_EQ("Hello, World!", s);
}
