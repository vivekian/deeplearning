#pragma once

#include <vector> 

class NeuralNetwork
{
    public:  
        NeuralNetwork (const std::vector<uint32_t> sizes); 
        ~NeuralNetwork(); 
        
        std::vector<double> Sigmoid(const std::vector<double>& in); 
    
    private: 
        std::vector<std::vector<double>> weights; 
        std::vector<std::vector<double>> biases;  
}; 
