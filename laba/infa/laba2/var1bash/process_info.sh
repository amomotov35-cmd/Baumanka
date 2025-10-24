#!/bin/bash

ps -e

c=$( ps -e | wc -l)
((c -= 1))

echo "$c"
 
