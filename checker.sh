#!/bin/bash

my_filler=./cmissy.filler

mapsArray=("map00" "map01" "map02")
playersArray=("abanlin.filler" "carli.filler" "champely.filler"
			"grati.filler" "hcao.filler" "superjeannot.filler")
red='\033[0;31m'
red_block='\033[37;1;41m'
blue_block='\033[37;1;44m'
green='\033[0;32m'
reset='\033[0m'

for i in ${!mapsArray[@]};
do
	for l in ${!playersArray[@]};
	do
		echo -e "$blue_block P1 - $my_filler $reset vs $red_block P2 - ${playersArray[$l]} $reset $red_block map = ${mapsArray[$i]} $reset"
		for (( a=1; a <= 3; a++ ))
		do
			result=`./resources/filler_vm -f resources/maps/${mapsArray[$i]} -p1 $my_filler -p2 ./resources/players/${playersArray[$l]} | grep -e "== X fin:" -e "== O fin:"`
			me=`echo $result | awk '{print $4}'`
			enemy=`echo $result | awk '{print $8}'`

			if [ $me -gt $enemy ]
			then
			echo -e "$green win $reset - $me : $enemy"
			else
			echo -e "$red loose $reset - $me : $enemy"
			fi
		done
		echo -e "$red_block P1 - ${playersArray[$l]} $reset vs $blue_block P2 - $my_filler $reset $red_block map = ${mapsArray[$i]} $reset"
		for (( a=1; a <= 3; a++ ))
		do
			result=`./resources/filler_vm -f resources/maps/${mapsArray[$i]} -p1 ./resources/players/${playersArray[$l]} -p2 $my_filler | grep -e "== X fin:" -e "== O fin:"`
			enemy=`echo $result | awk '{print $4}'`
			me=`echo $result | awk '{print $8}'`

			if [ $me -gt $enemy ]
			then
			echo -e "$green win $reset - $enemy : $me"
			else
			echo -e "$red loose $reset - $enemy : $me"
			# echo $enemy : $me - loose
			fi
		done
		echo -e "\n"
	done
done