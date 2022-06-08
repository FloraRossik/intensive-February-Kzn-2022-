read -p "file path >" file_path

cd ..

num1=$(cat $file_path | wc -l)
num2=$(cat $file_path | awk '{print $1}' | uniq | wc -l)

echo "$num1 $num2 $num1"
