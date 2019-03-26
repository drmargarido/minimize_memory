#!/bin/bash

# remember -- An easy command line based reminder pad

rememberfile="$HOME/.remember"

if [ $# -eq 0 ] ; then
	# Promt the user for input and append to the rememberfile whatever they write
	echo "Enter note, end with ^D: "
	cat - >> $rememberfile
else
	# Append any arguments passed to the script to the remeberfile
	echo $@ >> $rememberfile
fi

exit 0
