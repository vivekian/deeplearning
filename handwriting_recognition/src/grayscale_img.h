#pragma once

#include <fstream> 
#include <vector> 

//! GrayScale represents a single grayscale image with data and its label.
//! It can read data from a filestream object and copy it over to internal buffer.
class GrayscaleImage
{ 
    public: 
        explicit GrayscaleImage(const uint32_t numrows, const uint32_t numcols):
           rows(numrows), cols(numcols) 
        { 
            data.resize(rows * cols);
        }

        ~GrayscaleImage() 
        { 
            data.clear();
        }

        void CopyFileData(std::ifstream& fp) 
        {
            fp.read(reinterpret_cast<char*>(&data[0]), rows*cols); 
        }

        uint8_t label; 

    private: 
        std::vector<uint8_t> data; 
        uint32_t rows; 
        uint32_t cols; 
};
