#!/bin/bash

# read 从标准输入中读取一行，并把输入行的每个字段的值指定给 shell 变量
read name
echo "$name It is a test!"

# -e 开启转义
echo -e "Ok! \n is a test"
# \c 不换行
echo -e "OK! \c"
echo "is a test!"

# 原样输出，单引号不解析变量和转义符
echo '$name\"'

# 显示命令执行结果
echo `date`
