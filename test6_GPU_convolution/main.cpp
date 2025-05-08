#include <iostream>
#include <torch/torch.h>
#include "RNN.h"

int main(){


    RNN rnn(10, 5, 3);

    std::cout<<"this is the number of the epoch count " << rnn.epoch_count<<std::endl;


    return 0;
}