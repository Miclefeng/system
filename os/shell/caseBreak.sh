#!/bin/bash
echo '输入 1 到 4 之间的数字：'
echo '你输入的数字为：'
read aNum

# case 需要一个esac（就是case反过来）作为结束标记，
# 每个case分支用右圆括号，用两个分号表示break
case $aNum in
    1) echo "choice 1"
        ;;
    2) echo "choice 2"
        ;;
    3) echo "choice 3"
        ;;
    4) echo "choice 4"
        ;;
    *) echo "no choice 1 - 4"
        ;;
esac

while :
do
    echo -n "输入 1 到 5 之间的数字："
    read bNum
    case $bNum in
        1|2|3|4|5) echo "你输入的数字为：$bNum"
            ;;
        *) echo "你输入的数字不是 1 到 5 之间的! 游戏结束"
            # break命令允许跳出所有循环（终止执行后面的所有循环）。
            # continue命令与break命令类似，只有一点差别，它不会跳出所有循环，仅仅跳出当前循环。
            break
            ;;
    esac
done
