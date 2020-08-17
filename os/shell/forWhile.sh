#!/bin/bash

for loop in 1 2 3 4 5
do
    echo "The value is: $loop"
done

# 顺序输出字符串中的字符
for str in 'This is a string'
do
    echo $str
done

int=1
while (($int <= 5))
do
    echo $int
    #  let 命令，它用于执行一个或多个表达式，变量计算中不需要加上 $ 来表示变量
    let "int++"
    # int=`expr $int + 1` # 与上面逻辑一样
done

echo '按下 <CTRL-D> 退出'
echo -n '输入你最喜欢的电影名: '
while read FILM
do
    echo "是的！$FILM 是一部好电影"
done

# 无限循环
# while true
# do
#     command
# done
# 或者
# for (( ; ; ))

# until循环执行一系列命令直至条件为真时停止
# 一般while循环优于until循环，但在某些时候—也只是极少数情况下，until循环更加有用
# until condition
# do
#     command
# done
