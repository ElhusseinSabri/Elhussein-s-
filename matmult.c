#include<stdlib.h>
#include<pthread.h>
#include <stdio.h>

#define Item(X, I, J, NCOL)      X[((J) + (I) * (NCOL))]

 typedef struct {
    int *A;
    int *B;
    int *C;
    int l;
    int m;
    int n;
    int i;
    int j;

}mat;
/*
 * matrix multiplication
 *     C = A*B
 *     A has l rows and m cols
 *     B has m rows and n cols
 *     C has l rows and n cols
 */
void matmult(int* A, int* B, int* C, int l, int m, int n)
{  
    for(int i=0; i<l; i++)
        for(int j=0; j<n; j++)
        {
            int sum = 0;
            for(int k=0; k<m; k++)
                sum += Item(A, i, k, m) * Item(B, k, j, n);
            Item(C, i, j, n) = sum;
        }
}

void *element(void* ma){
   
    mat*mm=(mat*)ma;
    int sum=0;
            for(int k=0; k<mm->m; k++)
                sum += Item(mm->A, mm->i, k, mm->m) * Item(mm->B, k, mm->j, mm->n);
        Item(mm->C, mm->i, mm->j, mm->n) = sum;
          
    //return sum;
 }


 void *row(void *ma){
    mat*mem=(mat*)ma;
   for(int j=0; j<mem->n; j++)
        {
            int sum = 0;
            for(int k=0; k<mem->m; k++)
                sum += Item(mem->A, mem->i, k, mem->m) * Item(mem->B, k, j, mem->n);
            Item(mem->C, mem->i, j, mem->n) = sum;
        }
 }

 

/*
 * matrix multiplication
 *     C = A*B
 *     A has l rows and m cols
 *     B has m rows and n cols
 *     C has l rows and n cols
 */
void matmult_v1(int* A, int* B, int* C, int l, int m, int n)
{
int sum;
pthread_t thread1[l][n];
mat matt[l][n];

  for(int i=0; i<l; i++){
        for(int j=0; j<n; j++)
        {   
            matt[i][j].A=A;
            matt[i][j].B=B;
            matt[i][j].C=C;
            matt[i][j].l=l;
            matt[i][j].m=m;
            matt[i][j].n=n;
            matt[i][j].i=i;
            matt[i][j].j=j;
            
          sum=pthread_create( &thread1[i][j], NULL, element, (void*)&matt[i][j]);
            //sum=element(matt);
            
            //printf("Thread 1 returns: %d\n",sum);
            
        }

  }
  for(int i=0; i<l; i++){
        for(int j=0; j<n; j++)
        {
            pthread_join( thread1[i][j], NULL);
        }}
   
}



/*
 * matrix multiplication
 *     C = A*B
 *     A has l rows and m cols
 *     B has m rows and n cols
 *     C has l rows and n cols
 */
void matmult_v2(int* A, int* B, int* C, int l, int m, int n)
{

pthread_t thread2[l];
mat matt[l];

int s;
for(int i=0; i<l; i++){
            matt[i].A=A;
            matt[i].B=B;
            matt[i].C=C;
            matt[i].l=l;
            matt[i].m=m;
            matt[i].n=n;
            matt[i].i=i;
           
            
            s=pthread_create( &thread2[i], NULL, row, (void*) &matt[i]);
          
            
}

for(int i=0;i<l;i++){
pthread_join( thread2[i], NULL);
}
}
 

 