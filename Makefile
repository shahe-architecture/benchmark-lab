# 目标可执行文件
TARGET = main

# 编译器
CC = gcc

# 编译选项
CFLAGS = -Wall -g

# 源文件
SRCS = main.c workloads/semiring/run.c workloads/semiring/semiring.c

# 头文件路径
INCLUDES = -Iworkloads

# 目标文件
OBJS = $(SRCS:.c=.o)

# 默认目标
all: $(TARGET)

# 链接目标文件生成可执行文件
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# 编译每个源文件生成目标文件
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# 清理生成的文件
clean:
	rm -f $(OBJS) $(TARGET)

# 伪目标，防止与同名文件冲突
.PHONY: all clean
