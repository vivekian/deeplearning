#pragma once 

#include <cstdint>
#include <fstream> 
#include <iostream> 
#include <memory> 
#include <vector> 

#include "grayscale_img.h" 

//! IdxReader parses files from the Idx format. 
//! It can read both label and image data files.
class IdxReader
{ 
    public: 
        IdxReader(const char* filepath); 
        ~IdxReader(); 

        void ParseImages(std::vector<GrayscaleImage>& images); 
        void ParseLabels(std::vector<GrayscaleImage>& images); 

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
