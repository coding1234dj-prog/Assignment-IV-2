/*
   ========================================
   hash_fn.hpp — declare your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/17: Initial implementation

   Developer: Yu-Feng Huang <yfhuang@saturn.yzu.edu.tw>
 */
#ifndef HASH_FN_HPP
#define HASH_FN_HPP

#include <string>

int myHashString(const std::string& str, int m);
int myHashInt(int key, int m);

#endif


/**
 * @brief Computes the hash index for an integer key using division hashing.
 * 
 * @param key  The integer key to hash (can be negative)
 * @param tableSize    The hash table size (must be > 0, preferably prime)
 * @return     Hash index in range [0, m-1]
 */
int myHashInt(int key, int tableSize) {
    return key % tableSize;
}




/*
    https://blog.csdn.net/qq_43382960/article/details/124071223    why times 31
    https://www.cnblogs.com/looyee/articles/11424208.html
*/




/** 
* @brief  Computes the hash index for a string key using polynomial rolling hash.
* @param key 
* @param tableSize 
* @return Hash index in range [0, m-1]
*/
int myHashString(const string& key, int tableSize) {
    int hash = 0;
    for (char c : key) {
        hash = hash * 31 + c;  // 處理中文或負的 char
    }
    return hash % tableSize;
}

