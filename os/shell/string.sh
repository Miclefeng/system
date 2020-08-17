#!/bin/bash
string="abcd"
# 截取字符串
echo "hello, ${string:1:4}"

# 获取字符串长度
echo "${#string}"

# 查找子字符串
str="runoob is a great site"
# 位置从1开始计算
echo `expr index "$str" is`

# 拼接字符串
str1="hello"
word="world"
union1="${str1}, ${word}"
echo $union1
