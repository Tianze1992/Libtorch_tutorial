import numpy as np

# 创建一个示例矩阵（例如 3x3 的随机矩阵）
matrix = np.ones((3, 3),  dtype=np.float32)


# 保存为二进制文件（扩展名 .npy）
matrix.tofile("matrix.bin")
1
# 保存矩阵的形状信息，供 C++ 读取用
with open("matrix_shape.txt", "w") as f:
    f.write(f"{matrix.shape[0]} {matrix.shape[1]}")
