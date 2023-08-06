#!/bin/bash

start=$(date +%s%N)
directory=$1
number_of_folders=$(sudo find $directory -type d | wc -l)
top_folders=$(find $directory -printf "%s %p\n" -exec du -h {} + | sort -rh | head -n 5 | awk -F '.' '{print $0 " " $NF}' | awk '{print NR " - " $2 ", " $1}')
number_of_files=$(find $directory -type f | wc -l)
number_of_conf=$(find $directory -type f -name "*.conf" | wc -l)
number_of_txt=$(find $directory -type f -name "*.txt" | wc -l)
number_of_exec=$(find $directory -type f -executable | wc -l)
number_of_log=$(find $directory -type f -name "*.log" | wc -l)
number_of_links=$(find $directory -type l | wc -l)
number_of_archives=$(find $directory -type f | grep -c -e .zip -e .tar -e .rar -e .7z)
top_files=$(find $directory -type f -printf "%s %p\n" -exec du -h {} + | sort -rh  | head | awk -F '.' '{print $0 " " $NF}' | awk '{print NR " - " $2 ", " $1 ", " $3}')
top_exec=$(find /home/ -type f -executable -exec du -h {} +| sort -rh | head | awk '{printf "%d - %s, %s, ", NR, $2, $1; system("md5sum $2 | cut -d '-' -f1")}')



echo "Total number of folders (including all nested ones) =" $(sudo find $directory -type d | wc -l)
echo "TOP 5 folders of maximum size arranged in descending order (path and size):"  
echo "$top_folders"
echo "Total number of files =" $number_of_files 
echo "Number of:"
echo "Configuration files (with the .conf extension) =" $number_of_conf  
echo "Text files =" $number_of_txt 
echo "Executable files =" $number_of_exec
echo "Log files (with the extension .log) =" $number_of_log
echo "Archive files =" $number_of_archives  
echo "Symbolic links =" $number_of_links
echo "TOP 10 files of maximum size arranged in descending order (path, size and type):"  
echo "$top_files"
echo "TOP 10 executable files of the maximum size arranged in descending order (path, size and MD5 hash of file)"  
echo "$top_exec"
end=$(date +%s%N)
echo "Script execution time (in seconds) =" $((( $end - $start )/100000000))
