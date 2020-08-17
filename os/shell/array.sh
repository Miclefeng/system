#!/bin/bash

arr=(focus society ent military tech finance sports)
for var in ${arr[@]};
do
    echo $var
done

# 使用 @ 或者 * 符号可以获取数组中的所有元素
echo "数组的元素为：${arr[@]}"
echo "数组的元素为：${arr[*]}"

# 获取数组中元素的个数
echo "数组中元素的个数为：${#arr[@]}"
