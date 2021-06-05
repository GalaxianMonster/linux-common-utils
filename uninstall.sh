#!/bin/bash

crtfl_util=/bin/crtfl
rfl_util=/bin/rfl
listdir_util=/bin/listdir

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
