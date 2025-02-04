#!/bin/bash -l
#SBATCH --job-name=bench_memdomain
#SBATCH --output=Fritz_ICX_memdomain
#SBATCH --partition=singlenode
#SBATCH --nodes=1
#SBATCH --ntasks-per-node=72
#SBATCH --time=1:00:00
#SBATCH --export=NONE
#SBATCH --cpu-freq=2400000-2400000:performance

#https://github.com/RRZE-HPC/likwid/wiki/Likwid-Mpirun

unset SLURM_EXPORT_ENV

module load likwid intel intelmpi
export I_MPI_PIN=1
export I_MPI_DEBUG=0


cd ../
make

for CARD_NUMBER in $(seq 1 3); do

    # add card number to the file name
    FILENAME="scale_study/result_bench_memdomain_CARD_${CARD_NUMBER}.csv"

    rm $FILENAME
    touch $FILENAME
    echo "Ranks,Time" >>$FILENAME

    rm log_memdomain${CARD_NUMBER}.txt
    touch log_memdomain${CARD_NUMBER}.txt

    _iterate() {
        for np in $(seq 1 18); do
            np_1=$(($np - 1))
            export I_MPI_PIN_PROCESSOR_LIST=0-$np_1

            result="$(likwid-mpirun -mpi slurm -n $np -nperdomain M:$np ./build/runProgram $CARD_NUMBER)"

            echo $result >>log_memdomain.txt

            extracted_time=$(echo "$result" | grep -oP 'Elapsed time is \K[\d.]+')

            echo "$np,$extracted_time" >>$FILENAME
        done
    }

    NPM=18

    _iterate

    sed -i 's/ /,/g' $FILENAME

done
