#!/bin/bash
function attraper(){

	echo "Tu as tapé CTRL + C et je continue !!!"
	echo "J'ai attrapé le signal !!"
}
function quitter(){
	echo "C'est la fin !!"
	exit 0
}

trap 'attraper' SIGINT
trap 'quitter' SIGQUIT SIGTERM

count=0
while true
do
	sleep 1
	count=$(( $count+1))
	echo "PID=$$ et compteur=$count"
done

