#include <iostream>
#include <fstream>
#include <vector>
#include <torch/torch.h>

int main()
{
    if (torch::cuda::is_available()) {
        std::cout << "CUDA is available! Running on GPU." << std::endl;
    } else {
        std::cout << "CUDA is NOT available. Running on CPU." << std::endl;
    }

    std::ifstream file("matrix.bin", std::ios::binary);
    if (!file){
        std::cout << "can not open the target file" << std::endl;
        return 1;
    }

    int nz, nx;
    
    std::ifstream shape_file("matrix.txt");
    shape_file >> nz >> nx;

    std::vector<float> data(nz*nx);
    file.read(reinterpret_cast<char*>(data.data()), nz*nx*sizeof(float));

    //turn into the 2D matrix
    std::vector<std::vector<float>> matrix (nz, std::vector<float>(nx));
    
    for (int i = 0; i < nz; i++)
    {
        for (int j = 0; j < nx; j++)
        {
            matrix[i][j] = data[i*nx + j];
        }
        
    }
    for (const auto& row : matrix) {
        for (float val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    // Flatten the matrix
    std::vector<float> flat_data;
    flat_data.reserve(nz * nx);
    for (const auto& row : matrix) {
        flat_data.insert(flat_data.end(), row.begin(), row.end());

    }

    // Create torch::Tensor
    auto options = torch::TensorOptions().dtype(torch::kFloat32).device(torch::kCPU);;
    torch::Tensor tharray = torch::from_blob(flat_data.data(), {nz, nx}, options).clone().to(torch::kCUDA);

    std::cout << tharray << std::endl;
    std::cout << "this is the size of the array " << tharray.sizes() << std::endl;
    std::cout << "Device: " << tharray.device() << std::endl;


    torch::Tensor tharray2 = torch::from_blob(flat_data.data(), {nz, nx}, options).clone().to(torch::kCPU);


    std::ofstream file2("tensor_out.bin", std::ios::out | std::ios::binary);
    if(!file2){
        std::cerr <<  "failed to open file for writing" << std::endl;
        return 1;
    }
    file2.write(reinterpret_cast<char*>(tharray2.data_ptr<float>()), tharray2.numel()*sizeof(float));
    file2.close();



    



    return 0;
}