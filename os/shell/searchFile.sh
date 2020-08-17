#!/bin/bash

BASE=/dev/shm/www-temp

for FILE in `find $BASE -type f -mmin +720`
do
    DIR_1=`echo $FILE | awk -F '/' 'BEGIN{OFS="/"}{print $1,$2,$3,$4,$5}'`
    DIR_2=`echo $FILE | awk -F '/' 'BEGIN{OFS="/"}{print $1,$2,$3,$4,$5,$6}'`
    # BEGIN{OPS="/"} 指定 "/" 为拼接前缀,$NF="";去除最后一个元素
    DIR_3=`echo $FILE | awk -F '/' 'BEGIN{OFS="/"}{$NF="";print}'`

    if [ `ls $DIR_3 | wc -l` -gt 1 ];then
        `rm -f $FILE`
    else
        if [ `ls $DIR_2 | wc -l` -gt 1 ];then
            `cd $DIR_2`
            `rm -rf $DIR_3`
        else
            if [ `ls $DIR_1 | wc -l` -gt 1 ];then
                `cd $DIR_1`
                `rm -rf $DIR_2`
            else
                `rm -rf $DIR_1`
            fi
        fi
    fi
done
