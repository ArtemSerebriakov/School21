#!/bin/bash
#Part 1. First effort/Проба пера
#Скрипт запускается с одним параметром. Параметр текстовый.
#Скрипт выводит значение параметра.
#Если параметр - число, то должно выводится сообщение о некорректности ввода.

# Проверяем, что параметр не пустой
if [ "$#" -eq 0 ]
then
echo "Error: input arguments don't exist"

# Проверяем количество переданных параметров
elif [ $# -ne 1 ]
then
echo "Error: the script accepts only one argument"

# Проверяем, что параметр не является числом
elif [[ $1 =~ ^[+-]?[0-9]+([.][0-9]+)?$ ]]
then
echo "Error: input argument can't be a number"

# Выводим значение параметра
else
echo "Input argument: $1"
fi
