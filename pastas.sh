#!/bin/bash

program=$PWD

for i in {1..5}
	do
	mkdir "P$i"
	cd P$i
	for j in {1..5}
		do
		mkdir "Prob$j"
		done
	cd ..
	done

echo "DONE!"
	
