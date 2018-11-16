#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include "mpi.h"
#include <ctime>


using std::cout;
using std::endl;

double integral_MC(int N=1000){
sum=0.0;
for(int i=0; i<N;i++){
double prom=0.0;
for(int j=0;j<10;j++){
double f=(double)rand() / (double)RAND_MAX;
prom+=f*f;
}
sum+=prom;
}
double mean=sum/N;
return mean;
}

int main(int argc, char *argv[]){
srand(time(0));   
int N = atoi(argv[1]); 
double suma,total;
int rank, size;
MPI_Init(&argc,&argv);
MPI_Comm_size(MPI_COMM_WORLD,&size);
MPI_Comm_rank(MPI_COMM_WORLD,&rank);

int N_puntos=N/size;
    
double integ= integral_MC(N_puntos);

MPI_Reduce(&integ,&suma,1,MPI_DOUBLE,MPI_SUM,0,MPI_COMM_WORLD);
if(rank==0){
total=suma/(double)size;
cout<<total<<endl;
}
MPI_Barrier(MPI_COMM_WORLD);
MPI_Finalize();    
return 0;   
}
