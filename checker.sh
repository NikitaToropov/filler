#!/bin/bash

my_filler=./cmissy.filler

mapsArray=("map00" "map01" "map02")
playersArray=("abanlin.filler" "carli.filler" "champely.filler"
			"grati.filler" "hcao.filler" "superjeannot.filler")

for i in ${!mapsArray[@]};
do
	for l in ${!playersArray[@]};
	do
		echo -e "\033[37;1;44m P1 - $my_filler \033[0m vs \033[37;1;41m P2 - ${playersArray[$l]} \033[0m \033[37;1;41m map = ${mapsArray[$i]} \033[0m"
		for (( a=1; a <= 3; a++ ))
		do
			result=`./resources/filler_vm -f resources/maps/${mapsArray[$i]} -p1 $my_filler -p2 ./resources/players/${playersArray[$l]} | grep -e "== X fin:" -e "== O fin:"`
			me=`echo $result | awk '{print $4}'`
			enemy=`echo $result | awk '{print $8}'`

			if [ $me -gt $enemy ]
			then
			echo $me : $enemy - win
			else
			echo $me : $enemy - loose
			fi
		done
		echo -e "\033[37;1;41m P1 - ${playersArray[$l]} \033[0m vs \033[37;1;44m P2 - $my_filler \033[0m \033[37;1;41m map = ${mapsArray[$i]} \033[0m"
		for (( a=1; a <= 3; a++ ))
		do
			result=`./resources/filler_vm -f resources/maps/${mapsArray[$i]} -p1 ./resources/players/${playersArray[$l]} -p2 $my_filler | grep -e "== X fin:" -e "== O fin:"`
			enemy=`echo $result | awk '{print $4}'`
			me=`echo $result | awk '{print $8}'`

			if [ $me -gt $enemy ]
			then
			echo $enemy : $me - win
			else
			echo $enemy : $me - loose
			fi
		done
		echo -e "\n\n"
	done
done