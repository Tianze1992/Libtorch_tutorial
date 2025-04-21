#include "myfunction.h"

torch::Tensor create_random_tensor(int nz, int nx){
    auto tensor = torch::rand({nz, nx});
    std::cout<< tensor << std::endl;
    return tensor;
}