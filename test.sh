#!/bin/bash

mpath="test_maps/"

maps=("100-6.fdf" 
	"10-2.fdf"
	"10-70.fdf"
	"20-60.fdf"
	"42.fdf"
	"43.fdf"
	"50-4.fdf"
	"basictest.fdf"
	"elem2.fdf"
	"elem-col.fdf"
	"empty.fdf"
	"flat.fdf"
	"mars.fdf"
	"one_line.fdf"
	"pentenegpos.fdf"
	"plat.fdf"
	"pnp_flat.fdf"
	"pylone.fdf"
	"pyra.fdf"
	"pyramide.fdf"
	"simple.fdf"
	"t1.fdf"
	"t2.fdf")

basic_cmd="./fdf"
debug_cmd="valgrind -s ./fdf"
cmd=$basic_cmd

while getopts "bhd" option; do
	case $option in 
		b)
			maps+=("elem-fract.fdf" "julia.fdf");;
		h)
			echo "-h	help"
			echo "-b	test big maps (elem-fract and julia)"
			echo "-d	show leaks"	
			exit;;
		d)
			echo "debug mode"
			cmd=$debug_cmd;;	
	esac
done
make

for str in ${maps[@]}; do
	echo "NOM DE LA MAP TESTEE :" $str
	if [[ $cmd == *"valgrind"* ]]; then
		$cmd &> tmp.txt "$mpath$str" && egrep -A5 "LEAK SUMMARY|no leaks are possible" tmp.txt
	else
		$cmd "$mpath$str"
	fi
	echo "###############################"
	rm -rf tmp.txt
done
