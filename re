#! /bin/bash
for file in * 
do
	name=$(echo $file | sed 's/_\([0-9]\)$/_00\1/')
	new=$(echo $name| sed 's/_\([0-9][0-9]\)$/_0\1/')
	if [ $file != $new ]; then
		mv $file $new
	fi
done
