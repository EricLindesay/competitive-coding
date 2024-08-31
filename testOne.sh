#!/bin/bash


RED='\033[0;31m'
GREEN='\033[0;32m'
END='\033[0m'

error=$( g++ $1 -o run.out -Wall -Wextra -pedantic 2>&1 )
if [ $? -ne 0 ]; then
	echo "${error}"
	echo -e "${RED}COMPILATION ERROR${END}"
	exit 1
fi


let "success=0"
let "total=0"

filename="tests/1.in"
chmod 755 $filename	
SECONDS=0
output=$(./run.out < $filename | xargs)
duration=$SECONDS

just_filename=$(basename -- "$filename")
answer_file="${filename%.*}.out"

answer=$(cat $answer_file | xargs)
let "total++"
if [ "$answer" = "$output" ]; then
	let "success++"
	echo -e ${GREEN}PASSED on test $answer_file in $duration seconds${END}
else
	echo -e ${RED}FAILED on test $answer_file in $duration seconds${END}
	echo "Expected $answer"
	echo "Got $output"
fi

echo "Passed: ${success}/${total} tests"

