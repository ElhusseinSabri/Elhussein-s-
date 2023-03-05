#!/bin/bash
cd $2
ls -IR $1 > directory.info.last
rsync -a $1 $2/$(date +%Y-%m-%d-%H-%M-%S)
while true
do
  ls -IR $1 > directory.info.new
  k=3
  l=$(($k+$4))
  if cmp -s directory.info.new directory.info.last
  then
    echo "No Change Happened in the main directory"
  else
    echo "A Change Happened in the main directory"
    rsync -a $1 $2/$(date +%Y-%m-%d-%H-%M-%S)
    cp  directory.info.new directory.info.last
   ls -l $2 | wc -l  
  fi  
  if  [ "$(ls -l $2 | wc -l)" -gt $l ] 
  then 
    echo "Max number of backups"
    rm -r "$(ls | head -1)"
  else
    echo "Acceptable Number of Backups"
  fi  
  
 
  i=$((i+1))
  echo "Loop number : $i"
sleep $3
done










