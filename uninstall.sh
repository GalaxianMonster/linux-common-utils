#!/bin/bash

crtfl_util=/usr/bin/crtfl
rfl_util=/usr/bin/rfl
listdir_util=/usr/bin/listdir

if test -f "$crtfl_util";
then
	rm "$crtfl_util"
fi

if test -f "$rfl_util";
then
	rm "$rfl_util"
fi

if test -f "$listdir_util";
then
	rm "$listdir_util"
fi
