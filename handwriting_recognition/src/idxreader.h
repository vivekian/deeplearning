#pragma once 

#include <cstdint>
#include <iostream> 
#include <fstream> 
#include <memory> 
#include <vector> 

#include "grayscale_img.h" 

class IdxImageReader
{ 
    public: 
        IdxImageReader(const char* filepath); 
        ~IdxImageReader(); 

        void ParseImages(std::vector<GrayScaleImage>& images); 

        IdxImageReader(const IdxImageReader &) = delete; 
        IdxImageReader& operator=(const char* filepath) = delete; 
    
    private: 
        void ReadMagicNumber(); 
        void ReadNumImages(); 
        void ReadDimensions();
        
        uint32_t numImages; 
        uint32_t rowsPerImage; 
        uint32_t colsPerImage;         
        std::ifstream fp;
}; 
