#!/bin/bash

read -p "Number of minutes -> " minutes

mkdir backup

find /home/petar/bin -type f -mmin -$minutes -exec cp "{}" ./backup \;
tar -zcf backup.tgz backup/

rm -r backup

find /home/petar -type f -mmin -$minutes
