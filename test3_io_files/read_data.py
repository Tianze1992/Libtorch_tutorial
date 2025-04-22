import numpy as np

# Specify the shape (e.g., read from shape.txt or known beforehand)
nz, nx = 3, 3  # rows × columns

# Read binary data (written as float32)
data = np.fromfile("tensor_out.bin", dtype=np.float32)

# Reshape to 2D if needed
matrix = data.reshape((nz, nx))

print(matrix)