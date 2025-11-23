/*
   ========================================
   hash_fn.c — implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/11: Initial implementation
    - 2025/11/17: Refactored to use hash_fn.h

   Developer: Yu-Feng Huang <yfhuang@saturn.yzu.edu.tw>
 */

#include "hash_fn.h"


/**
 * @brief 計算整數鍵值 hash index
 *
 * 處理負數鍵值問題，確保回傳值永遠落在 [0, table_size-1]
 * 建議 table_size 使用質數以獲得最佳分佈均勻度
 *
 * @param key         hash inter
 * @param table_size  hash size
 * @return            範圍 [0, table_size-1]  hash index
 */

int myHashInt(int key, int table_size)
{
    if (table_size <= 0) {
        return 0;  /// 錯誤情況直接回傳 
    }
    /// 處理負數：(key % m + m) % m 
    return (key % table_size + table_size) % table_size;
}




/**
 * @brief 計算字串鍵值的hash index
 *
 * 採用業界標準的 31 基演算法（Java、C#、Python 內建皆用此法）
 * 參考資料：
 *   - https://blog.csdn.net/qq_43382960/article/details/124071223
 *   - https://www.cnblogs.com/looyee/articles/11424208.html
 *
 * @param str         
 * @param table_size  必須 > 0
 * @return            範圍 [0, table_size-1] 的 hash index
 */

int myHashString(const char* str, int table_size)
{
    if (str == NULL || table_size <= 0) {
        return 0;
    }

    unsigned int hash = 0;  // 用 unsigned 防止溢位變負數
    while (*str) {
        hash = hash * 31 + (unsigned char)(*str);
        str++;
    }
    return hash % table_size;
}