#include <iostream>
#include <torch/torch.h>

int main(){
    torch::Tensor field = torch::rand({1, 32, 64}, torch::kFloat32);
    torch::Tensor kernel = torch::tensor({{{
        {-1, 1, -1},
        {-1, 8, -1},
        {-1, 1, -1},
    }}}, torch::dtype(torch::kFloat32));
    
    std::cout<< "This is the size of the tensor being created. " <<field.sizes() << std::endl;
    std::cout<< "This is the size of the kernel" << kernel.sizes() << std::endl;


    // *** Convolution operation 1D *** //
    // Create a 1D kernel //
    torch::Tensor kernel1D = torch::tensor({{{
        -1, 1, -1,
    }}});
    std::cout << "this is the shape of the 1D kernel " << kernel1D.sizes() << std::endl;


    // Simulate a 2D image: batch=1, channels=1, height=64 width=64
    torch::Tensor input_2d = torch::rand({1, 1, 32, 64}, torch::kFloat32);  // OK for conv1d

    // Define 1D kernel horizontal layout: shape [batch, channels , kernel_size_z, kernel_size_x]
    torch::Tensor kernel_2d_h = torch::tensor({{{{1, -1,  1,}}}}, torch::dtype(torch::kFloat32));
    // Define 1D kernel vertical layout: shape [batch, channels , kernel_size_z, kernel_size_x]
    torch::Tensor kernel_2d_v = torch::tensor({{{ {1}, {-1},  {1},}}}, torch::dtype(torch::kFloat32));

    // Set stride and padding
    torch::nn::functional::Conv2dFuncOptions options_h; options_h.padding({0, 1});
    // Set stride and padding
    torch::nn::functional::Conv2dFuncOptions options_v; options_v.padding({1, 0});

    // Calculating convolution on CPU
    torch::Tensor output_h = torch::nn::functional::conv2d(input_2d, kernel_2d_h, options_h);
    std::cout << "1D Conv Output shape: " << output_h.sizes() << std::endl;  // should be [2, 4, 64]
    torch::Tensor output_v = torch::nn::functional::conv2d(input_2d, kernel_2d_v, options_v);
    std::cout << "1D Conv Output shape: " << output_v.sizes() << std::endl;  // should be [2, 4, 64]



    return 0;
}