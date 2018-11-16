!/bin/bash
#PBS -l nodes=2:intel:ppn=16, mem=64gb
#PBS -l walltime=00:10:00
#PBS -M n.copete@uniandes.edu.co
#PBS -m abe
#PBS -N ncpexo28
#PBS -j oe

module load anaconda/python3
cd $PBS_O_WORKDIR
make
mpirun -np 16 ./list127.x<<'EOF'
1000
0
