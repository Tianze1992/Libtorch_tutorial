#include <iostream>
#include <torch/torch.h>
#include "myfunction.h"

int main()
{
    std::cout << "I am using function 2" << std::endl;
    auto tensor = create_random_tensor2(3, 4);
    return 0;
}