#include "modifiers.h"
#include <string>
#include <algorithm>
#include <cstring>

// 一个最简单的trim函数
// 无法处理Unicode空格字符，且通过最简单的循环查找前后的空格
void trimTrial(std::string& s) {
    int i = 0, j = s.length() - 1;
    while (i <= j && s[i] == ' ') i++;
    while (j >= i && s[j] == ' ') j--;
    s = s.substr(i, j - i + 1);
}

// 迭代器
void trimIter(std::string& s) {
    const char ascii_space = ' ';
    const char* fullwidth_space = "\xE3\x80\x80"; //u8"\u3000";  // 使用u8前缀来指定UTF-8字符串字面量
    size_t fullwidth_space_len = strlen(fullwidth_space);

    s.erase(s.begin(), std::find_if_not(s.begin(), s.end(), [&](char ch) {
        return ch == ascii_space || (s.substr(0, fullwidth_space_len) == fullwidth_space && &s[0] == &ch);
    }));

    s.erase(std::find_if_not(s.rbegin(), s.rend(), [&](char ch) {
        return ch == ascii_space || (s.substr(s.length() - fullwidth_space_len) == fullwidth_space && &s[s.length() - 1] == &ch);
    }).base(), s.end());
}

#include <cctype> // for std::isspace
// 库函数isspace
// 在某些情况下，可能需要设置正确的区域设置以便std::isspace正确处理Unicode空格
// 例如，在Unix系统上，你可以设置环境变量LC_ALL为某个支持Unicode的区域设置
// setenv("LC_ALL", "en_US.utf8", 1); // 这只是一个例子，你需要根据你的系统和需求进行调整
void trimStd(std::string& s) {
    s.erase(s.begin(), std::find_if_not(s.begin(), s.end(), [](unsigned char ch) {
        return std::isspace(ch);
    }));

    s.erase(std::find_if_not(s.rbegin(), s.rend(), [](unsigned char ch) {
        return std::isspace(ch);
    }).base(), s.end());
}
