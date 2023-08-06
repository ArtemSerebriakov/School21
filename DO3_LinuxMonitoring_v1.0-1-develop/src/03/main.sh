#!/bin/bash

flag=0

if [ "$#" -eq 0 ]
then
echo "Error: input arguments don't exist"
flag=1

elif [ $# -ne 4 ]
then
echo "Error: the script accepts only four arguments"
flag=1

else
for var in $1 $2 $3 $4
do
if [[ ! $var =~ ^[+-]?[0-9]+([.][0-9]+)?$ ]]
then
echo "Error: input argument should be a number"
flag=1
elif [[ $var < 1 || $var > 6 ]]
then
echo "Error: arguments should be from 1 to 6"
flag=1
fi
done
fi

if (( $flag == 0 ))
then
if [[ $1 == $2 || $3 == $4 ]]
then
echo "Error: the colors match"
else
sudo bash functions.sh $1 $2 $3 $4
fi
fi
