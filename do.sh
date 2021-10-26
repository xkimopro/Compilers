#!/bin/sh
if [ "$1" != "" ]; 
then
    echo "Compiling $1"
    ./parser < $1 > a.ll || exit 1
    llc a.ll -o a.s
    gcc a.s ./edsger_lib/lib.a -o a.out -no-pie -g
fi