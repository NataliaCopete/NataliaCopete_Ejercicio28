#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include "mpi.h"
#define PI 3.14159265358979323846264338327

const double pi_valor=acos(-1);
using std::cout;
using std::endl;

using namespace std;

int main(int argc, char *argv[]){
    

int n ,rank, size, i, len;
double mypi, pi, h,sum,x;
double start_t, end_t, computation_t;
char name[80];

MPI_Init(&argc,&argv);
MPI_Comm_size(MPI_COMM_WORLD,&size);
MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    
MPI_Get_processor_name(name,&len);
    
while(true){
if(rank==0){
cout<<"Enter the number of intervals:(0 quits)"<<endl;    
scanf ("%d",&n);
start_t=MPI_Wtime();
}
MPI_Bcast(&n,1,MPI_INT,0,MPI_COMM_WORLD);
if(n==0) break;
h=1.0/(double)n;
sum=0.0;
for (i=rank+1;i<=n;i+=size){
    
x=h*((double)i-0.5);
sum += 4.0/(1.0+x*x);
    
}
mypi=h*sum;
cout<<"This is my sum:"<<mypi<<"from rank:"<<rank<<"in"<<name<<endl;

MPI_Reduce(&mypi,&pi,1,MPI_DOUBLE,MPI_SUM,0,MPI_COMM_WORLD);

if(rank==0){
double err=pi-PI;
cout<<"pi is approximately"<<pi<<",Error is"<<err<<endl;
computation_t=end_t-start_t;
cout<<"Time of calculating pi is:"<<computation_t<<endl;
}
}
MPI_Barrier(MPI_COMM_WORLD);
MPI_Finalize();      
return 0;   
}
