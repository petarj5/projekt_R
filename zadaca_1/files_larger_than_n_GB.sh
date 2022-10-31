#!/bin/bash

printf "for megabytes -> M\nfor gigabytes -> G\n\texample: 6G; 4M\n"
read -p "Find all files larger than -> " size

mkdir backup

find /home/petar/bin -type f -size +$size -exec cp "{}" ./backup \;
tar -zcf backup.tgz backup/

rm -r backup

find /home/petar -type f -size -$size
