#!/bin/bash

program=$1

compila="$program.c"

if $(find -name $program) != $program; then
	echo "Nao foi necessário remover!"
else
	rm $program
fi

if(clang $compila -o $program); then
	./$program
else
	echo "COMPILATION ERROR!!"
fi
