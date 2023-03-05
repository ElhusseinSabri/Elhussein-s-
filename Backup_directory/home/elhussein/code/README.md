###please put this text file in makereadme.com before you read so you could understand.
# Lab2
This is the read me file of the project that explains every part of it in three sections : overview-prerequisites -running instructions 
## Overview

The project consist of Lab2 directory that contains in it 2 directories and 1 Makefile and 1 bash script .

The 2 directories are : 1-dir and this the main directory (the source that we will back up)
2-backupdir and this is the destination directory in which we will backup the dir directory .

Then regarding the code in the bash script 

```bash
#!/bin/bash
cd $2 ##open the specified directory in the 2nd parameter
ls -IR $1 > directory.info.last ## list of all the files inside the first parameter directory in this text file called directory.info.last
rsync -a $1 $2/$(date +%Y-%m-%d-%H-%M-%S) ## backup the main directory (the first parameter or the source) into backupdir as a directory with its name is the current date with this format YY-MM-DD-HH-mm-ss
while true ##starts an infinte loop to keep checking the main directory to see whether it was changed or not 
do
  ls -IR $1 > directory.info.new ##list the files inside the first parameter directory another time in this text file called directory.info.new
  k=3 ## just a constant to help us add 3 to the max number of backups 
  l=$(($k+$4)) ## l=max number of backups ($4) + (3 for the 2 text files and the directory itself)
   if cmp -s directory.info.new directory.info.last ## check every loop whether the 2 text files are different or not then it means that something has changed
  then
    echo "No Change Happened in the main directory"
  else
    echo "A Change Happened in the main directory"
    rsync -a $1 $2/$(date +%Y-%m-%d-%H-%M-%S) ## if a change happened then we backup the main directory another time in the backupdir with a new directory and its name is the current date 
    cp  directory.info.new directory.info.last ## update the .last text file with the .new text file
   ls -l $2 | wc -l ## list the number of files and directories inside the backupdir  
  fi  
  if  [ "$(ls -l $2 | wc -l)" -gt $l ] ## check if the number of backup directories is greater than the max backups specified by the user then delete the oldest one
  then 
    echo "Max number of backups"
    rm -r "$(ls | head -1)" ## removing the oldest backup directory
  else
    echo "Acceptable Number of Backups"
  fi  
  
 
  i=$((i+1))
  echo "Loop number : $i" ## just printing the loop number for visual checking
sleep $3 ## wait between every check a specific time given by user at the third parameter
done
```
## prerequisites 
only the make package is required to install to run the makefile and if any package is missing an error will pop during the running of the code please write in the terminal as shown below in the second line but by changing the name fo package of course 
```bash
~$sudo apt install make
~$sudo apt install packageName ## if there is any other missing package 
```

## Running instructions 
to run your code first of all make sure to give the right parameters that you want inside the Makefile.

open the 6716-lab2 directory you will find a Makefile open it and you will find the following code please don't mess with line 1,2 or 4  . 

To change the parameters we have 4 types of them : the source directory , the backup directory , the waiting time between ever check and the maximum number of backups respectively.

-You change the source directory in line 5 don't touch @./backupd.sh just change the second sentence /home/elhussein/6716-lab2/dir/ and replace it with the full path of your directory in ex : /homedirectory/subdirectiry/6716-lab2/dir/

-To change the destination backup directory you will have to change it twice once in line 3 and once in line 5 
change them the same way you changed the source directory by changing the full path to the full path of the destination directory twice once in line 3 in place of "~/home/elhussein/6716-lab2/backupdir/" and the third sentence in line 5 at the place of "/home/elhussein/6716-lab2/backupdir/"and in extra at the end of the line 3 change "backupdir" word with the name of the destination directory.

-Then if you want to change the waiting time between every check just go to line 5 and the number 5 with the desired number of seconds you want to wait between every check.

-Last thing if you want to change the number of maximum backups go to the last thing at line 5 and change number 10 with the desired number of maximum backups.

1 all: check run

2 check:

3	@if [ ! -d "~/home/elhussein/6716-lab2/backupdir/" ];then mkdir -p backupdir; fi	   

4 run: 	 	
	

5 @./backupd.sh /home/elhussein/6716-lab2/dir/ /home/elhussein/6176-lab2/backupdir/ 5 10

Now after you changed the parameters and saving the Makefile all you need to do is just opening the terminal and changing the directory to Lab2 directory and typing make as shown below.

```bash
~$cd 6716-lab2
~/6716-lab2$ make
```

And it is good to go. 


##Thank you for your reading 
