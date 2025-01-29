import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

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
    
    # Find the reference time (minimum time, typically the first or lowest ranks)
    reference_time = df.loc[df['Ranks'].idxmin(), 'Time']
    
    # Calculate speedup
    df['Speedup'] = reference_time / df['Time']
    
    # Plot actual speedup
    plt.plot(df['Ranks'], df['Speedup'], 'o-', label='Speedup')
    
    # Plot linear speedup for comparison
    plt.plot(df['Ranks'], df['Ranks'], 'k--', label='Linear Speedup')
    
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

    print(f"Plot saved as {output_file}")

# Define the scenarios
scenarios = [
    {
        'csv_file': 'result_bench_memdomain_CARD_7.csv',
        'title': 'Strong Scaling within 1 NUMA Domain',
        'xlabel': 'Number of Cores',
        'ylabel': 'Speedup',
        'output_file': 'numa_domain_scaling.png'
    },
    # {
    #     'csv_file': 'result_bench_intranode.csv',
    #     'title': 'Inter-NUMA Scaling',
    #     'xlabel': 'Number of Cores',
    #     'ylabel': 'Speedup',
    #     'output_file': 'intra_node_scaling.png'
    # },
    # {
    #     'csv_file': 'result_bench_internode.csv',
    #     'title': 'Inter-Node Scaling',
    #     'xlabel': 'Number of Cores',
    #     'ylabel': 'Speedup',
    #     'output_file': 'inter_node_scaling.png'
    # }
]

# Generate plots for each scenario
for scenario in scenarios:
    try:
        create_strong_scaling_plot(**scenario)
    except Exception as e:
        print(f"Error processing {scenario['csv_file']}: {e}")
