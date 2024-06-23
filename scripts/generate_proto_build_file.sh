#!/bin/bash

# 定义递归函数
process_proto_directory() {
    local directory="$1"

    # 遍历当前目录中的文件和子目录
    for item in "$directory"/*; do
        if [ -d "$item" ]; then
            # 检查是否为proto目录
            if [ "$(basename "$item")" == "proto" ]; then
                echo "Processing proto directory: $item"
                python3 scripts/proto_build_generator.py "$item/BUILD"
            else
                process_proto_directory "$item" # 递归调用处理子目录
            fi
        fi
    done
}

# 起始目录
start_directory="drivers"

# 调用递归函数处理起始目录
process_proto_directory "$start_directory"
