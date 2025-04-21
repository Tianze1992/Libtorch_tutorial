#ifndef MYFUNCTION_H
#define MYFUNCTION_H

#include <torch/torch.h>

torch::Tensor create_random_tensor(int nz, int nx);
torch::Tensor create_random_tensor2(int nz, int nx);

#endif