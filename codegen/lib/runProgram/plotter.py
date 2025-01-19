import matplotlib.pyplot as plt
import matplotlib.animation as animation
import pandas as pd
import numpy as np

# Frame skip parameter (e.g., 1 for all frames, 2 for every second frame, etc.)
frame_step = 2

# Read the data from the CSV file
data = pd.read_csv('bestPositions.csv')

# Calculate the number of points (pairs of x, y columns)
num_points = (len(data.columns) - 2) // 2

# Precompute coordinates for all frames as a 3D Numpy array (num_frames x num_points x 2)
coordinates = data.iloc[:, 1:-1].values.reshape(-1, num_points, 2)[::frame_step]

# Extract fitness values
fitness_values = data.iloc[:, -1].values[::frame_step]

# Create figure
fig, ax = plt.subplots(figsize=(6, 6))
scat = ax.scatter([], [], s=50, alpha=1, c='green')
fitness_text = ax.text(0.02, 0.95, '', transform=ax.transAxes, 
                      fontsize=9, bbox=dict(facecolor='white', alpha=0.7))

# Get data ranges for x and y
x_min, x_max = coordinates[:, :, 0].min(), coordinates[:, :, 0].max()
y_min, y_max = coordinates[:, :, 1].min(), coordinates[:, :, 1].max()

# Set limits
ax.set_xlim(-1, x_max + 2)
ax.set_ylim(-1, y_max + 2)

# Improve grid and axis appearance
ax.grid(True, linestyle='--', alpha=0.3)
ax.set_xlabel('X Position')
ax.set_ylabel('Y Position')
ax.set_title('SMA Position Evolution')
ax.set_aspect('equal')

def init():
    scat.set_offsets(np.empty((0, 2)))
    fitness_text.set_text('')
    return scat, fitness_text

def update(frame):
    # Update scatter plot data
    scat.set_offsets(coordinates[frame])
    # Update fitness text with actual iteration number
    actual_iteration = (frame * frame_step) + 1
    fitness_text.set_text(f'Iteration: {actual_iteration}\nFitness: {fitness_values[frame]:.2f}')
    return scat, fitness_text

def read_and_plot(filepath):
    with open(filepath, 'r') as file:
        lines = file.readlines()

    # Extract coordinates and obstacles
    start_x, start_y = map(float, lines[0:2])
    finish_x, finish_y = map(float, lines[2:4])
    obstacle_x = list(map(lambda x: float(x.replace(',', '')), lines[4].strip().split(", ")))
    obstacle_y = list(map(lambda x: float(x.replace(',', '')), lines[5].strip().split(", ")))
    obstacle_radius = list(map(lambda x: float(x.replace(',', '')), lines[6].strip().split(", ")))

    # Plot static elements
    ax.scatter(start_x, start_y, color='green', label='Start Point', s=100)
    ax.scatter(finish_x, finish_y, color='red', label='Finish Point', s=100)
    for x, y, r in zip(obstacle_x, obstacle_y, obstacle_radius):
        circle = plt.Circle((x, y), r, color='blue', alpha=1)
        ax.add_artist(circle)
        ax.scatter(x, y, color='blue', s=30)

# Add static content to the plot
read_and_plot("output.txt")

# Create animation
num_frames = coordinates.shape[0]
ani = animation.FuncAnimation(fig, update, frames=num_frames, 
                              init_func=init, blit=True, interval=50)

# Save animation
ani.save('sma_positions.gif', writer='pillow', fps=10)

plt.legend()
plt.show()