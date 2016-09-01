#include <vector> 

#include "idxreader.h" 
#include "grayscale_img.h" 

using namespace std; 

int main() 
{ 
    vector<GrayScaleImage> images; 
    IdxImageReader reader("../data/training/train-images-idx3-ubyte"); 
    reader.ParseImages(images); 
    return 0; 
} 
