/* 
   ========================================
   Hash Function Observation (C++ Version)
   ========================================
   
   Description:
   This program tests and displays the output of hash functions for integer
   and string keys using different table sizes. It utilizes the hash functions
   defined in "hash_fn.cpp".

   Development History:
    - 2025/11/11: Initial implementation

   Developer: Yu-Feng Huang <yfhuang@saturn.yzu.edu.tw>
 */
#include <iostream>
#include <string>
#include <vector>
#include "hash_fn.hpp"
using namespace std;

// Caution: Do not change the content of this file.

int main() {
    // Integer keys
    std::vector<int> intKeys = {21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60};
    
    // Table sizes to test
    std::vector<int> sizes = {10, 11, 37};

    std::cout << "=== Hash Function Observation (C++ Version) ===\n\n";

    for (int m : sizes) {
        std::cout << "=== Table Size m = " << m << " ===\n";
        std::cout << "Key\tIndex\n";
        std::cout << "-----------------\n";
        for (int k : intKeys)
            std::cout << k << "\t" << myHashInt(k, m) << "\n";
        std::cout << "\n";
    }

    // String keys (Non-integer keys)
    std::vector<std::string> strKeys = {"cat", "dog", "bat", "cow", "ant", "owl", "bee", "hen", "pig", "fox"};
    for (int m : sizes) {
        std::cout << "=== String Hash (m = " << m << ") ===\n";
        std::cout << "Key\tIndex\n";
        std::cout << "-----------------\n";
        for (const auto& s : strKeys)
            std::cout << s << "\t" << myHashString(s, m) << "\n";
        std::cout << "\n";
    }
}

    //用餘數做 hash
int myHashInt(int key, int tableSize) {
    return key % tableSize;
}

/*
    https://blog.csdn.net/qq_43382960/article/details/124071223    why times 31
    https://www.cnblogs.com/looyee/articles/11424208.html   
    there is a lot of theory online explain but still  can't understand full so i have use AI help to understand
*/


/// @brief  
/// @param key 
/// @param tableSize 
/// @return 
int myHashString(const string& key, int tableSize) {
    int hash = 0;
    for (char c : key) {
        hash = hash * 31 + c;  // 處理中文或負的 char
    }
    return hash % tableSize;
}

