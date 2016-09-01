#include <vector> 

#include "idxreader.h" 
#include "grayscale_img.h" 

using namespace std; 

int main() 
{ 
    vector<GrayScaleImage> images; 
    IdxReader imagereader("../data/training/train-images-idx3-ubyte"); 
    IdxReader labelreader("../data/training/train-labels-idx1-ubyte"); 

    imagereader.ParseImages(images); 
    labelreader.ParseLabels(images); 
    return 0; 
} 
