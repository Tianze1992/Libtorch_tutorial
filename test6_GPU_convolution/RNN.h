#ifndef RNN_H
#define RNN_H

#include <iostream>
#include <torch/torch.h>


struct RNN : torch::nn::Module
{
    torch::nn::Linear fc1{nullptr}, fc2{nullptr};

    int epoch_count;
    float learning_rate;
    std::string name;

    // Constructor
    RNN(int input_size, int hidden_size, int output_size)
    : epoch_count(0), learning_rate(0.0001), name("My net")
    {
        fc1 = register_module("fc1", torch::nn::Linear(input_size, hidden_size));
        fc2 = register_module("fc2", torch::nn::Linear(hidden_size, output_size));        
    }


    torch::Tensor forward(torch::Tensor x){
        x = torch::relu(fc1->forward(x));
        x = fc2->forward(x);
        return x;
    }
    
};





#endif