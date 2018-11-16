!/bin/bash
#PBS -l nodes=2:intel:ppn=6, mem=64gb
#PBS -l walltime=00:15:00
#PBS -M n.copete@uniandes.edu.co
#PBS -m abe
#PBS -N ncpexo28
#PBS -j oe

module load anaconda/python3
cd $PBS_O_WORKDIR
mpic++ -o integra.x integra.c
for i in {2..8..1}
do
  mpiexec -np 6 ./integra.x 10**i > "File${i}.txt"
done
python grafica.py
