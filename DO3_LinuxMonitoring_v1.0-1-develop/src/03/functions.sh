#!/bin/bash

# Обозначения цветов: (1 - white, 2 - red, 3 - green, 4 - blue, 5 – purple, 6 - black)
font=('\e[97m' '\e[31m' '\e[32m' '\e[34m' '\e[35m' '\e[30m')
background=('\e[107m' '\e[41m' '\e[42m' '\e[44m' '\e[45m' '\e[40m')

function color(){
  echo "${background[$1-1]}${font[$2-1]}$3\e[0m"
}

hostname=$(hostname)
timezone=$(timedatectl | grep "Time zone" | awk '{print $3,"UTC",$5}'| tr -d "0()")
user=$(whoami)
os=$(cat /etc/issue | awk '{print $1, $2, $3}')
date=$(date | awk '{print $2, $3, $4, $5}')
uptime=$(uptime -p)
uptime_sec=$(cat /proc/uptime | awk '{print $1}')
ip=$(hostname -I)
mask=$(ifconfig | grep -m1 'netmask' | awk '{print $4}')
gateway=$(ip route | grep 'default' | awk '{print $3}')
ram_total=$(free -m | grep 'Mem' | awk '{printf "%.3f GB" , $2/1024}')
ram_used=$(free -m | grep 'Mem' | awk '{printf "%.3f GB" , $3/1024}')
ram_free=$(free -m | grep 'Mem' | awk '{printf "%.3f GB" , $4/1024}')
space_root=$(df -h /root | grep "/" | awk '{printf "%.2f MB" , $2 * 1024}')
space_root_used=$(df -h /root | grep "/" | awk '{printf "%.2f MB" , $3 * 1024}')
space_root_free=$(df -h /root | grep "/" | awk '{printf "%.2f MB" , $4 * 1024}')

echo -e "$(color $1 $2 HOSTNAME) =" $(color $3 $4 $hostname)
echo -e "$(color $1 $2 TIMEZONE) =" $(color $3 $4 $timezone)
echo -e "$(color $1 $2 USER) =" $(color $3 $4 $user)
echo -e "$(color $1 $2 OS) =" $(color $3 $4 $os)
echo -e "$(color $1 $2 DATE) =" $(color $3 $4 $date)
echo -e "$(color $1 $2 UPTIME) =" $(color $3 $4 $uptime)
echo -e "$(color $1 $2 UPTIME_SEC) =" $(color $3 $4 $uptime_sec)
echo -e "$(color $1 $2 IP) =" $(color $3 $4 $ip)
echo -e "$(color $1 $2 MASK) =" $(color $3 $4 $mask)
echo -e "$(color $1 $2 GATEWAY) =" $(color $3 $4 $gateway)
echo -e "$(color $1 $2 RAM_TOTAL) =" $(color $3 $4 $ram_total)
echo -e "$(color $1 $2 RAM_USED) =" $(color $3 $4 $ram_used)
echo -e "$(color $1 $2 RAM_FREE) =" $(color $3 $4 $ram_free)
echo -e "$(color $1 $2 SPACE_ROOT) =" $(color $3 $4 $space_root)
echo -e "$(color $1 $2 SPACE_ROOT_USED) =" $(color $3 $4 $space_root_used)
echo -e "$(color $1 $2 SPACE_ROOT_FREE) =" $(color $3 $4 $space_root_free)
