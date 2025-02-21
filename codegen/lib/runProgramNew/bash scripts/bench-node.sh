#!/bin/bash -l
#SBATCH --job-name=bench_intranode
#SBATCH --output=Fritz_ICX_intranode
#SBATCH --partition=singlenode
#SBATCH --nodes=1
#SBATCH --ntasks-per-node=72
#SBATCH --time=1:00:00
#SBATCH --export=NONE
#SBATCH --cpu-freq=2400000-2400000:performance

unset SLURM_EXPORT_ENV

module load likwid intel intelmpi
export I_MPI_PIN=1
export I_MPI_DEBUG=0

cd ../
make

for CARD_NUMBER in $(seq 1 3); do
    # add card number to the file name
    FILENAME="scale_study/result_bench_intranode_CARD_${CARD_NUMBER}.csv"

    rm $FILENAME
    touch $FILENAME
    echo "Ranks,Time" >>$FILENAME

    rm -f log_node${CARD_NUMBER}.txt
    touch log_node${CARD_NUMBER}.txt


    _iterate() {
        for np in $(seq 1 4); do
            npn=$(($np * $NPM))
            NC=$NPM

            result="$(mpirun -n $npn ./build/runProgram $CARD_NUMBER)"
            echo $result >>log_node.txt
            extracted_time=$(echo "$result" | grep -oP 'Elapsed time is \K[\d.]+')

            echo "$npn,$extracted_time" >>$FILENAME
        done
    }

    NPM=18

    _iterate

    sed -i 's/ /,/g' $FILENAME

done