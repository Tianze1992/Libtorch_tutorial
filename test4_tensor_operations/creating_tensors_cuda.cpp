#include <iostream>
#include <torch/torch.h>

int main(){

    if (!torch::cuda::is_available()){
        std::cerr << "CUDA is not available on this device";
        return -1;
    }
    else{
        std::cout << "Using cuda for calculation" << std::endl;
    }
    // torch::Device device(torch::kCUDA);
    
    torch::Tensor input_4d = torch::rand({1, 2, 32, 64}, torch::dtype(torch::kFloat32)).to(torch::Device(torch::kCUDA));
    std::cout << "this is the size of the tensor" << input_4d.sizes() << std::endl;

    torch::Tensor kernel_2d_h = torch::tensor({{{{ -1, 1,-1 }}}}, torch::dtype(torch::kFloat32)).to(torch::Device(torch::kCUDA));
    std::cout << "this is the size of the kernel h" << kernel_2d_h.sizes() << std::endl; 
    torch::Tensor kernel_2d_v = torch::tensor({{{  {-1}, {1}, {-1}  }}}, torch::dtype(torch::kFloat32)).to(torch::Device(torch::kCUDA));
    std::cout << "this is the size of the kernel v" << kernel_2d_v.sizes() << std::endl;


    torch::nn::functional::Conv2dFuncOptions options_h;
    options_h.padding({0, 1});
    options_h.groups(2);

    torch::nn::functional::Conv2dFuncOptions options_v;
    options_v.padding({1, 0});
    options_v.groups(2);

    torch::Tensor grouped_kernel = kernel_2d_h.repeat({2, 1, 1, 1});

    torch::Tensor output_h = torch::nn::functional::conv2d(input_4d, grouped_kernel, options_h);
    std::cout << "This is the size of the output after convolution" <<  output_h.sizes() << "On device " << output_h.device().str() <<std::endl;
    return 0;
}