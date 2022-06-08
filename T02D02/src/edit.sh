#!/bin/bash

read -p "Enter please name file: " file_path
read -p "Enter substring: " substring
read -p "Enter please line replace: " replacement

if [[ "$file_path" = "" ]]; then
    echo "file path empty !"
exit 1;
fi

sed -i "s/$substring/$replacement/g" $file_path

if [ $? -ne 0 ]; then
    echo 'error occured in replacement'
exit 1;
fi

checksum=$(sha256sum $file_path | awk '{printf $1}')

if [ $? -ne 0 ]; then
    echo 'error occured in checksum'
exit 1;
fi

file_size=$(wc -c $file_path | awk '{printf $1}')

if [ $? -ne 0 ]; then
    echo 'error occured in file size'
exit 1;
fi

time_now=$(date +"%Y-%m-%d %H:%M")

if [ $? -ne 0 ]; then
    echo 'error occured in time'
exit 1;
fi

echo "src/$file_path - $file_size - $time_now - $checksum - sha256" >> files.log
