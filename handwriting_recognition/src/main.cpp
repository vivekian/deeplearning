#include <iostream> 
#include <vector> 

#include "grayscale_img.h" 
#include "idxreader.h" 
#include "neuralnetwork.h" 

using namespace std; 

int main() 
{ 
    vector<GrayscaleImage> images; 
    
    try { 
        IdxReader imagereader("../data/training/train-images-idx3-ubyte"); 
        IdxReader labelreader("../data/training/train-labels-idx1-ubyte"); 

        imagereader.ParseImages(images); 
        labelreader.ParseLabels(images); 
        
        NeuralNetwork nn({2,3,4}); 
    } catch(...) { 
        cerr << "runtime exception\n"; 
    }

    return 0; 
} 
