CC      := gcc
CXX     := g++
CFLAGS  := -std=c23 -Wall -Wextra -Wpedantic -g
CFLAGS  := -std=c2x -Wall -Wextra -Wpedantic -g

C_SRCS   := $(wildcard C/*.c)
CXX_SRCS := $(wildcard CXX/*.cpp)

C_BIN    := C/hash_function
CXX_BIN  := CXX/hash_function_cpp

all: $(C_BIN) $(CXX_BIN)
	@echo "全部編譯完成！"
	@echo "執行 C   版：./$(C_BIN)"
	@echo "執行 C++ 版：./$(CXX_BIN)"

$(C_BIN): $(C_SRCS)
	$(CC) $(CFLAGS) $^ -o $@

$(CXX_BIN): $(CXX_SRCS)
	$(CXX) $(CXXFLAGS) $^ -o $@

c: $(C_BIN)
	./$(C_BIN)

cxx: $(CXX_BIN)
	./$(CXX_BIN)

run: all
	@echo "======== C 版測試 ========"
	./$(C_BIN)
	@echo "======== C++ 版測試 ======="
	./$(CXX_BIN)

clean:
	rm -f $(C_BIN) $(CXX_BIN) *.o C/*.o CXX/*.o

.PHONY: all c cxx run clean