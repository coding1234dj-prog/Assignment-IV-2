# Connect to GitHub with VSCode

＃前置步驟  下載  visual studio code ,  git (有github 帳戶)
             （ visual studio code 請在下載後去 extensions 中下載 C/C++ Extension Pack , github pull Request)



Linuxc環境  到 CMD 中打   sudo apt update
                    sudo apt install build-essential gdb -y   （下載必要工具包

    第二步  找到 .vscode/;launch.json   將檔案改成
    {
    "version": "2.0.0",
    "tasks": [
        {
            "type": "cppbuild",
            "label": "C/C++: g++ 編譯當前檔案",
            "command": "/usr/bin/g++",
            "args": [
                "-fdiagnostics-color=always",
                "-g",
                "-std=c++17",          // 或者 c++20、c++11 看你需要
                "${file}",
                "-o",
                "${fileDirname}/${fileBasenameNoExtension}"
            ],
            "options": {
                "cwd": "${workspaceFolder}"
            },
            "problemMatcher": [
                "$gcc"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            },
            "detail": "用 g++ 編譯 C++"
        }
    ]
    }
    之後就可以編譯 C/C++  寫完記得編譯（ shift + ctrl + B ) 編譯成exe檔才可以執行/debug

    再來上傳到github

    第一步
        找到![alt text](image-1.png)  然後按照它的指示你會連到你的帳號且需要驗證  （據體照片我沒有做完就消失了）
    第二步
        正式上傳  先到cmd中設定你的 email , name 是為了告訴github你是誰讓管理方便
    第三步 
        回到VS 要選擇上傳道哪個 repository  又會分成兩種
            
            第一種  直接到一個新的 repository   在source contronl 中找到雲端的標誌點下 或按 Ctrl+Shift+G 就會跳出視窗
            
            Publish to GitHub
            Publish to Private Repository
            Repository name: ▍ ← 這裡可以自己打倉庫名稱！

            按 Enter → 選 Public 或 Private → 登入 GitHub → 完成！
            VS Code 會自動在你 GitHub 帳號下建立這個名字的倉庫，並把所有 commit 推上去

            第二種  找到已有的 repository  

            在 VS Code 按 Ctrl+Shift+P → 輸入 Git: Add Remote
            再輸入/選擇你要的repository
            回到主畫面，按雲朵圖示 → 選 Push 或 Publish Branch
