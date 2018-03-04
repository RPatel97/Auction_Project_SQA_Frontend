#!/bin/bash

shopt -s nullglob

for f in ./TESTS/**/*.inp; do
    _FILE="${f##*/}"
    _NAME="${_FILE%%.*}"
    _PATH="${f%/*}/"

    echo Running test $_NAME

    rm ./dailyTransactionFile.atf >/dev/null 2>&1
    touch ./dailyTransactionFile.atf
    "./Auction" currentusers.txt items.txt dailyTransactionFile.atf <$f >$_PATH/$_NAME.out 

    diff $_PATH/$_NAME.etf ./dailyTransactionFile.atf
    if [ ! $? -eq 0 ]; then
        echo Test $_NAME fail
	printf "\n"
    else
        echo Test $_NAME success
        printf "\n"
    fi
done

cd ..