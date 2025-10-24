#!/bin/bash

if [ "$#" -ne 1 ]
then
	echo "Имя скрипта: $0 <число> "
	exit 1
fi

if (( number % 2 == 0 ))
 then
    echo "Число четное"
else
    echo "Число нечетное"
fi
