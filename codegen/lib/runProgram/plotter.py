import matplotlib.pyplot as plt
import matplotlib.animation as animation
import pandas as pd
import numpy as np

# Read the data from the CSV file
data = pd.read_csv('bestPositions.csv')

# Calculate the number of points (pairs of x,y columns)
num_points = (len(data.columns) - 2) // 2

def get_coordinates(frame):
    x = []
    y = []
    for i in range(num_points):
        x.append(data.iloc[frame, 1 + i*2])
        y.append(data.iloc[frame, 2 + i*2])
    return np.array(x), np.array(y)

# Create figure with a normal size
fig, ax = plt.subplots(figsize=(6, 6))
scat = ax.scatter([], [], s=50, alpha=0.6, c='blue')
fitness_text = ax.text(0.02, 0.95, '', transform=ax.transAxes, 
                      fontsize=9, bbox=dict(facecolor='white', alpha=0.7))

# Get data ranges
x_data = data.iloc[:, 1::2].values.flatten()
y_data = data.iloc[:, 2::2].values.flatten()

# Calculate exact limits from data
x_min, x_max = 0, max(x_data.max(), y_data.max())  # Use same scale for both axes
y_min, y_max = 0, max(x_data.max(), y_data.max())

# Set limits
ax.set_xlim(x_min, x_max)
ax.set_ylim(y_min, y_max)

# Improve grid and axis appearance
ax.grid(True, linestyle='--', alpha=0.3)
ax.set_xlabel('X Position')
ax.set_ylabel('Y Position')
ax.set_title('SMA Position Evolution')

# Make axes equal to preserve aspect ratio
ax.set_aspect('equal')

def init():
    scat.set_offsets(np.empty((0, 2)))
    fitness_text.set_text('')
    return scat, fitness_text

def update(frame):
    x, y = get_coordinates(frame)
    positions = np.column_stack((x, y))
    scat.set_offsets(positions)
    fitness = data.iloc[frame, -1]
    fitness_text.set_text(f'Iteration: {frame+1}\nFitness: {fitness:.2f}')
    return scat, fitness_text

# Create animation
num_frames = len(data)
ani = animation.FuncAnimation(fig, update, frames=num_frames, 
                            init_func=init, blit=True, interval=500)

# Save animation
ani.save('sma_positions.gif', writer='pillow', fps=2)

plt.show()