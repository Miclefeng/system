#!/bin/bash

FILE_NAME=/root/updatefile.list

for fname in `cat $FILE_NAME`
do
        scp root@192.168.202.5:$fname ./
        if [ ! `echo $?` ] ;then
            # OFS 指定结果连接符;$NF="" 取反模式
            scp `echo $fname | awk -F '/' '{print $NF}'` root@192.168.202.2:`echo $fname | awk -F '/' 'BEGIN{OFS="/"}{$NF="";print}'`
        fi
done

exit 0