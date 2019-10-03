#!/bin/bash
trap 'stty sane; tput cnorm; tput sgr0;' EXIT

cols=$(tput cols)
rows=$(tput lines)

tput civis
stty -echo

declare -A grid

cleanGrid(){
	for((i=0; i<=rows; i++))do
		for((j=0; j<=cols; j++))do
			grid[$i,$j]=0
		done
	done
}

midRow=$(( $rows / 2 ))
midCol=$(( $cols / 2 ))

initGame(){
	snake="*"

	x=$midRow
	y=$midCol

	xdir=0
	ydir=0

	cur=0
	score=0
	color=$((color%7+1))
	cleanGrid
	clear
}

up='\[A'
down='\[B'
right='\[C'
left='\[D'

initGame

while sleep 0.05
do

	if [[ $y -lt 1 || $y -gt $cols || $x -lt 1 || $x -gt $rows ]]; then
		break
	fi
	((x+=xdir))
	((y+=ydir))
	if [[ ${grid[$x,$y]} -eq 1 && $xdir -ne $ydir ]]; then
		break
	fi
	grid[$x,$y]=1
	while IFS= read -rs -t 0.0001 -n 1 key
	do
		case $key in
			q) exit 0;;
			A) if [[ $cur -ne 1 ]]; then
					((xdir=-1))
					((ydir=0))
					((score++))
					snake="^"
					color=$((color%7+1))
				fi
				((cur=1));;
			B) if [[ $cur -ne 2 ]]; then
					((xdir=1))
					((ydir=0))
					((score++))
					snake="v"
					color=$((color%7+1))
				fi
				((cur=2));;
			C)	if [[ $cur -ne 3 ]]; then
					((ydir=1)) 
					((xdir=0))
					((score++))
					snake=">"
					color=$((color%7+1))
				fi
				((cur=3));;
			D)	if [[ $cur -ne 4 ]]; then
					((ydir=-1)) 
					((xdir=0))
					((score++))
					snake="<"
					color=$((color%7+1))
				fi
				((cur=4));;
		esac	
	done

	output=$(
		tput cup $x $y
		tput setaf "$color"
		printf "%s" "$snake"
	)

	printf "%s" "$output"

done
tput cup $rows 0
echo "your score is: $score"