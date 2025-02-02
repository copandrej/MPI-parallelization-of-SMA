import os
import pandas as pd
import matplotlib.pyplot as plt

def create_strong_scaling_plot(csv_file, title, xlabel, ylabel, output_file):
    """
    Create a strong scaling plot from a CSV file.
    
    Parameters:
    -----------
    csv_file : str
        Path to the input CSV file
    title : str
        Title of the plot
    xlabel : str
        X-axis label
    ylabel : str
        Y-axis label
    output_file : str
        Output filename for the plot
    """
    plt.figure(figsize=(10, 6))

    # Read the CSV file
    df = pd.read_csv(csv_file)
    
    # Ensure columns are correctly named
    df.columns = ['Ranks', 'Time']
    
    # Sort dataframe by number of ranks to ensure consistency
    df = df.sort_values('Ranks')
    
    # Find the reference time (time for the smallest rank)
    reference_time = df.iloc[0]['Time']
    reference_ranks = df.iloc[0]['Ranks']
    
    # Calculate speedup using the corrected formula
    df['Speedup'] = reference_time / df['Time']
    
    # Plot measured speedup
    plt.plot(df['Ranks'], df['Speedup'], 'o-', label='Measured Speedup')
    
    # Plot ideal linear speedup for comparison
    plt.plot(df['Ranks'], df['Ranks'] / reference_ranks, 'k--', label='Linear Speedup')
    
    # Labeling
    plt.title(title, fontsize=14)
    plt.xlabel(xlabel, fontsize=12)
    plt.ylabel(ylabel, fontsize=12)
    plt.legend()
    plt.grid(True, linestyle='--', alpha=0.7)
    
    # Improve tick formatting
    plt.xticks(df['Ranks'])
    
    # Save the plot
    plt.tight_layout()
    plt.savefig(output_file, dpi=300)
    plt.close()

# Generate plots for all files
files = [
    "result_bench_internode_CARD_1.csv",
    "result_bench_internode_CARD_2.csv",
    "result_bench_internode_CARD_3.csv",
    "result_bench_intranode_CARD_1.csv",
    "result_bench_intranode_CARD_2.csv",
    "result_bench_intranode_CARD_3.csv",
    "result_bench_memdomain_CARD_1.csv",
    "result_bench_memdomain_CARD_2.csv",
    "result_bench_memdomain_CARD_3.csv"
]

for file in files:
    try:
        # Extract meaningful details from the filename for titles
        scenario = file.split("_")[2]  # internode, intranode, or memdomain
        card = file.split("_")[-1].split(".")[0]  # CARD_1, CARD_2, CARD_3
        title = f"Strong Scaling - {scenario.capitalize()} ({card})"
        xlabel = "Number of Cores"
        ylabel = "Speedup"
        output_file = f"{scenario}_{card}_scaling.png"
        
        # Create the plot
        create_strong_scaling_plot(file, title, xlabel, ylabel, output_file)
    except Exception as e:
        print(f"Error processing {file}: {e}")