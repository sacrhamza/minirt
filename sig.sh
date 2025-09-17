#!/bin/bash

while true
do 
  cpl=$(make miniRt)
  if [[ "$cpl" == "OK" ]]
  then
    pkill -SIGUSR1 miniRt
    echo $?
  else
    echo no
  fi
  sleep 0.5
done
