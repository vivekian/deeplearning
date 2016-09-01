#pragma once

#include <fstream> 
#include <vector> 

//! \class GrayScale represents a single grayscale image 
//! 
class GrayScaleImage
{ 
    public: 
        explicit GrayScaleImage(const uint32_t numrows, const uint32_t numcols):
           rows(numrows), cols(numcols) { data.resize(rows * cols); }

        ~GrayScaleImage() { data.clear(); } 

        void CopyFileData(std::ifstream& fp) 
        {
            fp.read(reinterpret_cast<char*>(&data[0]), rows*cols); 
        }

    private: 
        std::vector<uint8_t> data; 
        uint32_t rows; 
        uint32_t cols; 
        uint8_t label; 
};


