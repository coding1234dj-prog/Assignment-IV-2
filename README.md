### Assignment IV - Hash Functions Implementation & Analysis

    Developer:  劉弘翔
    Email: s1100860@mail.yzu.edu.tw  / coding1234dj@gmail.com
    執行環境：Ubuntu 22.04 LTS (Linux) + GCC 13.2 + Make 4.3

### My Hash Function
# Integer Keyse  
        簡單明瞭，餘數就可以使了   
# Non-integer Keys 
        : ( hash = hash * 31 + c ) % size 

### Experimental Setup
Table sizes tested (m): 10, 11, 37
Test dataset:
Integers: 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60
Strings: "cat", "dog", "bat", "cow", "ant", "owl", "bee", "hen", "pig", "fox"
Compiler: GCC and G++
Standard: C23 and C++23

### Compilation
- The project uses a comprehensive Makefile that builds both C and C++ versions with proper flags:
  ```bash
  # Build both C and C++ versions
  make all
  
  # Build only C version
  make c
  
  # Build only C++ version
  make cxx
  ```

  
### RESULT AND OUTCOME        

### 為什麼字串哈希要用 31？
- 31 是質數，且能被編譯器優化為 `(hash << 5) - hash`
- Java、C#、Python、Rust 等主流語言內建字串哈希皆使用 31
- 經過數十年實戰驗證，分佈最均勻、碰撞率最低
- 參考資料：
  - https://blog.csdn.net/qq_43382960/article/details/124071223
  - https://www.cnblogs.com/looyee/articles/11424208.html

### 為什麼哈希表大小建議用質數？

| 表大小 (m)  | 鍵值 0~99 的哈希分佈範例            | 觀察結果                         |
|------------|----------------------------------|-------------------------------  |
| 10         | 0,1,2,3,4,5,6,7,8,9,0,1,2...     | 每 10 個就完全重複，極差           |
| 11         | 0,1,2,3,4,5,6,7,8,9,10,0,1...    | 11 個才重複，分布較均勻            |
| 37         | 0,37,74,33,13,50,29,10,69...     | 近乎隨機，極度均勻（推薦）          |
| 97         | 甚至更好（更大質數）                 | 推薦用在正式專案                  |
 
 
  結論：**表大小使用質數可大幅降低系統性碰撞**，尤其是除法哈希法。


### make

<img width="828" height="141" alt="image" src="https://github.com/user-attachments/assets/3c5a1ada-1562-42e2-8123-27c0aa2324a0" />

### make c

<img width="581" height="1252" alt="image" src="https://github.com/user-attachments/assets/2422a372-1cd6-4e7c-9e6c-fbfd8d7b6430" />
<img width="587" height="1364" alt="image" src="https://github.com/user-attachments/assets/5f2c6e31-48bf-4ed6-ba9d-b2814d57ce57" />
<img width="587" height="358" alt="image" src="https://github.com/user-attachments/assets/41a02d65-244d-48f0-bf50-03d12ec59490" />

## make cxx

<img width="614" height="1264" alt="image" src="https://github.com/user-attachments/assets/7c305383-405d-43d2-ba0d-bdcba4bb9865" />
<img width="561" height="1342" alt="image" src="https://github.com/user-attachments/assets/6f17b1cb-ba49-4539-b834-82a8ba28fefc" />
<img width="561" height="366" alt="image" src="https://github.com/user-attachments/assets/be5b2df7-8073-4b58-9b95-fb0437fb40aa" />

### Analysis

第一個int  很簡單，直接除就好：發生collision?  那是空間不夠大，把size放大就沒這個問題了

str 就是我上查到的資料了
    31 是個質數（prime）
質數可以讓乘法分佈更均勻，減少碰撞。
  **31 × hash 可以用位運算優化
編譯器會把 hash * 31 優化成 (hash << 5) - hash，速度非常快。
Java、C#、Python 等語言的字串哈希都用 31
所以這已經是業界標準做法了

### Reflection

根據查到的資料來看似乎2^n -1 的倍數是且是質數會是最好的
   
