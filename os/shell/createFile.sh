#!/bin/bash
FILE_PATH=/opt/linux/shell/file_list
for FILE in `cat $FILE_PATH`
do
    #echo $FILE
    #DIR=`echo $FILE | awk -F '/' 'BEGIN{OFS="/"}{$NF="";print}'`
    #echo $DIR
    #`mkdir -p $DIR`
    #`touch $FILE`
    #`echo 'this is test' > $FILE`
    LINE=`cat $FILE`
    echo $LINE
done
