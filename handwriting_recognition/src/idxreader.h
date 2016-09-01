#pragma once 

#include <cstdint>
#include <iostream> 
#include <fstream> 
#include <memory> 
#include <vector> 

#include "grayscale_img.h" 

class IdxReader
{ 
    public: 
        IdxReader(const char* filepath); 
        ~IdxReader(); 

        void ParseImages(std::vector<GrayScaleImage>& images); 
        void ParseLabels(std::vector<GrayScaleImage>& images); 

        IdxReader(const IdxReader &) = delete; 
        IdxReader& operator=(const char* filepath) = delete; 
    
    private: 
        void ReadMagicNumber(); 
        void ReadNumImages(); 
        void ReadDimensions();
        
        uint32_t numImages; 
        uint32_t rowsPerImage; 
        uint32_t colsPerImage;         
        std::ifstream fp;
}; 
