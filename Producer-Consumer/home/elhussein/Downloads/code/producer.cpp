#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/time.h>
#include <time.h>
#include <stdio.h>
#include <cstdio>
#include <stdlib.h>
#include <string>
#include <random>
#include <iomanip>
#include <unistd.h>
#include <chrono>
#include <thread>
#include <ctime>
#include <bits/stdc++.h>
#include <vector>
#include <cctype>
#include <cstring>
#include <sys/sem.h>
using namespace std;


typedef struct
{
    char name[10];
    double price;
    double average;

}product;

typedef union{
  
  int val;
  struct semid_ds*buf;
 unsigned short *array;
  struct seminfo*_buf;

}semun;
 
 double produce(double mean,double stand_dev){
  std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
  auto duration = now.time_since_epoch();
  long int nano_time =static_cast<long int>(std::chrono::duration_cast<std::chrono::nanoseconds>(duration).count());
  srand(nano_time);
  default_random_engine generator(rand());
  normal_distribution<double> distribution(mean,pow(stand_dev,2.0));
  double price = distribution(generator);
  return price;
}

int main(int n,char**arr)
{
    string name=arr[1];
    double mean=stod(arr[2]);
    double stand_dev=stod(arr[3]);
    int sleeptime=stoi(arr[4]);
    int buff_size=stoi(arr[5]);
    double sum=0;
    double average;
    double array_sum[999]={0};
    int cntr=0;

    struct sembuf op[1]={{0,0,0}};
    semun ff;
     
    int emptybuff_sem=semget(1000+3,1,0660 | IPC_CREAT);
    int mutex_sem=semget(1000+2,1,0660 | IPC_CREAT);
    int fullbuff_sem=semget(1000+1,1,0660 | IPC_CREAT);
        ff.val=0;
        semctl (fullbuff_sem, 0, SETVAL, ff);
        ff.val=buff_size;
        semctl (emptybuff_sem, 0, SETVAL, ff);
        ff.val=1;
        semctl (mutex_sem, 0, SETVAL, ff);  
        

    // ftok to generate unique key
    key_t key = ftok("shmfile",65);
  
    // shmget returns an identifier in shmid
    int shmid = shmget(6003,sizeof(product)*buff_size,0666|IPC_CREAT);
   
    // shmat to attach to shared memory
      product* str= (product*) shmat(shmid,(void*)0,0); 
     
    while(1){
      
    double price=produce(mean,stand_dev);
   
     struct timespec ts;
     time_t rawtime;
     struct tm *timeinfo;
     rawtime = time(0);
     timeinfo = localtime(&rawtime);
     clock_gettime(CLOCK_REALTIME, &ts);
     printf("[%d/%d/%d %d:%d:%d.%ld] ", timeinfo->tm_mday, timeinfo->tm_mon + 1, 1900 + timeinfo->tm_year, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec, ts.tv_nsec);
     cout<<name<<" :"<<"generating a new value "<<price<<endl;
 

     struct timespec ti;
     time_t rawt;
     struct tm *timeinf;
     rawt = time(0);
     timeinf = localtime(&rawt);
     clock_gettime(CLOCK_REALTIME, &ti);
     printf("[%d/%d/%d %d:%d:%d.%ld] ", timeinf->tm_mday, timeinf->tm_mon + 1, 1900 + timeinf->tm_year, timeinf->tm_hour, timeinf->tm_min, timeinf->tm_sec, ti.tv_nsec);
     cout<<name<<" :"<<"trying to get mutex on shared buffer"<<endl;

     op->sem_op=-1;
     semop (emptybuff_sem, op, 1);

     semop (mutex_sem, op, 1);

     struct timespec tu;
     time_t raw;
     struct tm *timeinfoo;
     raw = time(0);
     timeinfoo = localtime(&raw);
     clock_gettime(CLOCK_REALTIME, &tu);
     printf("[%d/%d/%d %d:%d:%d.%ld] ", timeinfoo->tm_mday, timeinfoo->tm_mon + 1, 1900 + timeinfoo->tm_year, timeinfoo->tm_hour, timeinfoo->tm_min, timeinfoo->tm_sec, tu.tv_nsec);
     cout<<str[cntr%buff_size].name<<" :"<<"placing "<<price<<" on shared buffer"<<endl;


     //critical section
     str[cntr%buff_size].price=price;
      
     strcpy(str[cntr%buff_size].name,name.c_str());
   
     array_sum[cntr%buff_size]=price;
    if(cntr==3){
      sum=array_sum[3]+array_sum[2]+array_sum[1]+array_sum[0];
      average=sum/4;
    }
    else if(cntr==2){
      sum=array_sum[2]+array_sum[1]+array_sum[0];
      average=sum/3;
    }
    else if(cntr==1){
      sum=array_sum[1]+array_sum[0];
      average=sum/2;
    }
    else if(cntr==0){
      sum=array_sum[0];
      average=sum;
    }
    else{
      sum=array_sum[cntr%buff_size]+array_sum[(cntr-1+buff_size)%buff_size]+array_sum[(cntr-2+buff_size)%buff_size]+array_sum[(cntr-3+buff_size)%buff_size]+array_sum[(cntr-4+buff_size)%buff_size];
      average=sum/5;
    }
    
    str[cntr%buff_size].average=average;
    
     op->sem_op=1;
     semop (mutex_sem, op, 1);
     semop (fullbuff_sem, op, 1);
      cntr++;
      
     struct timespec tp;
     time_t rt;
     struct tm *timeinfooo;
     rt = time(0);
     timeinfooo = localtime(&rt);
     clock_gettime(CLOCK_REALTIME, &tp);
     printf("[%d/%d/%d %d:%d:%d.%ld] ", timeinfooo->tm_mday, timeinfooo->tm_mon + 1, 1900 + timeinfooo->tm_year, timeinfooo->tm_hour, timeinfooo->tm_min, timeinfooo->tm_sec, tp.tv_nsec);
  
     cout<<str[cntr%buff_size].name<<" :"<<"sleeping for "<<sleeptime<<" ms"<<endl;
     std::this_thread::sleep_for(std::chrono::milliseconds(sleeptime));
   }

     //detach from shared memory 
     //shmdt(str);
  
    return 0;
}
