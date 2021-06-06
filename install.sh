#!/bin/bash

if [ "$#" -lt "1" ];
then
	printf "\033[31mError:\033[0m Missing Argument 2(compiler path)\n"
	exit 0
fi

COMPILER=$1
if test -f "$COMPILER";
then
	$COMPILER -o /usr/bin/rfl ./rfl.c
	$COMPILER -o /usr/bin/listdir ./listdir.c
	$COMPILER -o /usr/bin/crtfl ./crtfl.c
else
	printf "\033[31mError:\033[0m Cannot find Compiler \"$COMPILER\"\n"
fi

exit 0
