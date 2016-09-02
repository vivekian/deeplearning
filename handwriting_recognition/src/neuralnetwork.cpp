#include "neuralnetwork.h" 

#include <cmath> 
#include <random> 
#include <iostream> 

using std::vector; 

NeuralNetwork::NeuralNetwork(const vector<uint32_t> sizes)
{ 
    weights.resize(sizes.size()); 
    biases.resize(sizes.size()); 

    std::default_random_engine generator;
    std::normal_distribution<double> distribution;

     for (auto i=1; i<weights.size(); ++i) { 
        weights[i].resize(sizes[i]); 
        biases[i].resize(sizes[i]);

        for (auto& w: weights[i]) { 
            w = distribution(generator);
            std::cout << w << std::endl; 
        } 

        for (auto& b: biases[i]) { 
            b = distribution(generator); 
        } 
    }

}

NeuralNetwork::~NeuralNetwork()
{ 
    weights.clear(); 
    biases.clear(); 
}

vector<double> NeuralNetwork::Sigmoid(const vector<double>& in) 
{
    vector<double> ret; 
  
    for (auto &i: in) { 
        ret.emplace_back( 1.0 / (1.0 + std::exp(-i))); 
    }

    return ret;  
}

