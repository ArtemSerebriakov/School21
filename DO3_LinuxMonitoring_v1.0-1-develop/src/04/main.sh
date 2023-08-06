#!/bin/bash

function match() {
if [[ $1 == $2 && "$1" != "default" ]]
then
echo 1
else
echo 0
fi
}

function check_parameter() {
parameter=$1
if [[ $parameter == "=" ]]
then
parameter="default"
fi
echo $parameter
}

color_back_1=$(grep 1_b color.conf)
color_font_1=$(grep 1_f color.conf)
color_back_2=$(grep 2_b color.conf)
color_font_2=$(grep 2_f color.conf)

color_back_1=${color_back_1: -1}
color_font_1=${color_font_1: -1}
color_back_2=${color_back_2: -1}
color_font_2=${color_font_2: -1}

color_back_1=$(check_parameter $color_back_1)
color_font_1=$(check_parameter $color_font_1)
color_back_2=$(check_parameter $color_back_2)
color_font_2=$(check_parameter $color_font_2)

flag=0

if (( $flag == 0 ))
then
for var in $color_back_1 $color_font_1 $color_back_2 $color_font_2
do
if [[ $var != "default" ]]
then
if [[ ! $var =~ ^[+-]?[0-9]+([.][0-9]+)?$ && $flag != 1 ]]
then
echo "Error: input argument should be a number"
flag=1
elif [[ $var < 1 || $var > 6 && $flag != 1 ]]
then
echo "Error: arguments should be from 1 to 6"
flag=1
fi
fi
done
fi

if (( $flag == 0 ))
then
flag=$(match $color_back_1 $color_font_1)
if (( $flag == 1 ))
then
echo "Error: the colors match"
fi
fi

if (( $flag == 0 ))
then
flag=$(match $color_back_2 $color_font_2)
if (( $flag == 1 ))
then
echo "Error: the colors match"
fi
fi

if (( $flag == 0 ))
then
sudo bash functions.sh $color_back_1 $color_font_1 $color_back_2 $color_font_2
fi




