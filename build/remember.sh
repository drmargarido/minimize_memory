#!/bin/bash
# remember -- An easy command line based reminder pad

rememberfile="$HOME/.remember"


if [ $# -eq 0 ] ; then

    # Prompt the user for input and append to the rememberfile whatever they wrote.
    echo "Enter note, end with ^D: "
    cat - >> $rememberfile
else
    # Send any arguments passed to the script into the remeberfile.
    echo $@ >> $rememberfile
fi

exit 0

