#!/bin/bash

# Проверяем, что параметр не пустой
if [ "$#" -eq 0 ]
then
echo "Error: input arguments don't exist"

# Проверяем количество переданных параметров
elif [ $# -ne 1 ]
then
echo "Error: the script accepts only one argument"

else
directory=$1
if [[ !(-d "$directory") || ${directory: -1} != "/" ]]
then
    echo "Error: directory doesn't exist."
else
    sudo bash functions.sh $directory
fi
fi

