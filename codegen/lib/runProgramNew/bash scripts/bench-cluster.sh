#!/bin/bash -l
#SBATCH --job-name=bench_internode
#SBATCH --output=Fritz_ICX_internode
#SBATCH --partition=multinode
#SBATCH --nodes=4
#SBATCH --ntasks-per-node=72
#SBATCH --time=00:30:00
#SBATCH --export=NONE
#SBATCH --cpu-freq=2400000-2400000:performance

unset SLURM_EXPORT_ENV

module load likwid intel intelmpi
export I_MPI_PIN=1
export I_MPI_DEBUG=0
export I_MPI_PIN_PROCESSOR_LIST=0-71


CARD_NUMBER=11
# add card number to the file name
FILENAME="scale_study/result_bench_internode_CARD_${CARD_NUMBER}.csv"
# remove the file if it exists
rm -f $FILENAME

cd ../

rm $FILENAME
touch $FILENAME
echo "Ranks,Time" >>$FILENAME

rm log_cluster.txt
touch log_cluster.txt

_iterate() {
    for np in $(seq 1 4); do
        npn=$(($np * $NPM))

        result="$(mpirun -n $npn ./build/runProgram $CARD_NUMBER)"
        
        echo $result >>log_cluster.txt

        extracted_time=$(echo "$result" | grep -oP 'Elapsed time is \K[\d.]+')
        
        if [[ -z "$extracted_time" ]]; then
            extracted_time="NA" # Handle cases where time is not found
        fi

        # Log the results to the CSV file
        echo "$npn,$extracted_time" >>$FILENAME
    done
}

NPM=72

_iterate

sed -i 's/ /,/g' $FILENAME
