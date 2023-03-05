#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <cstdio>
#include <stdlib.h>
#include <cstring>
#include <chrono>
#include <thread>
#include <ctime>
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

void display_temp(string name,double price[11][2],double average[11][2],int pf[11],int af[11]){

  string names[11];
  names[0]="Aluminum";
  names[1]="Copper";
  names[2]="Gold";
  names[3]="Silver";
  names[4]="Zinc";
  printf("\e[1;1H\e[2J");
  //cout<<average[1][1]<<endl;
  
  if(name=="Aluminum"){
  cout<<"+-------------------------------------+"<<endl;
  cout<<"| Currency      |  Price   | AvgPrice |"<<endl;
  cout<<"+-------------------------------------+"<<endl;
  if(pf[0]==1){
  cout<<"| Aluminum      | "; printf("\033[;32m%7.2lf\033[0m",price[0][1]); cout<<"↑ | "; 
  }
  else if(pf[0]==-1){
  cout<<"| Aluminum      | "; printf("\033[;31m%7.2lf\033[0m",price[0][1]); cout<<"↓ | "; 
  }
  else{
    cout<<"| Aluminum      | "; printf("\033[;34m%7.2lf\033[0m",price[0][1]); cout<<"  | "; 
  }
  if(af[0]==1){
   printf("\033[;32m%7.2lf\033[0m",average[0][1]); cout<<"↑ |"<<endl;
  }
  else if(af[0]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[0][1]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[0][1]); cout<<"  |"<<endl;
  }
  //Copper
  if(pf[1]==1){
  cout<<"| Copper        | "; printf("\033[;32m%7.2lf\033[0m",price[1][0]); cout<<"↑ | "; 
  }
  else if(pf[1]==-1){
  cout<<"| Copper        | "; printf("\033[;31m%7.2lf\033[0m",price[1][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Copper        | "; printf("\033[;34m%7.2lf\033[0m",price[1][0]); cout<<"  | "; 
  }
  if(af[1]==1){
   printf("\033[;32m%7.2lf\033[0m",average[1][0]); cout<<"↑ |"<<endl;
  }
  else if(af[1]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[1][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[1][0]); cout<<"  |"<<endl;
  }
  //Gold
  if(pf[2]==1){
  cout<<"| Gold          | "; printf("\033[;32m%7.2lf\033[0m",price[2][0]); cout<<"↑ | "; 
  }
  else if(pf[2]==-1){
  cout<<"| Gold          | "; printf("\033[;31m%7.2lf\033[0m",price[2][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Gold          | "; printf("\033[;34m%7.2lf\033[0m",price[2][0]); cout<<"  | "; 
  }
  if(af[2]==1){
   printf("\033[;32m%7.2lf\033[0m",average[2][0]); cout<<"↑ |"<<endl;
  }
  else if(af[2]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[2][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[2][0]); cout<<"  |"<<endl;
  }

  //Silver
  if(pf[3]==1){
  cout<<"| Silver        | "; printf("\033[;32m%7.2lf\033[0m",price[3][0]); cout<<"↑ | "; 
  }
  else if(pf[3]==-1){
  cout<<"| Silver        | "; printf("\033[;31m%7.2lf\033[0m",price[3][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Silver        | "; printf("\033[;34m%7.2lf\033[0m",price[3][0]); cout<<"  | "; 
  }
  if(af[3]==1){
   printf("\033[;32m%7.2lf\033[0m",average[3][0]); cout<<"↑ |"<<endl;
  }
  else if(af[3]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[3][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[3][0]); cout<<"  |"<<endl;
  }
  
  //Zinc
  if(pf[4]==1){
  cout<<"| Zinc          | "; printf("\033[;32m%7.2lf\033[0m",price[4][0]); cout<<"↑ | "; 
  }
  else if(pf[4]==-1){
  cout<<"| Zinc          | "; printf("\033[;31m%7.2lf\033[0m",price[4][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Zinc          | "; printf("\033[;34m%7.2lf\033[0m",price[4][0]); cout<<"  | "; 
  }
  if(af[4]==1){
   printf("\033[;32m%7.2lf\033[0m",average[4][0]); cout<<"↑ |"<<endl;
  }
  else if(af[4]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[4][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[4][0]); cout<<"  |"<<endl;
  } 

  //Crudeoil
  if(pf[5]==1){
  cout<<"| Crudeoil      | "; printf("\033[;32m%7.2lf\033[0m",price[5][0]); cout<<"↑ | "; 
  }
  else if(pf[5]==-1){
  cout<<"| Crudeoil      | "; printf("\033[;31m%7.2lf\033[0m",price[5][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Crudeoil      | "; printf("\033[;34m%7.2lf\033[0m",price[5][0]); cout<<"  | "; 
  }
  if(af[5]==1){
   printf("\033[;32m%7.2lf\033[0m",average[5][0]); cout<<"↑ |"<<endl;
  }
  else if(af[5]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[5][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[5][0]); cout<<"  |"<<endl;
  } 

   //Naturalgas
  if(pf[6]==1){
  cout<<"| Naturalgas    | "; printf("\033[;32m%7.2lf\033[0m",price[6][0]); cout<<"↑ | "; 
  }
  else if(pf[6]==-1){
  cout<<"| Naturalgas    | "; printf("\033[;31m%7.2lf\033[0m",price[6][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Naturalgas    | "; printf("\033[;34m%7.2lf\033[0m",price[6][0]); cout<<"  | "; 
  }
  if(af[6]==1){
   printf("\033[;32m%7.2lf\033[0m",average[6][0]); cout<<"↑ |"<<endl;
  }
  else if(af[6]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[6][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[6][0]); cout<<"  |"<<endl;
  } 

  //Nickel
  if(pf[7]==1){
  cout<<"| Nickel        | "; printf("\033[;32m%7.2lf\033[0m",price[7][0]); cout<<"↑ | "; 
  }
  else if(pf[7]==-1){
  cout<<"| Nickel        | "; printf("\033[;31m%7.2lf\033[0m",price[7][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Nickel        | "; printf("\033[;34m%7.2lf\033[0m",price[7][0]); cout<<"  | "; 
  }
  if(af[7]==1){
   printf("\033[;32m%7.2lf\033[0m",average[7][0]); cout<<"↑ |"<<endl;
  }
  else if(af[7]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[7][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[7][0]); cout<<"  |"<<endl;
  } 
  
  //Lead
  if(pf[8]==1){
  cout<<"| Lead          | "; printf("\033[;32m%7.2lf\033[0m",price[8][0]); cout<<"↑ | "; 
  }
  else if(pf[8]==-1){
  cout<<"| Lead          | "; printf("\033[;31m%7.2lf\033[0m",price[8][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Lead          | "; printf("\033[;34m%7.2lf\033[0m",price[8][0]); cout<<"  | "; 
  }
  if(af[8]==1){
   printf("\033[;32m%7.2lf\033[0m",average[8][0]); cout<<"↑ |"<<endl;
  }
  else if(af[8]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[8][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[8][0]); cout<<"  |"<<endl;
  } 

  //Menthaoil
  if(pf[9]==1){
  cout<<"| Menthaoil     | "; printf("\033[;32m%7.2lf\033[0m",price[9][0]); cout<<"↑ | "; 
  }
  else if(pf[9]==-1){
  cout<<"| Menthaoil     | "; printf("\033[;31m%7.2lf\033[0m",price[9][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Menthaoil     | "; printf("\033[;34m%7.2lf\033[0m",price[9][0]); cout<<"  | "; 
  }
  if(af[9]==1){
   printf("\033[;32m%7.2lf\033[0m",average[9][0]); cout<<"↑ |"<<endl;
  }
  else if(af[9]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[9][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[9][0]); cout<<"  |"<<endl;
  } 

  //Cotton
    if(pf[10]==1){
  cout<<"| Cotton        | "; printf("\033[;32m%7.2lf\033[0m",price[10][0]); cout<<"↑ | "; 
  }
  else if(pf[10]==-1){
  cout<<"| Cotton        | "; printf("\033[;31m%7.2lf\033[0m",price[10][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Cotton        | "; printf("\033[;34m%7.2lf\033[0m",price[10][0]); cout<<"  | "; 
  }
  if(af[10]==1){
   printf("\033[;32m%7.2lf\033[0m",average[10][0]); cout<<"↑ |"<<endl;
  }
  else if(af[10]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[10][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[10][0]); cout<<"  |"<<endl;
  } 

  cout<<"+-------------------------------------+"<<endl;
  
   }
   
   
   
   else if(name=="Copper"){
    cout<<"+-------------------------------------+"<<endl;
  cout<<"| Currency      |  Price   | AvgPrice |"<<endl;
  cout<<"+-------------------------------------+"<<endl;
  if(pf[0]==1){
  cout<<"| Aluminum      | "; printf("\033[;32m%7.2lf\033[0m",price[0][0]); cout<<"↑ | "; 
  }
  else if(pf[0]==-1){
  cout<<"| Aluminum      | "; printf("\033[;31m%7.2lf\033[0m",price[0][0]); cout<<"↓ | "; 
  }
  else{
    cout<<"| Aluminum      | "; printf("\033[;34m%7.2lf\033[0m",price[0][0]); cout<<"  | "; 
  }
  if(af[0]==1){
   printf("\033[;32m%7.2lf\033[0m",average[0][0]); cout<<"↑ |"<<endl;
  }
  else if(af[0]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[0][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[0][0]); cout<<"  |"<<endl;
  }
  //Copper
  if(pf[1]==1){
  cout<<"| Copper        | "; printf("\033[;32m%7.2lf\033[0m",price[1][1]); cout<<"↑ | "; 
  }
  else if(pf[1]==-1){
  cout<<"| Copper        | "; printf("\033[;31m%7.2lf\033[0m",price[1][1]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Copper        | "; printf("\033[;34m%7.2lf\033[0m",price[1][1]); cout<<"  | "; 
  }
  if(af[1]==1){
   printf("\033[;32m%7.2lf\033[0m",average[1][1]); cout<<"↑ |"<<endl;
  }
  else if(af[1]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[1][1]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[1][1]); cout<<"  |"<<endl;
  }
  //Gold
  if(pf[2]==1){
  cout<<"| Gold          | "; printf("\033[;32m%7.2lf\033[0m",price[2][0]); cout<<"↑ | "; 
  }
  else if(pf[2]==-1){
  cout<<"| Gold          | "; printf("\033[;31m%7.2lf\033[0m",price[2][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Gold          | "; printf("\033[;34m%7.2lf\033[0m",price[2][0]); cout<<"  | "; 
  }
  if(af[2]==1){
   printf("\033[;32m%7.2lf\033[0m",average[2][0]); cout<<"↑ |"<<endl;
  }
  else if(af[2]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[2][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[2][0]); cout<<"  |"<<endl;
  }

  //Silver
  if(pf[3]==1){
  cout<<"| Silver        | "; printf("\033[;32m%7.2lf\033[0m",price[3][0]); cout<<"↑ | "; 
  }
  else if(pf[3]==-1){
  cout<<"| Silver        | "; printf("\033[;31m%7.2lf\033[0m",price[3][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Silver        | "; printf("\033[;34m%7.2lf\033[0m",price[3][0]); cout<<"  | "; 
  }
  if(af[3]==1){
   printf("\033[;32m%7.2lf\033[0m",average[3][0]); cout<<"↑ |"<<endl;
  }
  else if(af[3]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[3][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[3][0]); cout<<"  |"<<endl;
  }
  
  //Zinc
  if(pf[4]==1){
  cout<<"| Zinc          | "; printf("\033[;32m%7.2lf\033[0m",price[4][0]); cout<<"↑ | "; 
  }
  else if(pf[4]==-1){
  cout<<"| Zinc          | "; printf("\033[;31m%7.2lf\033[0m",price[4][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Zinc          | "; printf("\033[;34m%7.2lf\033[0m",price[4][0]); cout<<"  | "; 
  }
  if(af[4]==1){
   printf("\033[;32m%7.2lf\033[0m",average[4][0]); cout<<"↑ |"<<endl;
  }
  else if(af[4]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[4][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[4][0]); cout<<"  |"<<endl;
  } 

  //Crudeoil
  if(pf[5]==1){
  cout<<"| Crudeoil      | "; printf("\033[;32m%7.2lf\033[0m",price[5][0]); cout<<"↑ | "; 
  }
  else if(pf[5]==-1){
  cout<<"| Crudeoil      | "; printf("\033[;31m%7.2lf\033[0m",price[5][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Crudeoil      | "; printf("\033[;34m%7.2lf\033[0m",price[5][0]); cout<<"  | "; 
  }
  if(af[5]==1){
   printf("\033[;32m%7.2lf\033[0m",average[5][0]); cout<<"↑ |"<<endl;
  }
  else if(af[5]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[5][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[5][0]); cout<<"  |"<<endl;
  } 

   //Naturalgas
  if(pf[6]==1){
  cout<<"| Naturalgas    | "; printf("\033[;32m%7.2lf\033[0m",price[6][0]); cout<<"↑ | "; 
  }
  else if(pf[6]==-1){
  cout<<"| Naturalgas    | "; printf("\033[;31m%7.2lf\033[0m",price[6][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Naturalgas    | "; printf("\033[;34m%7.2lf\033[0m",price[6][0]); cout<<"  | "; 
  }
  if(af[6]==1){
   printf("\033[;32m%7.2lf\033[0m",average[6][0]); cout<<"↑ |"<<endl;
  }
  else if(af[6]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[6][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[6][0]); cout<<"  |"<<endl;
  } 

  //Nickel
  if(pf[7]==1){
  cout<<"| Nickel        | "; printf("\033[;32m%7.2lf\033[0m",price[7][0]); cout<<"↑ | "; 
  }
  else if(pf[7]==-1){
  cout<<"| Nickel        | "; printf("\033[;31m%7.2lf\033[0m",price[7][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Nickel        | "; printf("\033[;34m%7.2lf\033[0m",price[7][0]); cout<<"  | "; 
  }
  if(af[7]==1){
   printf("\033[;32m%7.2lf\033[0m",average[7][0]); cout<<"↑ |"<<endl;
  }
  else if(af[7]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[7][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[7][0]); cout<<"  |"<<endl;
  } 
  
  //Lead
  if(pf[8]==1){
  cout<<"| Lead          | "; printf("\033[;32m%7.2lf\033[0m",price[8][0]); cout<<"↑ | "; 
  }
  else if(pf[8]==-1){
  cout<<"| Lead          | "; printf("\033[;31m%7.2lf\033[0m",price[8][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Lead          | "; printf("\033[;34m%7.2lf\033[0m",price[8][0]); cout<<"  | "; 
  }
  if(af[8]==1){
   printf("\033[;32m%7.2lf\033[0m",average[8][0]); cout<<"↑ |"<<endl;
  }
  else if(af[8]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[8][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[8][0]); cout<<"  |"<<endl;
  } 

  //Menthaoil
  if(pf[9]==1){
  cout<<"| Menthaoil     | "; printf("\033[;32m%7.2lf\033[0m",price[9][0]); cout<<"↑ | "; 
  }
  else if(pf[9]==-1){
  cout<<"| Menthaoil     | "; printf("\033[;31m%7.2lf\033[0m",price[9][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Menthaoil     | "; printf("\033[;34m%7.2lf\033[0m",price[9][0]); cout<<"  | "; 
  }
  if(af[9]==1){
   printf("\033[;32m%7.2lf\033[0m",average[9][0]); cout<<"↑ |"<<endl;
  }
  else if(af[9]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[9][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[9][0]); cout<<"  |"<<endl;
  } 

  //Cotton
    if(pf[10]==1){
  cout<<"| Cotton        | "; printf("\033[;32m%7.2lf\033[0m",price[10][0]); cout<<"↑ | "; 
  }
  else if(pf[10]==-1){
  cout<<"| Cotton        | "; printf("\033[;31m%7.2lf\033[0m",price[10][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Cotton        | "; printf("\033[;34m%7.2lf\033[0m",price[10][0]); cout<<"  | "; 
  }
  if(af[10]==1){
   printf("\033[;32m%7.2lf\033[0m",average[10][0]); cout<<"↑ |"<<endl;
  }
  else if(af[10]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[10][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[10][0]); cout<<"  |"<<endl;
  } 

  cout<<"+-------------------------------------+"<<endl;
  
  
   }
  
   else if(name=="Gold"){
       cout<<"+-------------------------------------+"<<endl;
  cout<<"| Currency      |  Price   | AvgPrice |"<<endl;
  cout<<"+-------------------------------------+"<<endl;
  if(pf[0]==1){
  cout<<"| Aluminum      | "; printf("\033[;32m%7.2lf\033[0m",price[0][0]); cout<<"↑ | "; 
  }
  else if(pf[0]==-1){
  cout<<"| Aluminum      | "; printf("\033[;31m%7.2lf\033[0m",price[0][0]); cout<<"↓ | "; 
  }
  else{
    cout<<"| Aluminum      | "; printf("\033[;34m%7.2lf\033[0m",price[0][0]); cout<<"  | "; 
  }
  if(af[0]==1){
   printf("\033[;32m%7.2lf\033[0m",average[0][0]); cout<<"↑ |"<<endl;
  }
  else if(af[0]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[0][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[0][0]); cout<<"  |"<<endl;
  }
  //Copper
  if(pf[1]==1){
  cout<<"| Copper        | "; printf("\033[;32m%7.2lf\033[0m",price[1][0]); cout<<"↑ | "; 
  }
  else if(pf[1]==-1){
  cout<<"| Copper        | "; printf("\033[;31m%7.2lf\033[0m",price[1][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Copper        | "; printf("\033[;34m%7.2lf\033[0m",price[1][0]); cout<<"  | "; 
  }
  if(af[1]==1){
   printf("\033[;32m%7.2lf\033[0m",average[1][0]); cout<<"↑ |"<<endl;
  }
  else if(af[1]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[1][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[1][0]); cout<<"  |"<<endl;
  }
  //Gold
  if(pf[2]==1){
  cout<<"| Gold          | "; printf("\033[;32m%7.2lf\033[0m",price[2][1]); cout<<"↑ | "; 
  }
  else if(pf[2]==-1){
  cout<<"| Gold          | "; printf("\033[;31m%7.2lf\033[0m",price[2][1]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Gold          | "; printf("\033[;34m%7.2lf\033[0m",price[2][1]); cout<<"  | "; 
  }
  if(af[2]==1){
   printf("\033[;32m%7.2lf\033[0m",average[2][1]); cout<<"↑ |"<<endl;
  }
  else if(af[2]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[2][1]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[2][1]); cout<<"  |"<<endl;
  }

  //Silver
  if(pf[3]==1){
  cout<<"| Silver        | "; printf("\033[;32m%7.2lf\033[0m",price[3][0]); cout<<"↑ | "; 
  }
  else if(pf[3]==-1){
  cout<<"| Silver        | "; printf("\033[;31m%7.2lf\033[0m",price[3][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Silver        | "; printf("\033[;34m%7.2lf\033[0m",price[3][0]); cout<<"  | "; 
  }
  if(af[3]==1){
   printf("\033[;32m%7.2lf\033[0m",average[3][0]); cout<<"↑ |"<<endl;
  }
  else if(af[3]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[3][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[3][0]); cout<<"  |"<<endl;
  }
  
  //Zinc
  if(pf[4]==1){
  cout<<"| Zinc          | "; printf("\033[;32m%7.2lf\033[0m",price[4][0]); cout<<"↑ | "; 
  }
  else if(pf[4]==-1){
  cout<<"| Zinc          | "; printf("\033[;31m%7.2lf\033[0m",price[4][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Zinc          | "; printf("\033[;34m%7.2lf\033[0m",price[4][0]); cout<<"  | "; 
  }
  if(af[4]==1){
   printf("\033[;32m%7.2lf\033[0m",average[4][0]); cout<<"↑ |"<<endl;
  }
  else if(af[4]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[4][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[4][0]); cout<<"  |"<<endl;
  } 

  //Crudeoil
  if(pf[5]==1){
  cout<<"| Crudeoil      | "; printf("\033[;32m%7.2lf\033[0m",price[5][0]); cout<<"↑ | "; 
  }
  else if(pf[5]==-1){
  cout<<"| Crudeoil      | "; printf("\033[;31m%7.2lf\033[0m",price[5][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Crudeoil      | "; printf("\033[;34m%7.2lf\033[0m",price[5][0]); cout<<"  | "; 
  }
  if(af[5]==1){
   printf("\033[;32m%7.2lf\033[0m",average[5][0]); cout<<"↑ |"<<endl;
  }
  else if(af[5]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[5][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[5][0]); cout<<"  |"<<endl;
  } 

   //Naturalgas
  if(pf[6]==1){
  cout<<"| Naturalgas    | "; printf("\033[;32m%7.2lf\033[0m",price[6][0]); cout<<"↑ | "; 
  }
  else if(pf[6]==-1){
  cout<<"| Naturalgas    | "; printf("\033[;31m%7.2lf\033[0m",price[6][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Naturalgas    | "; printf("\033[;34m%7.2lf\033[0m",price[6][0]); cout<<"  | "; 
  }
  if(af[6]==1){
   printf("\033[;32m%7.2lf\033[0m",average[6][0]); cout<<"↑ |"<<endl;
  }
  else if(af[6]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[6][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[6][0]); cout<<"  |"<<endl;
  } 

  //Nickel
  if(pf[7]==1){
  cout<<"| Nickel        | "; printf("\033[;32m%7.2lf\033[0m",price[7][0]); cout<<"↑ | "; 
  }
  else if(pf[7]==-1){
  cout<<"| Nickel        | "; printf("\033[;31m%7.2lf\033[0m",price[7][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Nickel        | "; printf("\033[;34m%7.2lf\033[0m",price[7][0]); cout<<"  | "; 
  }
  if(af[7]==1){
   printf("\033[;32m%7.2lf\033[0m",average[7][0]); cout<<"↑ |"<<endl;
  }
  else if(af[7]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[7][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[7][0]); cout<<"  |"<<endl;
  } 
  
  //Lead
  if(pf[8]==1){
  cout<<"| Lead          | "; printf("\033[;32m%7.2lf\033[0m",price[8][0]); cout<<"↑ | "; 
  }
  else if(pf[8]==-1){
  cout<<"| Lead          | "; printf("\033[;31m%7.2lf\033[0m",price[8][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Lead          | "; printf("\033[;34m%7.2lf\033[0m",price[8][0]); cout<<"  | "; 
  }
  if(af[8]==1){
   printf("\033[;32m%7.2lf\033[0m",average[8][0]); cout<<"↑ |"<<endl;
  }
  else if(af[8]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[8][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[8][0]); cout<<"  |"<<endl;
  } 

  //Menthaoil
  if(pf[9]==1){
  cout<<"| Menthaoil     | "; printf("\033[;32m%7.2lf\033[0m",price[9][0]); cout<<"↑ | "; 
  }
  else if(pf[9]==-1){
  cout<<"| Menthaoil     | "; printf("\033[;31m%7.2lf\033[0m",price[9][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Menthaoil     | "; printf("\033[;34m%7.2lf\033[0m",price[9][0]); cout<<"  | "; 
  }
  if(af[9]==1){
   printf("\033[;32m%7.2lf\033[0m",average[9][0]); cout<<"↑ |"<<endl;
  }
  else if(af[9]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[9][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[9][0]); cout<<"  |"<<endl;
  } 

  //Cotton
    if(pf[10]==1){
  cout<<"| Cotton        | "; printf("\033[;32m%7.2lf\033[0m",price[10][0]); cout<<"↑ | "; 
  }
  else if(pf[10]==-1){
  cout<<"| Cotton        | "; printf("\033[;31m%7.2lf\033[0m",price[10][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Cotton        | "; printf("\033[;34m%7.2lf\033[0m",price[10][0]); cout<<"  | "; 
  }
  if(af[10]==1){
   printf("\033[;32m%7.2lf\033[0m",average[10][0]); cout<<"↑ |"<<endl;
  }
  else if(af[10]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[10][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[10][0]); cout<<"  |"<<endl;
  } 

  cout<<"+-------------------------------------+"<<endl;
  
   }
  
  
  else if(name=="Silver"){
     cout<<"+-------------------------------------+"<<endl;
  cout<<"| Currency      |  Price   | AvgPrice |"<<endl;
  cout<<"+-------------------------------------+"<<endl;
  if(pf[0]==1){
  cout<<"| Aluminum      | "; printf("\033[;32m%7.2lf\033[0m",price[0][0]); cout<<"↑ | "; 
  }
  else if(pf[0]==-1){
  cout<<"| Aluminum      | "; printf("\033[;31m%7.2lf\033[0m",price[0][0]); cout<<"↓ | "; 
  }
  else{
    cout<<"| Aluminum      | "; printf("\033[;34m%7.2lf\033[0m",price[0][0]); cout<<"  | "; 
  }
  if(af[0]==1){
   printf("\033[;32m%7.2lf\033[0m",average[0][0]); cout<<"↑ |"<<endl;
  }
  else if(af[0]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[0][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[0][0]); cout<<"  |"<<endl;
  }
  //Copper
  if(pf[1]==1){
  cout<<"| Copper        | "; printf("\033[;32m%7.2lf\033[0m",price[1][0]); cout<<"↑ | "; 
  }
  else if(pf[1]==-1){
  cout<<"| Copper        | "; printf("\033[;31m%7.2lf\033[0m",price[1][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Copper        | "; printf("\033[;34m%7.2lf\033[0m",price[1][0]); cout<<"  | "; 
  }
  if(af[1]==1){
   printf("\033[;32m%7.2lf\033[0m",average[1][0]); cout<<"↑ |"<<endl;
  }
  else if(af[1]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[1][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[1][0]); cout<<"  |"<<endl;
  }
  //Gold
  if(pf[2]==1){
  cout<<"| Gold          | "; printf("\033[;32m%7.2lf\033[0m",price[2][0]); cout<<"↑ | "; 
  }
  else if(pf[2]==-1){
  cout<<"| Gold          | "; printf("\033[;31m%7.2lf\033[0m",price[2][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Gold          | "; printf("\033[;34m%7.2lf\033[0m",price[2][0]); cout<<"  | "; 
  }
  if(af[2]==1){
   printf("\033[;32m%7.2lf\033[0m",average[2][0]); cout<<"↑ |"<<endl;
  }
  else if(af[2]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[2][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[2][0]); cout<<"  |"<<endl;
  }

  //Silver
  if(pf[3]==1){
  cout<<"| Silver        | "; printf("\033[;32m%7.2lf\033[0m",price[3][1]); cout<<"↑ | "; 
  }
  else if(pf[3]==-1){
  cout<<"| Silver        | "; printf("\033[;31m%7.2lf\033[0m",price[3][1]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Silver        | "; printf("\033[;34m%7.2lf\033[0m",price[3][1]); cout<<"  | "; 
  }
  if(af[3]==1){
   printf("\033[;32m%7.2lf\033[0m",average[3][1]); cout<<"↑ |"<<endl;
  }
  else if(af[3]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[3][1]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[3][1]); cout<<"  |"<<endl;
  }
  
  //Zinc
  if(pf[4]==1){
  cout<<"| Zinc          | "; printf("\033[;32m%7.2lf\033[0m",price[4][0]); cout<<"↑ | "; 
  }
  else if(pf[4]==-1){
  cout<<"| Zinc          | "; printf("\033[;31m%7.2lf\033[0m",price[4][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Zinc          | "; printf("\033[;34m%7.2lf\033[0m",price[4][0]); cout<<"  | "; 
  }
  if(af[4]==1){
   printf("\033[;32m%7.2lf\033[0m",average[4][0]); cout<<"↑ |"<<endl;
  }
  else if(af[4]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[4][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[4][0]); cout<<"  |"<<endl;
  } 

  //Crudeoil
  if(pf[5]==1){
  cout<<"| Crudeoil      | "; printf("\033[;32m%7.2lf\033[0m",price[5][0]); cout<<"↑ | "; 
  }
  else if(pf[5]==-1){
  cout<<"| Crudeoil      | "; printf("\033[;31m%7.2lf\033[0m",price[5][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Crudeoil      | "; printf("\033[;34m%7.2lf\033[0m",price[5][0]); cout<<"  | "; 
  }
  if(af[5]==1){
   printf("\033[;32m%7.2lf\033[0m",average[5][0]); cout<<"↑ |"<<endl;
  }
  else if(af[5]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[5][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[5][0]); cout<<"  |"<<endl;
  } 

   //Naturalgas
  if(pf[6]==1){
  cout<<"| Naturalgas    | "; printf("\033[;32m%7.2lf\033[0m",price[6][0]); cout<<"↑ | "; 
  }
  else if(pf[6]==-1){
  cout<<"| Naturalgas    | "; printf("\033[;31m%7.2lf\033[0m",price[6][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Naturalgas    | "; printf("\033[;34m%7.2lf\033[0m",price[6][0]); cout<<"  | "; 
  }
  if(af[6]==1){
   printf("\033[;32m%7.2lf\033[0m",average[6][0]); cout<<"↑ |"<<endl;
  }
  else if(af[6]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[6][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[6][0]); cout<<"  |"<<endl;
  } 

  //Nickel
  if(pf[7]==1){
  cout<<"| Nickel        | "; printf("\033[;32m%7.2lf\033[0m",price[7][0]); cout<<"↑ | "; 
  }
  else if(pf[7]==-1){
  cout<<"| Nickel        | "; printf("\033[;31m%7.2lf\033[0m",price[7][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Nickel        | "; printf("\033[;34m%7.2lf\033[0m",price[7][0]); cout<<"  | "; 
  }
  if(af[7]==1){
   printf("\033[;32m%7.2lf\033[0m",average[7][0]); cout<<"↑ |"<<endl;
  }
  else if(af[7]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[7][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[7][0]); cout<<"  |"<<endl;
  } 
  
  //Lead
  if(pf[8]==1){
  cout<<"| Lead          | "; printf("\033[;32m%7.2lf\033[0m",price[8][0]); cout<<"↑ | "; 
  }
  else if(pf[8]==-1){
  cout<<"| Lead          | "; printf("\033[;31m%7.2lf\033[0m",price[8][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Lead          | "; printf("\033[;34m%7.2lf\033[0m",price[8][0]); cout<<"  | "; 
  }
  if(af[8]==1){
   printf("\033[;32m%7.2lf\033[0m",average[8][0]); cout<<"↑ |"<<endl;
  }
  else if(af[8]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[8][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[8][0]); cout<<"  |"<<endl;
  } 

  //Menthaoil
  if(pf[9]==1){
  cout<<"| Menthaoil     | "; printf("\033[;32m%7.2lf\033[0m",price[9][0]); cout<<"↑ | "; 
  }
  else if(pf[9]==-1){
  cout<<"| Menthaoil     | "; printf("\033[;31m%7.2lf\033[0m",price[9][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Menthaoil     | "; printf("\033[;34m%7.2lf\033[0m",price[9][0]); cout<<"  | "; 
  }
  if(af[9]==1){
   printf("\033[;32m%7.2lf\033[0m",average[9][0]); cout<<"↑ |"<<endl;
  }
  else if(af[9]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[9][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[9][0]); cout<<"  |"<<endl;
  } 

  //Cotton
    if(pf[10]==1){
  cout<<"| Cotton        | "; printf("\033[;32m%7.2lf\033[0m",price[10][0]); cout<<"↑ | "; 
  }
  else if(pf[10]==-1){
  cout<<"| Cotton        | "; printf("\033[;31m%7.2lf\033[0m",price[10][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Cotton        | "; printf("\033[;34m%7.2lf\033[0m",price[10][0]); cout<<"  | "; 
  }
  if(af[10]==1){
   printf("\033[;32m%7.2lf\033[0m",average[10][0]); cout<<"↑ |"<<endl;
  }
  else if(af[10]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[10][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[10][0]); cout<<"  |"<<endl;
  } 

  cout<<"+-------------------------------------+"<<endl;
   }

   else if(name=="Zinc"){
   cout<<"+-------------------------------------+"<<endl;
  cout<<"| Currency      |  Price   | AvgPrice |"<<endl;
  cout<<"+-------------------------------------+"<<endl;
  if(pf[0]==1){
  cout<<"| Aluminum      | "; printf("\033[;32m%7.2lf\033[0m",price[0][0]); cout<<"↑ | "; 
  }
  else if(pf[0]==-1){
  cout<<"| Aluminum      | "; printf("\033[;31m%7.2lf\033[0m",price[0][0]); cout<<"↓ | "; 
  }
  else{
    cout<<"| Aluminum      | "; printf("\033[;34m%7.2lf\033[0m",price[0][0]); cout<<"  | "; 
  }
  if(af[0]==1){
   printf("\033[;32m%7.2lf\033[0m",average[0][0]); cout<<"↑ |"<<endl;
  }
  else if(af[0]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[0][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[0][0]); cout<<"  |"<<endl;
  }
  //Copper
  if(pf[1]==1){
  cout<<"| Copper        | "; printf("\033[;32m%7.2lf\033[0m",price[1][0]); cout<<"↑ | "; 
  }
  else if(pf[1]==-1){
  cout<<"| Copper        | "; printf("\033[;31m%7.2lf\033[0m",price[1][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Copper        | "; printf("\033[;34m%7.2lf\033[0m",price[1][0]); cout<<"  | "; 
  }
  if(af[1]==1){
   printf("\033[;32m%7.2lf\033[0m",average[1][0]); cout<<"↑ |"<<endl;
  }
  else if(af[1]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[1][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[1][0]); cout<<"  |"<<endl;
  }
  //Gold
  if(pf[2]==1){
  cout<<"| Gold          | "; printf("\033[;32m%7.2lf\033[0m",price[2][0]); cout<<"↑ | "; 
  }
  else if(pf[2]==-1){
  cout<<"| Gold          | "; printf("\033[;31m%7.2lf\033[0m",price[2][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Gold          | "; printf("\033[;34m%7.2lf\033[0m",price[2][0]); cout<<"  | "; 
  }
  if(af[2]==1){
   printf("\033[;32m%7.2lf\033[0m",average[2][0]); cout<<"↑ |"<<endl;
  }
  else if(af[2]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[2][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[2][0]); cout<<"  |"<<endl;
  }

  //Silver
  if(pf[3]==1){
  cout<<"| Silver        | "; printf("\033[;32m%7.2lf\033[0m",price[3][0]); cout<<"↑ | "; 
  }
  else if(pf[3]==-1){
  cout<<"| Silver        | "; printf("\033[;31m%7.2lf\033[0m",price[3][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Silver        | "; printf("\033[;34m%7.2lf\033[0m",price[3][0]); cout<<"  | "; 
  }
  if(af[3]==1){
   printf("\033[;32m%7.2lf\033[0m",average[3][0]); cout<<"↑ |"<<endl;
  }
  else if(af[3]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[3][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[3][0]); cout<<"  |"<<endl;
  }
  
  //Zinc
  if(pf[4]==1){
  cout<<"| Zinc          | "; printf("\033[;32m%7.2lf\033[0m",price[4][1]); cout<<"↑ | "; 
  }
  else if(pf[4]==-1){
  cout<<"| Zinc          | "; printf("\033[;31m%7.2lf\033[0m",price[4][1]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Zinc          | "; printf("\033[;34m%7.2lf\033[0m",price[4][1]); cout<<"  | "; 
  }
  if(af[4]==1){
   printf("\033[;32m%7.2lf\033[0m",average[4][1]); cout<<"↑ |"<<endl;
  }
  else if(af[4]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[4][1]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[4][1]); cout<<"  |"<<endl;
  } 

  //Crudeoil
  if(pf[5]==1){
  cout<<"| Crudeoil      | "; printf("\033[;32m%7.2lf\033[0m",price[5][0]); cout<<"↑ | "; 
  }
  else if(pf[5]==-1){
  cout<<"| Crudeoil      | "; printf("\033[;31m%7.2lf\033[0m",price[5][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Crudeoil      | "; printf("\033[;34m%7.2lf\033[0m",price[5][0]); cout<<"  | "; 
  }
  if(af[5]==1){
   printf("\033[;32m%7.2lf\033[0m",average[5][0]); cout<<"↑ |"<<endl;
  }
  else if(af[5]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[5][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[5][0]); cout<<"  |"<<endl;
  } 

   //Naturalgas
  if(pf[6]==1){
  cout<<"| Naturalgas    | "; printf("\033[;32m%7.2lf\033[0m",price[6][0]); cout<<"↑ | "; 
  }
  else if(pf[6]==-1){
  cout<<"| Naturalgas    | "; printf("\033[;31m%7.2lf\033[0m",price[6][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Naturalgas    | "; printf("\033[;34m%7.2lf\033[0m",price[6][0]); cout<<"  | "; 
  }
  if(af[6]==1){
   printf("\033[;32m%7.2lf\033[0m",average[6][0]); cout<<"↑ |"<<endl;
  }
  else if(af[6]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[6][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[6][0]); cout<<"  |"<<endl;
  } 

  //Nickel
  if(pf[7]==1){
  cout<<"| Nickel        | "; printf("\033[;32m%7.2lf\033[0m",price[7][0]); cout<<"↑ | "; 
  }
  else if(pf[7]==-1){
  cout<<"| Nickel        | "; printf("\033[;31m%7.2lf\033[0m",price[7][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Nickel        | "; printf("\033[;34m%7.2lf\033[0m",price[7][0]); cout<<"  | "; 
  }
  if(af[7]==1){
   printf("\033[;32m%7.2lf\033[0m",average[7][0]); cout<<"↑ |"<<endl;
  }
  else if(af[7]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[7][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[7][0]); cout<<"  |"<<endl;
  } 
  
  //Lead
  if(pf[8]==1){
  cout<<"| Lead          | "; printf("\033[;32m%7.2lf\033[0m",price[8][0]); cout<<"↑ | "; 
  }
  else if(pf[8]==-1){
  cout<<"| Lead          | "; printf("\033[;31m%7.2lf\033[0m",price[8][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Lead          | "; printf("\033[;34m%7.2lf\033[0m",price[8][0]); cout<<"  | "; 
  }
  if(af[8]==1){
   printf("\033[;32m%7.2lf\033[0m",average[8][0]); cout<<"↑ |"<<endl;
  }
  else if(af[8]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[8][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[8][0]); cout<<"  |"<<endl;
  } 

  //Menthaoil
  if(pf[9]==1){
  cout<<"| Menthaoil     | "; printf("\033[;32m%7.2lf\033[0m",price[9][0]); cout<<"↑ | "; 
  }
  else if(pf[9]==-1){
  cout<<"| Menthaoil     | "; printf("\033[;31m%7.2lf\033[0m",price[9][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Menthaoil     | "; printf("\033[;34m%7.2lf\033[0m",price[9][0]); cout<<"  | "; 
  }
  if(af[9]==1){
   printf("\033[;32m%7.2lf\033[0m",average[9][0]); cout<<"↑ |"<<endl;
  }
  else if(af[9]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[9][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[9][0]); cout<<"  |"<<endl;
  } 

  //Cotton
    if(pf[10]==1){
  cout<<"| Cotton        | "; printf("\033[;32m%7.2lf\033[0m",price[10][0]); cout<<"↑ | "; 
  }
  else if(pf[10]==-1){
  cout<<"| Cotton        | "; printf("\033[;31m%7.2lf\033[0m",price[10][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Cotton        | "; printf("\033[;34m%7.2lf\033[0m",price[10][0]); cout<<"  | "; 
  }
  if(af[10]==1){
   printf("\033[;32m%7.2lf\033[0m",average[10][0]); cout<<"↑ |"<<endl;
  }
  else if(af[10]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[10][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[10][0]); cout<<"  |"<<endl;
  } 

  cout<<"+-------------------------------------+"<<endl; 
   }

  else if(name=="Crudeoil"){
    cout<<"+-------------------------------------+"<<endl;
  cout<<"| Currency      |  Price   | AvgPrice |"<<endl;
  cout<<"+-------------------------------------+"<<endl;
  if(pf[0]==1){
  cout<<"| Aluminum      | "; printf("\033[;32m%7.2lf\033[0m",price[0][0]); cout<<"↑ | "; 
  }
  else if(pf[0]==-1){
  cout<<"| Aluminum      | "; printf("\033[;31m%7.2lf\033[0m",price[0][0]); cout<<"↓ | "; 
  }
  else{
    cout<<"| Aluminum      | "; printf("\033[;34m%7.2lf\033[0m",price[0][0]); cout<<"  | "; 
  }
  if(af[0]==1){
   printf("\033[;32m%7.2lf\033[0m",average[0][0]); cout<<"↑ |"<<endl;
  }
  else if(af[0]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[0][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[0][0]); cout<<"  |"<<endl;
  }
  //Copper
  if(pf[1]==1){
  cout<<"| Copper        | "; printf("\033[;32m%7.2lf\033[0m",price[1][0]); cout<<"↑ | "; 
  }
  else if(pf[1]==-1){
  cout<<"| Copper        | "; printf("\033[;31m%7.2lf\033[0m",price[1][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Copper        | "; printf("\033[;34m%7.2lf\033[0m",price[1][0]); cout<<"  | "; 
  }
  if(af[1]==1){
   printf("\033[;32m%7.2lf\033[0m",average[1][0]); cout<<"↑ |"<<endl;
  }
  else if(af[1]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[1][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[1][0]); cout<<"  |"<<endl;
  }
  //Gold
  if(pf[2]==1){
  cout<<"| Gold          | "; printf("\033[;32m%7.2lf\033[0m",price[2][0]); cout<<"↑ | "; 
  }
  else if(pf[2]==-1){
  cout<<"| Gold          | "; printf("\033[;31m%7.2lf\033[0m",price[2][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Gold          | "; printf("\033[;34m%7.2lf\033[0m",price[2][0]); cout<<"  | "; 
  }
  if(af[2]==1){
   printf("\033[;32m%7.2lf\033[0m",average[2][0]); cout<<"↑ |"<<endl;
  }
  else if(af[2]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[2][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[2][0]); cout<<"  |"<<endl;
  }

  //Silver
  if(pf[3]==1){
  cout<<"| Silver        | "; printf("\033[;32m%7.2lf\033[0m",price[3][0]); cout<<"↑ | "; 
  }
  else if(pf[3]==-1){
  cout<<"| Silver        | "; printf("\033[;31m%7.2lf\033[0m",price[3][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Silver        | "; printf("\033[;34m%7.2lf\033[0m",price[3][0]); cout<<"  | "; 
  }
  if(af[3]==1){
   printf("\033[;32m%7.2lf\033[0m",average[3][0]); cout<<"↑ |"<<endl;
  }
  else if(af[3]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[3][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[3][0]); cout<<"  |"<<endl;
  }
  
  //Zinc
  if(pf[4]==1){
  cout<<"| Zinc          | "; printf("\033[;32m%7.2lf\033[0m",price[4][0]); cout<<"↑ | "; 
  }
  else if(pf[4]==-1){
  cout<<"| Zinc          | "; printf("\033[;31m%7.2lf\033[0m",price[4][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Zinc          | "; printf("\033[;34m%7.2lf\033[0m",price[4][0]); cout<<"  | "; 
  }
  if(af[4]==1){
   printf("\033[;32m%7.2lf\033[0m",average[4][0]); cout<<"↑ |"<<endl;
  }
  else if(af[4]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[4][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[4][0]); cout<<"  |"<<endl;
  } 

  //Crudeoil
  if(pf[5]==1){
  cout<<"| Crudeoil      | "; printf("\033[;32m%7.2lf\033[0m",price[5][1]); cout<<"↑ | "; 
  }
  else if(pf[5]==-1){
  cout<<"| Crudeoil      | "; printf("\033[;31m%7.2lf\033[0m",price[5][1]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Crudeoil      | "; printf("\033[;34m%7.2lf\033[0m",price[5][1]); cout<<"  | "; 
  }
  if(af[5]==1){
   printf("\033[;32m%7.2lf\033[0m",average[5][1]); cout<<"↑ |"<<endl;
  }
  else if(af[5]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[5][1]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[5][1]); cout<<"  |"<<endl;
  } 

   //Naturalgas
  if(pf[6]==1){
  cout<<"| Naturalgas    | "; printf("\033[;32m%7.2lf\033[0m",price[6][0]); cout<<"↑ | "; 
  }
  else if(pf[6]==-1){
  cout<<"| Naturalgas    | "; printf("\033[;31m%7.2lf\033[0m",price[6][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Naturalgas    | "; printf("\033[;34m%7.2lf\033[0m",price[6][0]); cout<<"  | "; 
  }
  if(af[6]==1){
   printf("\033[;32m%7.2lf\033[0m",average[6][0]); cout<<"↑ |"<<endl;
  }
  else if(af[6]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[6][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[6][0]); cout<<"  |"<<endl;
  } 

  //Nickel
  if(pf[7]==1){
  cout<<"| Nickel        | "; printf("\033[;32m%7.2lf\033[0m",price[7][0]); cout<<"↑ | "; 
  }
  else if(pf[7]==-1){
  cout<<"| Nickel        | "; printf("\033[;31m%7.2lf\033[0m",price[7][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Nickel        | "; printf("\033[;34m%7.2lf\033[0m",price[7][0]); cout<<"  | "; 
  }
  if(af[7]==1){
   printf("\033[;32m%7.2lf\033[0m",average[7][0]); cout<<"↑ |"<<endl;
  }
  else if(af[7]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[7][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[7][0]); cout<<"  |"<<endl;
  } 
  
  //Lead
  if(pf[8]==1){
  cout<<"| Lead          | "; printf("\033[;32m%7.2lf\033[0m",price[8][0]); cout<<"↑ | "; 
  }
  else if(pf[8]==-1){
  cout<<"| Lead          | "; printf("\033[;31m%7.2lf\033[0m",price[8][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Lead          | "; printf("\033[;34m%7.2lf\033[0m",price[8][0]); cout<<"  | "; 
  }
  if(af[8]==1){
   printf("\033[;32m%7.2lf\033[0m",average[8][0]); cout<<"↑ |"<<endl;
  }
  else if(af[8]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[8][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[8][0]); cout<<"  |"<<endl;
  } 

  //Menthaoil
  if(pf[9]==1){
  cout<<"| Menthaoil     | "; printf("\033[;32m%7.2lf\033[0m",price[9][0]); cout<<"↑ | "; 
  }
  else if(pf[9]==-1){
  cout<<"| Menthaoil     | "; printf("\033[;31m%7.2lf\033[0m",price[9][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Menthaoil     | "; printf("\033[;34m%7.2lf\033[0m",price[9][0]); cout<<"  | "; 
  }
  if(af[9]==1){
   printf("\033[;32m%7.2lf\033[0m",average[9][0]); cout<<"↑ |"<<endl;
  }
  else if(af[9]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[9][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[9][0]); cout<<"  |"<<endl;
  } 

  //Cotton
    if(pf[10]==1){
  cout<<"| Cotton        | "; printf("\033[;32m%7.2lf\033[0m",price[10][0]); cout<<"↑ | "; 
  }
  else if(pf[10]==-1){
  cout<<"| Cotton        | "; printf("\033[;31m%7.2lf\033[0m",price[10][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Cotton        | "; printf("\033[;34m%7.2lf\033[0m",price[10][0]); cout<<"  | "; 
  }
  if(af[10]==1){
   printf("\033[;32m%7.2lf\033[0m",average[10][0]); cout<<"↑ |"<<endl;
  }
  else if(af[10]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[10][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[10][0]); cout<<"  |"<<endl;
  } 

  cout<<"+-------------------------------------+"<<endl;
  }

  else if(name=="Naturalgas"){
  cout<<"+-------------------------------------+"<<endl;
  cout<<"| Currency      |  Price   | AvgPrice |"<<endl;
  cout<<"+-------------------------------------+"<<endl;
  if(pf[0]==1){
  cout<<"| Aluminum      | "; printf("\033[;32m%7.2lf\033[0m",price[0][0]); cout<<"↑ | "; 
  }
  else if(pf[0]==-1){
  cout<<"| Aluminum      | "; printf("\033[;31m%7.2lf\033[0m",price[0][0]); cout<<"↓ | "; 
  }
  else{
    cout<<"| Aluminum      | "; printf("\033[;34m%7.2lf\033[0m",price[0][0]); cout<<"  | "; 
  }
  if(af[0]==1){
   printf("\033[;32m%7.2lf\033[0m",average[0][0]); cout<<"↑ |"<<endl;
  }
  else if(af[0]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[0][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[0][0]); cout<<"  |"<<endl;
  }
  //Copper
  if(pf[1]==1){
  cout<<"| Copper        | "; printf("\033[;32m%7.2lf\033[0m",price[1][0]); cout<<"↑ | "; 
  }
  else if(pf[1]==-1){
  cout<<"| Copper        | "; printf("\033[;31m%7.2lf\033[0m",price[1][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Copper        | "; printf("\033[;34m%7.2lf\033[0m",price[1][0]); cout<<"  | "; 
  }
  if(af[1]==1){
   printf("\033[;32m%7.2lf\033[0m",average[1][0]); cout<<"↑ |"<<endl;
  }
  else if(af[1]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[1][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[1][0]); cout<<"  |"<<endl;
  }
  //Gold
  if(pf[2]==1){
  cout<<"| Gold          | "; printf("\033[;32m%7.2lf\033[0m",price[2][0]); cout<<"↑ | "; 
  }
  else if(pf[2]==-1){
  cout<<"| Gold          | "; printf("\033[;31m%7.2lf\033[0m",price[2][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Gold          | "; printf("\033[;34m%7.2lf\033[0m",price[2][0]); cout<<"  | "; 
  }
  if(af[2]==1){
   printf("\033[;32m%7.2lf\033[0m",average[2][0]); cout<<"↑ |"<<endl;
  }
  else if(af[2]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[2][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[2][0]); cout<<"  |"<<endl;
  }

  //Silver
  if(pf[3]==1){
  cout<<"| Silver        | "; printf("\033[;32m%7.2lf\033[0m",price[3][0]); cout<<"↑ | "; 
  }
  else if(pf[3]==-1){
  cout<<"| Silver        | "; printf("\033[;31m%7.2lf\033[0m",price[3][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Silver        | "; printf("\033[;34m%7.2lf\033[0m",price[3][0]); cout<<"  | "; 
  }
  if(af[3]==1){
   printf("\033[;32m%7.2lf\033[0m",average[3][0]); cout<<"↑ |"<<endl;
  }
  else if(af[3]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[3][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[3][0]); cout<<"  |"<<endl;
  }
  
  //Zinc
  if(pf[4]==1){
  cout<<"| Zinc          | "; printf("\033[;32m%7.2lf\033[0m",price[4][0]); cout<<"↑ | "; 
  }
  else if(pf[4]==-1){
  cout<<"| Zinc          | "; printf("\033[;31m%7.2lf\033[0m",price[4][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Zinc          | "; printf("\033[;34m%7.2lf\033[0m",price[4][0]); cout<<"  | "; 
  }
  if(af[4]==1){
   printf("\033[;32m%7.2lf\033[0m",average[4][0]); cout<<"↑ |"<<endl;
  }
  else if(af[4]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[4][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[4][0]); cout<<"  |"<<endl;
  } 

  //Crudeoil
  if(pf[5]==1){
  cout<<"| Crudeoil      | "; printf("\033[;32m%7.2lf\033[0m",price[5][0]); cout<<"↑ | "; 
  }
  else if(pf[5]==-1){
  cout<<"| Crudeoil      | "; printf("\033[;31m%7.2lf\033[0m",price[5][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Crudeoil      | "; printf("\033[;34m%7.2lf\033[0m",price[5][0]); cout<<"  | "; 
  }
  if(af[5]==1){
   printf("\033[;32m%7.2lf\033[0m",average[5][0]); cout<<"↑ |"<<endl;
  }
  else if(af[5]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[5][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[5][0]); cout<<"  |"<<endl;
  } 

   //Naturalgas
  if(pf[6]==1){
  cout<<"| Naturalgas    | "; printf("\033[;32m%7.2lf\033[0m",price[6][1]); cout<<"↑ | "; 
  }
  else if(pf[6]==-1){
  cout<<"| Naturalgas    | "; printf("\033[;31m%7.2lf\033[0m",price[6][1]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Naturalgas    | "; printf("\033[;34m%7.2lf\033[0m",price[6][1]); cout<<"  | "; 
  }
  if(af[6]==1){
   printf("\033[;32m%7.2lf\033[0m",average[6][1]); cout<<"↑ |"<<endl;
  }
  else if(af[6]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[6][1]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[6][1]); cout<<"  |"<<endl;
  } 

  //Nickel
  if(pf[7]==1){
  cout<<"| Nickel        | "; printf("\033[;32m%7.2lf\033[0m",price[7][0]); cout<<"↑ | "; 
  }
  else if(pf[7]==-1){
  cout<<"| Nickel        | "; printf("\033[;31m%7.2lf\033[0m",price[7][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Nickel        | "; printf("\033[;34m%7.2lf\033[0m",price[7][0]); cout<<"  | "; 
  }
  if(af[7]==1){
   printf("\033[;32m%7.2lf\033[0m",average[7][0]); cout<<"↑ |"<<endl;
  }
  else if(af[7]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[7][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[7][0]); cout<<"  |"<<endl;
  } 
  
  //Lead
  if(pf[8]==1){
  cout<<"| Lead          | "; printf("\033[;32m%7.2lf\033[0m",price[8][0]); cout<<"↑ | "; 
  }
  else if(pf[8]==-1){
  cout<<"| Lead          | "; printf("\033[;31m%7.2lf\033[0m",price[8][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Lead          | "; printf("\033[;34m%7.2lf\033[0m",price[8][0]); cout<<"  | "; 
  }
  if(af[8]==1){
   printf("\033[;32m%7.2lf\033[0m",average[8][0]); cout<<"↑ |"<<endl;
  }
  else if(af[8]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[8][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[8][0]); cout<<"  |"<<endl;
  } 

  //Menthaoil
  if(pf[9]==1){
  cout<<"| Menthaoil     | "; printf("\033[;32m%7.2lf\033[0m",price[9][0]); cout<<"↑ | "; 
  }
  else if(pf[9]==-1){
  cout<<"| Menthaoil     | "; printf("\033[;31m%7.2lf\033[0m",price[9][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Menthaoil     | "; printf("\033[;34m%7.2lf\033[0m",price[9][0]); cout<<"  | "; 
  }
  if(af[9]==1){
   printf("\033[;32m%7.2lf\033[0m",average[9][0]); cout<<"↑ |"<<endl;
  }
  else if(af[9]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[9][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[9][0]); cout<<"  |"<<endl;
  } 

  //Cotton
    if(pf[10]==1){
  cout<<"| Cotton        | "; printf("\033[;32m%7.2lf\033[0m",price[10][0]); cout<<"↑ | "; 
  }
  else if(pf[10]==-1){
  cout<<"| Cotton        | "; printf("\033[;31m%7.2lf\033[0m",price[10][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Cotton        | "; printf("\033[;34m%7.2lf\033[0m",price[10][0]); cout<<"  | "; 
  }
  if(af[10]==1){
   printf("\033[;32m%7.2lf\033[0m",average[10][0]); cout<<"↑ |"<<endl;
  }
  else if(af[10]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[10][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[10][0]); cout<<"  |"<<endl;
  } 

  cout<<"+-------------------------------------+"<<endl;
  }

   else if(name=="Nickel"){
   cout<<"+-------------------------------------+"<<endl;
  cout<<"| Currency      |  Price   | AvgPrice |"<<endl;
  cout<<"+-------------------------------------+"<<endl;
  if(pf[0]==1){
  cout<<"| Aluminum      | "; printf("\033[;32m%7.2lf\033[0m",price[0][0]); cout<<"↑ | "; 
  }
  else if(pf[0]==-1){
  cout<<"| Aluminum      | "; printf("\033[;31m%7.2lf\033[0m",price[0][0]); cout<<"↓ | "; 
  }
  else{
    cout<<"| Aluminum      | "; printf("\033[;34m%7.2lf\033[0m",price[0][0]); cout<<"  | "; 
  }
  if(af[0]==1){
   printf("\033[;32m%7.2lf\033[0m",average[0][0]); cout<<"↑ |"<<endl;
  }
  else if(af[0]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[0][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[0][0]); cout<<"  |"<<endl;
  }
  //Copper
  if(pf[1]==1){
  cout<<"| Copper        | "; printf("\033[;32m%7.2lf\033[0m",price[1][0]); cout<<"↑ | "; 
  }
  else if(pf[1]==-1){
  cout<<"| Copper        | "; printf("\033[;31m%7.2lf\033[0m",price[1][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Copper        | "; printf("\033[;34m%7.2lf\033[0m",price[1][0]); cout<<"  | "; 
  }
  if(af[1]==1){
   printf("\033[;32m%7.2lf\033[0m",average[1][0]); cout<<"↑ |"<<endl;
  }
  else if(af[1]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[1][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[1][0]); cout<<"  |"<<endl;
  }
  //Gold
  if(pf[2]==1){
  cout<<"| Gold          | "; printf("\033[;32m%7.2lf\033[0m",price[2][0]); cout<<"↑ | "; 
  }
  else if(pf[2]==-1){
  cout<<"| Gold          | "; printf("\033[;31m%7.2lf\033[0m",price[2][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Gold          | "; printf("\033[;34m%7.2lf\033[0m",price[2][0]); cout<<"  | "; 
  }
  if(af[2]==1){
   printf("\033[;32m%7.2lf\033[0m",average[2][0]); cout<<"↑ |"<<endl;
  }
  else if(af[2]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[2][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[2][0]); cout<<"  |"<<endl;
  }

  //Silver
  if(pf[3]==1){
  cout<<"| Silver        | "; printf("\033[;32m%7.2lf\033[0m",price[3][0]); cout<<"↑ | "; 
  }
  else if(pf[3]==-1){
  cout<<"| Silver        | "; printf("\033[;31m%7.2lf\033[0m",price[3][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Silver        | "; printf("\033[;34m%7.2lf\033[0m",price[3][0]); cout<<"  | "; 
  }
  if(af[3]==1){
   printf("\033[;32m%7.2lf\033[0m",average[3][0]); cout<<"↑ |"<<endl;
  }
  else if(af[3]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[3][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[3][0]); cout<<"  |"<<endl;
  }
  
  //Zinc
  if(pf[4]==1){
  cout<<"| Zinc          | "; printf("\033[;32m%7.2lf\033[0m",price[4][0]); cout<<"↑ | "; 
  }
  else if(pf[4]==-1){
  cout<<"| Zinc          | "; printf("\033[;31m%7.2lf\033[0m",price[4][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Zinc          | "; printf("\033[;34m%7.2lf\033[0m",price[4][0]); cout<<"  | "; 
  }
  if(af[4]==1){
   printf("\033[;32m%7.2lf\033[0m",average[4][0]); cout<<"↑ |"<<endl;
  }
  else if(af[4]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[4][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[4][0]); cout<<"  |"<<endl;
  } 

  //Crudeoil
  if(pf[5]==1){
  cout<<"| Crudeoil      | "; printf("\033[;32m%7.2lf\033[0m",price[5][0]); cout<<"↑ | "; 
  }
  else if(pf[5]==-1){
  cout<<"| Crudeoil      | "; printf("\033[;31m%7.2lf\033[0m",price[5][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Crudeoil      | "; printf("\033[;34m%7.2lf\033[0m",price[5][0]); cout<<"  | "; 
  }
  if(af[5]==1){
   printf("\033[;32m%7.2lf\033[0m",average[5][0]); cout<<"↑ |"<<endl;
  }
  else if(af[5]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[5][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[5][0]); cout<<"  |"<<endl;
  } 

   //Naturalgas
  if(pf[6]==1){
  cout<<"| Naturalgas    | "; printf("\033[;32m%7.2lf\033[0m",price[6][0]); cout<<"↑ | "; 
  }
  else if(pf[6]==-1){
  cout<<"| Naturalgas    | "; printf("\033[;31m%7.2lf\033[0m",price[6][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Naturalgas    | "; printf("\033[;34m%7.2lf\033[0m",price[6][0]); cout<<"  | "; 
  }
  if(af[6]==1){
   printf("\033[;32m%7.2lf\033[0m",average[6][0]); cout<<"↑ |"<<endl;
  }
  else if(af[6]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[6][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[6][0]); cout<<"  |"<<endl;
  } 

  //Nickel
  if(pf[7]==1){
  cout<<"| Nickel        | "; printf("\033[;32m%7.2lf\033[0m",price[7][1]); cout<<"↑ | "; 
  }
  else if(pf[7]==-1){
  cout<<"| Nickel        | "; printf("\033[;31m%7.2lf\033[0m",price[7][1]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Nickel        | "; printf("\033[;34m%7.2lf\033[0m",price[7][1]); cout<<"  | "; 
  }
  if(af[7]==1){
   printf("\033[;32m%7.2lf\033[0m",average[7][1]); cout<<"↑ |"<<endl;
  }
  else if(af[7]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[7][1]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[7][1]); cout<<"  |"<<endl;
  } 
  
  //Lead
  if(pf[8]==1){
  cout<<"| Lead          | "; printf("\033[;32m%7.2lf\033[0m",price[8][0]); cout<<"↑ | "; 
  }
  else if(pf[8]==-1){
  cout<<"| Lead          | "; printf("\033[;31m%7.2lf\033[0m",price[8][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Lead          | "; printf("\033[;34m%7.2lf\033[0m",price[8][0]); cout<<"  | "; 
  }
  if(af[8]==1){
   printf("\033[;32m%7.2lf\033[0m",average[8][0]); cout<<"↑ |"<<endl;
  }
  else if(af[8]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[8][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[8][0]); cout<<"  |"<<endl;
  } 

  //Menthaoil
  if(pf[9]==1){
  cout<<"| Menthaoil     | "; printf("\033[;32m%7.2lf\033[0m",price[9][0]); cout<<"↑ | "; 
  }
  else if(pf[9]==-1){
  cout<<"| Menthaoil     | "; printf("\033[;31m%7.2lf\033[0m",price[9][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Menthaoil     | "; printf("\033[;34m%7.2lf\033[0m",price[9][0]); cout<<"  | "; 
  }
  if(af[9]==1){
   printf("\033[;32m%7.2lf\033[0m",average[9][0]); cout<<"↑ |"<<endl;
  }
  else if(af[9]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[9][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[9][0]); cout<<"  |"<<endl;
  } 

  //Cotton
    if(pf[10]==1){
  cout<<"| Cotton        | "; printf("\033[;32m%7.2lf\033[0m",price[10][0]); cout<<"↑ | "; 
  }
  else if(pf[10]==-1){
  cout<<"| Cotton        | "; printf("\033[;31m%7.2lf\033[0m",price[10][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Cotton        | "; printf("\033[;34m%7.2lf\033[0m",price[10][0]); cout<<"  | "; 
  }
  if(af[10]==1){
   printf("\033[;32m%7.2lf\033[0m",average[10][0]); cout<<"↑ |"<<endl;
  }
  else if(af[10]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[10][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[10][0]); cout<<"  |"<<endl;
  } 

  cout<<"+-------------------------------------+"<<endl;
  }


   else if(name=="Lead"){
   cout<<"+-------------------------------------+"<<endl;
  cout<<"| Currency      |  Price   | AvgPrice |"<<endl;
  cout<<"+-------------------------------------+"<<endl;
  if(pf[0]==1){
  cout<<"| Aluminum      | "; printf("\033[;32m%7.2lf\033[0m",price[0][0]); cout<<"↑ | "; 
  }
  else if(pf[0]==-1){
  cout<<"| Aluminum      | "; printf("\033[;31m%7.2lf\033[0m",price[0][0]); cout<<"↓ | "; 
  }
  else{
    cout<<"| Aluminum      | "; printf("\033[;34m%7.2lf\033[0m",price[0][0]); cout<<"  | "; 
  }
  if(af[0]==1){
   printf("\033[;32m%7.2lf\033[0m",average[0][0]); cout<<"↑ |"<<endl;
  }
  else if(af[0]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[0][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[0][0]); cout<<"  |"<<endl;
  }
  //Copper
  if(pf[1]==1){
  cout<<"| Copper        | "; printf("\033[;32m%7.2lf\033[0m",price[1][0]); cout<<"↑ | "; 
  }
  else if(pf[1]==-1){
  cout<<"| Copper        | "; printf("\033[;31m%7.2lf\033[0m",price[1][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Copper        | "; printf("\033[;34m%7.2lf\033[0m",price[1][0]); cout<<"  | "; 
  }
  if(af[1]==1){
   printf("\033[;32m%7.2lf\033[0m",average[1][0]); cout<<"↑ |"<<endl;
  }
  else if(af[1]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[1][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[1][0]); cout<<"  |"<<endl;
  }
  //Gold
  if(pf[2]==1){
  cout<<"| Gold          | "; printf("\033[;32m%7.2lf\033[0m",price[2][0]); cout<<"↑ | "; 
  }
  else if(pf[2]==-1){
  cout<<"| Gold          | "; printf("\033[;31m%7.2lf\033[0m",price[2][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Gold          | "; printf("\033[;34m%7.2lf\033[0m",price[2][0]); cout<<"  | "; 
  }
  if(af[2]==1){
   printf("\033[;32m%7.2lf\033[0m",average[2][0]); cout<<"↑ |"<<endl;
  }
  else if(af[2]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[2][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[2][0]); cout<<"  |"<<endl;
  }

  //Silver
  if(pf[3]==1){
  cout<<"| Silver        | "; printf("\033[;32m%7.2lf\033[0m",price[3][0]); cout<<"↑ | "; 
  }
  else if(pf[3]==-1){
  cout<<"| Silver        | "; printf("\033[;31m%7.2lf\033[0m",price[3][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Silver        | "; printf("\033[;34m%7.2lf\033[0m",price[3][0]); cout<<"  | "; 
  }
  if(af[3]==1){
   printf("\033[;32m%7.2lf\033[0m",average[3][0]); cout<<"↑ |"<<endl;
  }
  else if(af[3]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[3][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[3][0]); cout<<"  |"<<endl;
  }
  
  //Zinc
  if(pf[4]==1){
  cout<<"| Zinc          | "; printf("\033[;32m%7.2lf\033[0m",price[4][0]); cout<<"↑ | "; 
  }
  else if(pf[4]==-1){
  cout<<"| Zinc          | "; printf("\033[;31m%7.2lf\033[0m",price[4][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Zinc          | "; printf("\033[;34m%7.2lf\033[0m",price[4][0]); cout<<"  | "; 
  }
  if(af[4]==1){
   printf("\033[;32m%7.2lf\033[0m",average[4][0]); cout<<"↑ |"<<endl;
  }
  else if(af[4]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[4][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[4][0]); cout<<"  |"<<endl;
  } 

  //Crudeoil
  if(pf[5]==1){
  cout<<"| Crudeoil      | "; printf("\033[;32m%7.2lf\033[0m",price[5][0]); cout<<"↑ | "; 
  }
  else if(pf[5]==-1){
  cout<<"| Crudeoil      | "; printf("\033[;31m%7.2lf\033[0m",price[5][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Crudeoil      | "; printf("\033[;34m%7.2lf\033[0m",price[5][0]); cout<<"  | "; 
  }
  if(af[5]==1){
   printf("\033[;32m%7.2lf\033[0m",average[5][0]); cout<<"↑ |"<<endl;
  }
  else if(af[5]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[5][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[5][0]); cout<<"  |"<<endl;
  } 

   //Naturalgas
  if(pf[6]==1){
  cout<<"| Naturalgas    | "; printf("\033[;32m%7.2lf\033[0m",price[6][0]); cout<<"↑ | "; 
  }
  else if(pf[6]==-1){
  cout<<"| Naturalgas    | "; printf("\033[;31m%7.2lf\033[0m",price[6][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Naturalgas    | "; printf("\033[;34m%7.2lf\033[0m",price[6][0]); cout<<"  | "; 
  }
  if(af[6]==1){
   printf("\033[;32m%7.2lf\033[0m",average[6][0]); cout<<"↑ |"<<endl;
  }
  else if(af[6]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[6][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[6][0]); cout<<"  |"<<endl;
  } 

  //Nickel
  if(pf[7]==1){
  cout<<"| Nickel        | "; printf("\033[;32m%7.2lf\033[0m",price[7][0]); cout<<"↑ | "; 
  }
  else if(pf[7]==-1){
  cout<<"| Nickel        | "; printf("\033[;31m%7.2lf\033[0m",price[7][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Nickel        | "; printf("\033[;34m%7.2lf\033[0m",price[7][0]); cout<<"  | "; 
  }
  if(af[7]==1){
   printf("\033[;32m%7.2lf\033[0m",average[7][0]); cout<<"↑ |"<<endl;
  }
  else if(af[7]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[7][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[7][0]); cout<<"  |"<<endl;
  } 
  
  //Lead
  if(pf[8]==1){
  cout<<"| Lead          | "; printf("\033[;32m%7.2lf\033[0m",price[8][1]); cout<<"↑ | "; 
  }
  else if(pf[8]==-1){
  cout<<"| Lead          | "; printf("\033[;31m%7.2lf\033[0m",price[8][1]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Lead          | "; printf("\033[;34m%7.2lf\033[0m",price[8][1]); cout<<"  | "; 
  }
  if(af[8]==1){
   printf("\033[;32m%7.2lf\033[0m",average[8][1]); cout<<"↑ |"<<endl;
  }
  else if(af[8]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[8][1]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[8][1]); cout<<"  |"<<endl;
  } 

  //Menthaoil
  if(pf[9]==1){
  cout<<"| Menthaoil     | "; printf("\033[;32m%7.2lf\033[0m",price[9][0]); cout<<"↑ | "; 
  }
  else if(pf[9]==-1){
  cout<<"| Menthaoil     | "; printf("\033[;31m%7.2lf\033[0m",price[9][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Menthaoil     | "; printf("\033[;34m%7.2lf\033[0m",price[9][0]); cout<<"  | "; 
  }
  if(af[9]==1){
   printf("\033[;32m%7.2lf\033[0m",average[9][0]); cout<<"↑ |"<<endl;
  }
  else if(af[9]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[9][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[9][0]); cout<<"  |"<<endl;
  } 

  //Cotton
    if(pf[10]==1){
  cout<<"| Cotton        | "; printf("\033[;32m%7.2lf\033[0m",price[10][0]); cout<<"↑ | "; 
  }
  else if(pf[10]==-1){
  cout<<"| Cotton        | "; printf("\033[;31m%7.2lf\033[0m",price[10][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Cotton        | "; printf("\033[;34m%7.2lf\033[0m",price[10][0]); cout<<"  | "; 
  }
  if(af[10]==1){
   printf("\033[;32m%7.2lf\033[0m",average[10][0]); cout<<"↑ |"<<endl;
  }
  else if(af[10]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[10][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[10][0]); cout<<"  |"<<endl;
  } 

  cout<<"+-------------------------------------+"<<endl;
  }

   else if(name=="Menthaoil"){
    cout<<"+-------------------------------------+"<<endl;
  cout<<"| Currency      |  Price   | AvgPrice |"<<endl;
  cout<<"+-------------------------------------+"<<endl;
  if(pf[0]==1){
  cout<<"| Aluminum      | "; printf("\033[;32m%7.2lf\033[0m",price[0][0]); cout<<"↑ | "; 
  }
  else if(pf[0]==-1){
  cout<<"| Aluminum      | "; printf("\033[;31m%7.2lf\033[0m",price[0][0]); cout<<"↓ | "; 
  }
  else{
    cout<<"| Aluminum      | "; printf("\033[;34m%7.2lf\033[0m",price[0][0]); cout<<"  | "; 
  }
  if(af[0]==1){
   printf("\033[;32m%7.2lf\033[0m",average[0][0]); cout<<"↑ |"<<endl;
  }
  else if(af[0]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[0][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[0][0]); cout<<"  |"<<endl;
  }
  //Copper
  if(pf[1]==1){
  cout<<"| Copper        | "; printf("\033[;32m%7.2lf\033[0m",price[1][0]); cout<<"↑ | "; 
  }
  else if(pf[1]==-1){
  cout<<"| Copper        | "; printf("\033[;31m%7.2lf\033[0m",price[1][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Copper        | "; printf("\033[;34m%7.2lf\033[0m",price[1][0]); cout<<"  | "; 
  }
  if(af[1]==1){
   printf("\033[;32m%7.2lf\033[0m",average[1][0]); cout<<"↑ |"<<endl;
  }
  else if(af[1]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[1][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[1][0]); cout<<"  |"<<endl;
  }
  //Gold
  if(pf[2]==1){
  cout<<"| Gold          | "; printf("\033[;32m%7.2lf\033[0m",price[2][0]); cout<<"↑ | "; 
  }
  else if(pf[2]==-1){
  cout<<"| Gold          | "; printf("\033[;31m%7.2lf\033[0m",price[2][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Gold          | "; printf("\033[;34m%7.2lf\033[0m",price[2][0]); cout<<"  | "; 
  }
  if(af[2]==1){
   printf("\033[;32m%7.2lf\033[0m",average[2][0]); cout<<"↑ |"<<endl;
  }
  else if(af[2]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[2][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[2][0]); cout<<"  |"<<endl;
  }

  //Silver
  if(pf[3]==1){
  cout<<"| Silver        | "; printf("\033[;32m%7.2lf\033[0m",price[3][0]); cout<<"↑ | "; 
  }
  else if(pf[3]==-1){
  cout<<"| Silver        | "; printf("\033[;31m%7.2lf\033[0m",price[3][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Silver        | "; printf("\033[;34m%7.2lf\033[0m",price[3][0]); cout<<"  | "; 
  }
  if(af[3]==1){
   printf("\033[;32m%7.2lf\033[0m",average[3][0]); cout<<"↑ |"<<endl;
  }
  else if(af[3]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[3][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[3][0]); cout<<"  |"<<endl;
  }
  
  //Zinc
  if(pf[4]==1){
  cout<<"| Zinc          | "; printf("\033[;32m%7.2lf\033[0m",price[4][0]); cout<<"↑ | "; 
  }
  else if(pf[4]==-1){
  cout<<"| Zinc          | "; printf("\033[;31m%7.2lf\033[0m",price[4][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Zinc          | "; printf("\033[;34m%7.2lf\033[0m",price[4][0]); cout<<"  | "; 
  }
  if(af[4]==1){
   printf("\033[;32m%7.2lf\033[0m",average[4][0]); cout<<"↑ |"<<endl;
  }
  else if(af[4]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[4][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[4][0]); cout<<"  |"<<endl;
  } 

  //Crudeoil
  if(pf[5]==1){
  cout<<"| Crudeoil      | "; printf("\033[;32m%7.2lf\033[0m",price[5][0]); cout<<"↑ | "; 
  }
  else if(pf[5]==-1){
  cout<<"| Crudeoil      | "; printf("\033[;31m%7.2lf\033[0m",price[5][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Crudeoil      | "; printf("\033[;34m%7.2lf\033[0m",price[5][0]); cout<<"  | "; 
  }
  if(af[5]==1){
   printf("\033[;32m%7.2lf\033[0m",average[5][0]); cout<<"↑ |"<<endl;
  }
  else if(af[5]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[5][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[5][0]); cout<<"  |"<<endl;
  } 

   //Naturalgas
  if(pf[6]==1){
  cout<<"| Naturalgas    | "; printf("\033[;32m%7.2lf\033[0m",price[6][0]); cout<<"↑ | "; 
  }
  else if(pf[6]==-1){
  cout<<"| Naturalgas    | "; printf("\033[;31m%7.2lf\033[0m",price[6][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Naturalgas    | "; printf("\033[;34m%7.2lf\033[0m",price[6][0]); cout<<"  | "; 
  }
  if(af[6]==1){
   printf("\033[;32m%7.2lf\033[0m",average[6][0]); cout<<"↑ |"<<endl;
  }
  else if(af[6]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[6][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[6][0]); cout<<"  |"<<endl;
  } 

  //Nickel
  if(pf[7]==1){
  cout<<"| Nickel        | "; printf("\033[;32m%7.2lf\033[0m",price[7][0]); cout<<"↑ | "; 
  }
  else if(pf[7]==-1){
  cout<<"| Nickel        | "; printf("\033[;31m%7.2lf\033[0m",price[7][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Nickel        | "; printf("\033[;34m%7.2lf\033[0m",price[7][0]); cout<<"  | "; 
  }
  if(af[7]==1){
   printf("\033[;32m%7.2lf\033[0m",average[7][0]); cout<<"↑ |"<<endl;
  }
  else if(af[7]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[7][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[7][0]); cout<<"  |"<<endl;
  } 
  
  //Lead
  if(pf[8]==1){
  cout<<"| Lead          | "; printf("\033[;32m%7.2lf\033[0m",price[8][0]); cout<<"↑ | "; 
  }
  else if(pf[8]==-1){
  cout<<"| Lead          | "; printf("\033[;31m%7.2lf\033[0m",price[8][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Lead          | "; printf("\033[;34m%7.2lf\033[0m",price[8][0]); cout<<"  | "; 
  }
  if(af[8]==1){
   printf("\033[;32m%7.2lf\033[0m",average[8][0]); cout<<"↑ |"<<endl;
  }
  else if(af[8]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[8][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[8][0]); cout<<"  |"<<endl;
  } 

  //Menthaoil
  if(pf[9]==1){
  cout<<"| Menthaoil     | "; printf("\033[;32m%7.2lf\033[0m",price[9][1]); cout<<"↑ | "; 
  }
  else if(pf[9]==-1){
  cout<<"| Menthaoil     | "; printf("\033[;31m%7.2lf\033[0m",price[9][1]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Menthaoil     | "; printf("\033[;34m%7.2lf\033[0m",price[9][1]); cout<<"  | "; 
  }
  if(af[9]==1){
   printf("\033[;32m%7.2lf\033[0m",average[9][1]); cout<<"↑ |"<<endl;
  }
  else if(af[9]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[9][1]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[9][1]); cout<<"  |"<<endl;
  } 

  //Cotton
    if(pf[10]==1){
  cout<<"| Cotton        | "; printf("\033[;32m%7.2lf\033[0m",price[10][0]); cout<<"↑ | "; 
  }
  else if(pf[10]==-1){
  cout<<"| Cotton        | "; printf("\033[;31m%7.2lf\033[0m",price[10][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Cotton        | "; printf("\033[;34m%7.2lf\033[0m",price[10][0]); cout<<"  | "; 
  }
  if(af[10]==1){
   printf("\033[;32m%7.2lf\033[0m",average[10][0]); cout<<"↑ |"<<endl;
  }
  else if(af[10]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[10][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[10][0]); cout<<"  |"<<endl;
  } 

  cout<<"+-------------------------------------+"<<endl;
  }

   else if(name=="Cotton"){
   cout<<"+-------------------------------------+"<<endl;
  cout<<"| Currency      |  Price   | AvgPrice |"<<endl;
  cout<<"+-------------------------------------+"<<endl;
  if(pf[0]==1){
  cout<<"| Aluminum      | "; printf("\033[;32m%7.2lf\033[0m",price[0][0]); cout<<"↑ | "; 
  }
  else if(pf[0]==-1){
  cout<<"| Aluminum      | "; printf("\033[;31m%7.2lf\033[0m",price[0][0]); cout<<"↓ | "; 
  }
  else{
    cout<<"| Aluminum      | "; printf("\033[;34m%7.2lf\033[0m",price[0][0]); cout<<"  | "; 
  }
  if(af[0]==1){
   printf("\033[;32m%7.2lf\033[0m",average[0][0]); cout<<"↑ |"<<endl;
  }
  else if(af[0]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[0][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[0][0]); cout<<"  |"<<endl;
  }
  //Copper
  if(pf[1]==1){
  cout<<"| Copper        | "; printf("\033[;32m%7.2lf\033[0m",price[1][0]); cout<<"↑ | "; 
  }
  else if(pf[1]==-1){
  cout<<"| Copper        | "; printf("\033[;31m%7.2lf\033[0m",price[1][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Copper        | "; printf("\033[;34m%7.2lf\033[0m",price[1][0]); cout<<"  | "; 
  }
  if(af[1]==1){
   printf("\033[;32m%7.2lf\033[0m",average[1][0]); cout<<"↑ |"<<endl;
  }
  else if(af[1]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[1][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[1][0]); cout<<"  |"<<endl;
  }
  //Gold
  if(pf[2]==1){
  cout<<"| Gold          | "; printf("\033[;32m%7.2lf\033[0m",price[2][0]); cout<<"↑ | "; 
  }
  else if(pf[2]==-1){
  cout<<"| Gold          | "; printf("\033[;31m%7.2lf\033[0m",price[2][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Gold          | "; printf("\033[;34m%7.2lf\033[0m",price[2][0]); cout<<"  | "; 
  }
  if(af[2]==1){
   printf("\033[;32m%7.2lf\033[0m",average[2][0]); cout<<"↑ |"<<endl;
  }
  else if(af[2]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[2][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[2][0]); cout<<"  |"<<endl;
  }

  //Silver
  if(pf[3]==1){
  cout<<"| Silver        | "; printf("\033[;32m%7.2lf\033[0m",price[3][0]); cout<<"↑ | "; 
  }
  else if(pf[3]==-1){
  cout<<"| Silver        | "; printf("\033[;31m%7.2lf\033[0m",price[3][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Silver        | "; printf("\033[;34m%7.2lf\033[0m",price[3][0]); cout<<"  | "; 
  }
  if(af[3]==1){
   printf("\033[;32m%7.2lf\033[0m",average[3][0]); cout<<"↑ |"<<endl;
  }
  else if(af[3]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[3][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[3][0]); cout<<"  |"<<endl;
  }
  
  //Zinc
  if(pf[4]==1){
  cout<<"| Zinc          | "; printf("\033[;32m%7.2lf\033[0m",price[4][0]); cout<<"↑ | "; 
  }
  else if(pf[4]==-1){
  cout<<"| Zinc          | "; printf("\033[;31m%7.2lf\033[0m",price[4][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Zinc          | "; printf("\033[;34m%7.2lf\033[0m",price[4][0]); cout<<"  | "; 
  }
  if(af[4]==1){
   printf("\033[;32m%7.2lf\033[0m",average[4][0]); cout<<"↑ |"<<endl;
  }
  else if(af[4]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[4][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[4][0]); cout<<"  |"<<endl;
  } 

  //Crudeoil
  if(pf[5]==1){
  cout<<"| Crudeoil      | "; printf("\033[;32m%7.2lf\033[0m",price[5][0]); cout<<"↑ | "; 
  }
  else if(pf[5]==-1){
  cout<<"| Crudeoil      | "; printf("\033[;31m%7.2lf\033[0m",price[5][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Crudeoil      | "; printf("\033[;34m%7.2lf\033[0m",price[5][0]); cout<<"  | "; 
  }
  if(af[5]==1){
   printf("\033[;32m%7.2lf\033[0m",average[5][0]); cout<<"↑ |"<<endl;
  }
  else if(af[5]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[5][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[5][0]); cout<<"  |"<<endl;
  } 

   //Naturalgas
  if(pf[6]==1){
  cout<<"| Naturalgas    | "; printf("\033[;32m%7.2lf\033[0m",price[6][0]); cout<<"↑ | "; 
  }
  else if(pf[6]==-1){
  cout<<"| Naturalgas    | "; printf("\033[;31m%7.2lf\033[0m",price[6][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Naturalgas    | "; printf("\033[;34m%7.2lf\033[0m",price[6][0]); cout<<"  | "; 
  }
  if(af[6]==1){
   printf("\033[;32m%7.2lf\033[0m",average[6][0]); cout<<"↑ |"<<endl;
  }
  else if(af[6]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[6][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[6][0]); cout<<"  |"<<endl;
  } 

  //Nickel
  if(pf[7]==1){
  cout<<"| Nickel        | "; printf("\033[;32m%7.2lf\033[0m",price[7][0]); cout<<"↑ | "; 
  }
  else if(pf[7]==-1){
  cout<<"| Nickel        | "; printf("\033[;31m%7.2lf\033[0m",price[7][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Nickel        | "; printf("\033[;34m%7.2lf\033[0m",price[7][0]); cout<<"  | "; 
  }
  if(af[7]==1){
   printf("\033[;32m%7.2lf\033[0m",average[7][0]); cout<<"↑ |"<<endl;
  }
  else if(af[7]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[7][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[7][0]); cout<<"  |"<<endl;
  } 
  
  //Lead
  if(pf[8]==1){
  cout<<"| Lead          | "; printf("\033[;32m%7.2lf\033[0m",price[8][0]); cout<<"↑ | "; 
  }
  else if(pf[8]==-1){
  cout<<"| Lead          | "; printf("\033[;31m%7.2lf\033[0m",price[8][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Lead          | "; printf("\033[;34m%7.2lf\033[0m",price[8][0]); cout<<"  | "; 
  }
  if(af[8]==1){
   printf("\033[;32m%7.2lf\033[0m",average[8][0]); cout<<"↑ |"<<endl;
  }
  else if(af[8]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[8][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[8][0]); cout<<"  |"<<endl;
  } 

  //Menthaoil
  if(pf[9]==1){
  cout<<"| Menthaoil     | "; printf("\033[;32m%7.2lf\033[0m",price[9][0]); cout<<"↑ | "; 
  }
  else if(pf[9]==-1){
  cout<<"| Menthaoil     | "; printf("\033[;31m%7.2lf\033[0m",price[9][0]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Menthaoil     | "; printf("\033[;34m%7.2lf\033[0m",price[9][0]); cout<<"  | "; 
  }
  if(af[9]==1){
   printf("\033[;32m%7.2lf\033[0m",average[9][0]); cout<<"↑ |"<<endl;
  }
  else if(af[9]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[9][0]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[9][0]); cout<<"  |"<<endl;
  } 

  //Cotton
    if(pf[10]==1){
  cout<<"| Cotton        | "; printf("\033[;32m%7.2lf\033[0m",price[10][1]); cout<<"↑ | "; 
  }
  else if(pf[10]==-1){
  cout<<"| Cotton        | "; printf("\033[;31m%7.2lf\033[0m",price[10][1]); cout<<"↓ | "; 
  }
  else{
  cout<<"| Cotton        | "; printf("\033[;34m%7.2lf\033[0m",price[10][1]); cout<<"  | "; 
  }
  if(af[10]==1){
   printf("\033[;32m%7.2lf\033[0m",average[10][1]); cout<<"↑ |"<<endl;
  }
  else if(af[10]==-1){
   printf("\033[;31m%7.2lf\033[0m",average[10][1]); cout<<"↓ |"<<endl;
  }
  else{
    printf("\033[;34m%7.2lf\033[0m",average[10][1]); cout<<"  |"<<endl;
  } 

  cout<<"+-------------------------------------+"<<endl;
  }
  
}

int main(int n,char**arr)
{
 
    // ftok to generate unique key
struct sembuf op[1]={{0,0,0}};
      semun ff;
      int buff_size=stoi(arr[1]);
    
   int emptybuff_sem=semget(1000+3,1,0660 | IPC_CREAT);
    int mutex_sem=semget(1000+2,1,0660 | IPC_CREAT);
    int fullbuff_sem=semget(1000+1,1,0660 | IPC_CREAT);
        ff.val=0;
        semctl (fullbuff_sem, 0, SETVAL, ff);
        ff.val=100;
        semctl (emptybuff_sem, 0, SETVAL, ff);
        ff.val=1;
        semctl (mutex_sem, 0, SETVAL, ff);  

    key_t key = ftok("shmfile",65);
    int cntr=0;
   
    // shmget returns an identifier in shmid
    int shmid = shmget(6003,sizeof(product)*buff_size,0666|IPC_CREAT);

  
    // shmat to attach to shared memory
    product* (str) = (product*) shmat(shmid,(void*)0,0);
    double price[11][2]={0.00};
    int price_flag[11]={0};
    int average_flag[11]={0};
    double average[11][2]={0.00};
    char name[10];
    //string name;

   while(1){
     //memcpy(&price,str,sizeof(str));
     op->sem_op=-1;
        semop (fullbuff_sem, op, 1);

        semop (mutex_sem, op, 1);

        //critical section
     
      string name=str[cntr%buff_size].name;
      
  if(name=="Aluminum"){
       price[0][1]=str[cntr%buff_size].price;
       
       average[0][1]=str[cntr%buff_size].average;
       if(price[0][1]>price[0][0]){
        price_flag[0]=1;
       }
       else if(price[0][1]<price[0][0]){
        price_flag[0]=-1;
       }
       else{
        price_flag[0]=0;
       };
       if(average[0][1]>average[0][0]){
        average_flag[0]=1;
       }
       else if(average[0][1]<average[0][0]){
        average_flag[0]=-1;
       }
       else{
        average_flag[0]=0;
       };
       display_temp(name,price,average,price_flag,average_flag);
       cout<<"Old price :"<<price[0][0]<<endl;
           cout<<"Old average :"<<average[0][0]<<endl;
       price[0][0]=price[0][1];
       average[0][0]=average[0][1];
            cout<<"consumer price :"<<price[0][1]<<endl;
           cout<<"average :"<<average[0][1]<<endl;
           cout<<"name : "<<name<<endl;
       
}
 else if(name=="Copper"){
       price[1][1]=str[cntr%buff_size].price;
       average[1][1]=str[cntr%buff_size].average;
       if(price[1][1]>price[1][0]){
        price_flag[1]=1;
       }
       else if(price[1][1]<price[1][0]){
        price_flag[1]=-1;
       }
       else{
        price_flag[1]=0;
       };
       if(average[1][1]>average[1][0]){
        average_flag[1]=1;
       }
       else if(average[1][1]<average[1][0]){
        average_flag[1]=-1;
       }
       else{
        average_flag[1]=0;
       };
       display_temp(name,price,average,price_flag,average_flag);
       cout<<"Old price :"<<price[1][0]<<endl;
           cout<<"Old average :"<<average[1][0]<<endl;
       price[1][0]=price[1][1];
       average[1][0]=average[1][1];
       //cout<<name<<endl;
           cout<<"consumer price :"<<price[1][1]<<endl;
          cout<<"average :"<<average[1][1]<<endl;
           cout<<"name : "<<name<<endl;

}
 else if(name=="Gold"){
       price[2][1]=str[cntr%buff_size].price;
       average[2][1]=str[cntr%buff_size].average;
       if(price[2][1]>price[2][0]){
        price_flag[2]=1;
       }
       else if(price[2][1]<price[2][0]){
        price_flag[2]=-1;
       }
       else{
        price_flag[2]=0;
       };
       if(average[2][1]>average[2][0]){
        average_flag[2]=1;
       }
       else if(average[2][1]<average[2][0]){
        average_flag[2]=-1;
       }
      else{
        average_flag[2]=0;
       };
       display_temp(name,price,average,price_flag,average_flag);
       cout<<"Old price :"<<price[2][0]<<endl;
           cout<<"Old average :"<<average[2][0]<<endl;
       price[2][0]=price[2][1];
       average[2][0]=average[2][1];
             cout<<"consumer price :"<<price[2][1]<<endl;
          cout<<"average :"<<average[2][1]<<endl;
           cout<<"name : "<<name<<endl;
}
 else if(name=="Silver"){
       price[3][1]=str[cntr%buff_size].price;
       average[3][1]=str[cntr%buff_size].average;
       if(price[3][1]>price[3][0]){
        price_flag[3]=1;
       }
       else if(price[3][1]<price[3][0]){
        price_flag[3]=-1;
       }
       else{
        price_flag[3]=0;
       };
       if(average[3][1]>average[3][0]){
        average_flag[3]=1;
       }
       else if(average[3][1]<average[3][0]){
        average_flag[3]=-1;
       }
       else{
        average_flag[3]=0;
       };
       display_temp(name,price,average,price_flag,average_flag);
       cout<<"Old price :"<<price[3][0]<<endl;
           cout<<"Old average :"<<average[3][0]<<endl;
       price[3][0]=price[3][1];
      average[3][0]=average[3][1];
            cout<<"consumer price :"<<price[3][1]<<endl;
           cout<<"average :"<<average[3][1]<<endl;
           cout<<"name : "<<name<<endl;
 }
 else if(name=="Zinc"){
       price[4][1]=str[cntr%buff_size].price;
       average[4][1]=str[cntr%buff_size].average;
       if(price[4][1]>price[4][0]){
        price_flag[4]=1;
       }
       else if(price[4][1]<price[4][0]){
        price_flag[4]=-1;
       }
       else{
        price_flag[4]=0;
       };
       if(average[4][1]>average[4][0]){
        average_flag[4]=1;
       }
       else if(average[4][1]<average[4][0]){
        average_flag[4]=-1;
       }
       else{
        average_flag[4]=0;
       };

       display_temp(name,price,average,price_flag,average_flag);
       cout<<"Old price :"<<price[4][0]<<endl;
           cout<<"Old average :"<<average[4][0]<<endl;
       price[4][0]=price[4][1];
       average[4][0]=average[4][1];
            cout<<"consumer price :"<<price[4][1]<<endl;
          cout<<"average :"<<average[4][1]<<endl;
           cout<<"name : "<<name<<endl;
}
else if(name=="Crudeoil"){
           price[5][1]=str[cntr%buff_size].price;
       average[5][1]=str[cntr%buff_size].average;
       if(price[5][1]>price[5][0]){
        price_flag[5]=1;
       }
       else if(price[5][1]<price[5][0]){
        price_flag[5]=-1;
       }
       else{
        price_flag[5]=0;
       };
       if(average[5][1]>average[5][0]){
        average_flag[5]=1;
       }
       else if(average[5][1]<average[5][0]){
        average_flag[5]=-1;
       }
       else{
        average_flag[5]=0;
       };

       display_temp(name,price,average,price_flag,average_flag);
       cout<<"Old price :"<<price[5][0]<<endl;
           cout<<"Old average :"<<average[5][0]<<endl;
       price[5][0]=price[5][1];
       average[5][0]=average[5][1];
            cout<<"consumer price :"<<price[5][1]<<endl;
          cout<<"average :"<<average[5][1]<<endl;
           cout<<"name : "<<name<<endl;
}
else if(name=="Naturalgas"){
         price[6][1]=str[cntr%buff_size].price;
       average[6][1]=str[cntr%buff_size].average;
       if(price[6][1]>price[6][0]){
        price_flag[6]=1;
       }
       else if(price[6][1]<price[6][0]){
        price_flag[6]=-1;
       }
       else{
        price_flag[6]=0;
       };
       if(average[6][1]>average[6][0]){
        average_flag[6]=1;
       }
       else if(average[6][1]<average[6][0]){
        average_flag[6]=-1;
       }
       else{
        average_flag[6]=0;
       };

       display_temp(name,price,average,price_flag,average_flag);
       cout<<"Old price :"<<price[6][0]<<endl;
           cout<<"Old average :"<<average[6][0]<<endl;
       price[6][0]=price[6][1];
       average[6][0]=average[6][1];
            cout<<"consumer price :"<<price[6][1]<<endl;
          cout<<"average :"<<average[6][1]<<endl;
           cout<<"name : "<<name<<endl;
}
else if(name=="Nickel"){
         price[7][1]=str[cntr%buff_size].price;
       average[7][1]=str[cntr%buff_size].average;
       if(price[7][1]>price[7][0]){
        price_flag[7]=1;
       }
       else if(price[7][1]<price[7][0]){
        price_flag[7]=-1;
       }
       else{
        price_flag[7]=0;
       };
       if(average[7][1]>average[7][0]){
        average_flag[7]=1;
       }
       else if(average[7][1]<average[7][0]){
        average_flag[7]=-1;
       }
       else{
        average_flag[7]=0;
       };

       display_temp(name,price,average,price_flag,average_flag);
       cout<<"Old price :"<<price[7][0]<<endl;
           cout<<"Old average :"<<average[7][0]<<endl;
       price[7][0]=price[7][1];
       average[7][0]=average[7][1];
            cout<<"consumer price :"<<price[7][1]<<endl;
          cout<<"average :"<<average[7][1]<<endl;
           cout<<"name : "<<name<<endl;
}
else if(name=="Lead"){
        price[8][1]=str[cntr%buff_size].price;
       average[8][1]=str[cntr%buff_size].average;
       if(price[8][1]>price[8][0]){
        price_flag[8]=1;
       }
       else if(price[8][1]<price[8][0]){
        price_flag[8]=-1;
       }
       else{
        price_flag[8]=0;
       };
       if(average[8][1]>average[8][0]){
        average_flag[8]=1;
       }
       else if(average[8][1]<average[8][0]){
        average_flag[8]=-1;
       }
       else{
        average_flag[8]=0;
       };

       display_temp(name,price,average,price_flag,average_flag);
       cout<<"Old price :"<<price[8][0]<<endl;
           cout<<"Old average :"<<average[8][0]<<endl;
       price[8][0]=price[8][1];
       average[8][0]=average[8][1];
            cout<<"consumer price :"<<price[8][1]<<endl;
          cout<<"average :"<<average[8][1]<<endl;
           cout<<"name : "<<name<<endl;
}
else if(name=="Menthaoil"){
         price[9][1]=str[cntr%buff_size].price;
       average[9][1]=str[cntr%buff_size].average;
       if(price[9][1]>price[9][0]){
        price_flag[9]=1;
       }
       else if(price[4][1]<price[9][0]){
        price_flag[9]=-1;
       }
       else{
        price_flag[9]=0;
       };
       if(average[9][1]>average[9][0]){
        average_flag[9]=1;
       }
       else if(average[9][1]<average[9][0]){
        average_flag[9]=-1;
       }
       else{
        average_flag[9]=0;
       };

       display_temp(name,price,average,price_flag,average_flag);
       cout<<"Old price :"<<price[9][0]<<endl;
           cout<<"Old average :"<<average[9][0]<<endl;
       price[9][0]=price[9][1];
       average[9][0]=average[9][1];
            cout<<"consumer price :"<<price[9][1]<<endl;
          cout<<"average :"<<average[9][1]<<endl;
           cout<<"name : "<<name<<endl;
}
else if(name=="Cotton"){
         price[10][1]=str[cntr%buff_size].price;
       average[10][1]=str[cntr%buff_size].average;
       if(price[10][1]>price[10][0]){
        price_flag[10]=1;
       }
       else if(price[10][1]<price[10][0]){
        price_flag[10]=-1;
       }
       else{
        price_flag[10]=0;
       };
       if(average[10][1]>average[10][0]){
        average_flag[10]=1;
       }
       else if(average[10][1]<average[10][0]){
        average_flag[10]=-1;
       }
       else{
        average_flag[10]=0;
       };

       display_temp(name,price,average,price_flag,average_flag);
       cout<<"Old price :"<<price[10][0]<<endl;
       cout<<"Old average :"<<average[10][0]<<endl;
       price[10][0]=price[10][1];
       average[10][0]=average[10][1];
       cout<<"consumer price :"<<price[10][1]<<endl;
       cout<<"average :"<<average[10][1]<<endl;
       cout<<"name : "<<name<<endl;
}
     
           cntr++;
           op->sem_op=1;
           semop (mutex_sem, op, 1);
           semop (emptybuff_sem, op, 1);
           //std::this_thread::sleep_for(std::chrono::milliseconds(2000));
  }
      
   //detach from shared memory 
    shmdt(str);
    // destroy the shared memory
   //shmctl(shmid,IPC_RMID,NULL);
    
    return 0;
}
