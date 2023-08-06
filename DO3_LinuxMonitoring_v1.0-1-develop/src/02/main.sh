#!/bin/bash

data=$(sudo bash functions.sh)
echo "$data"
read -p "Do you want to save the data to a file? (Y/N): " answer
if [[ "$answer" == "y" ||  "$answer" == "Y" ]]
then
file="$(date +%d_%m_%y_%H_%M_%S).status"
echo "$data" > "$file"
fi
