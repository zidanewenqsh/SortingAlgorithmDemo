#!/bin/bash

# 设定 bin 目录的路径
BIN_DIR="bin"  # 请替换为您的 bin 目录的实际路径

# 遍历 bin 目录中的所有文件
for file in "$BIN_DIR"/*; do
    # 检查文件是否为可执行文件
    if [ -x "$file" ]; then
        echo "Running $file..."
        "$file"  # 运行可执行文件
    else
        echo "$file is not an executable file."
    fi
done
