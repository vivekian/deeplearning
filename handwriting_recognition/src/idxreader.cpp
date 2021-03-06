#include "idxreader.h" 
#include "grayscale_img.h" 

#include <cassert> 
#include <sys/stat.h> 
#include <unistd.h> 

using namespace std; 

namespace 
{ 
    bool doesFileExist(const char* filepath)
    { 
        struct stat buffer;   
        return (stat (filepath, &buffer) == 0); 
    }
    
    uint32_t ReadHighEndian(ifstream& fp) 
    { 
        char byte[4] = {0}; 
        fp.read(byte, 4);

        return  (static_cast<uint8_t>(byte[2]) << 8)  | 
                (static_cast<uint8_t>(byte[0]) << 24) | 
                (static_cast<uint8_t>(byte[1]) << 16) | 
                (static_cast<uint8_t>(byte[3]));
    }
    
    const uint32_t IMAGE_MAGIC_NUMBER = 0x00000803; 
    const uint32_t LABEL_MAGIC_NUMBER = 0x00000801; 
}


IdxReader::IdxReader(const char* filepath) 
{ 
    if (!doesFileExist(filepath)) { 
       throw std::runtime_error("file not found\n"); 
    }  

    fp.open(filepath); 
} 

IdxReader::~IdxReader() 
{ 
    if (fp.is_open())
        fp.close(); 
}

void IdxReader::ReadMagicNumber()
{
    uint32_t magicNumber = ReadHighEndian(fp); 

    if ((magicNumber != IMAGE_MAGIC_NUMBER) && 
        (magicNumber != LABEL_MAGIC_NUMBER)) { 
        throw std::runtime_error("idx magic number not found\n"); 
    } 
}

void IdxReader::ReadNumImages() 
{
    numImages = ReadHighEndian(fp);
} 

void IdxReader::ReadDimensions() 
{ 
    rowsPerImage = ReadHighEndian(fp); 
    colsPerImage = ReadHighEndian(fp); 
} 

void IdxReader::ParseLabels(vector<GrayscaleImage>& images) 
{ 
    assert(fp.is_open()); 
    fp.seekg(0); 
    ReadMagicNumber();   
    ReadNumImages();

    if (images.size() != numImages) { 
        throw std::runtime_error("number of images does not match parsed file data\n"); 
    } 

    for (auto& image: images) { 
        fp.read(reinterpret_cast<char*>(&image.label), 1); 
    }
} 

void IdxReader::ParseImages(vector<GrayscaleImage>& images) 
{ 
    assert(fp.is_open()); 
    fp.seekg(0); 
    ReadMagicNumber();
    ReadNumImages();  
    ReadDimensions();

    images.resize(numImages, GrayscaleImage(rowsPerImage, colsPerImage));  

    for (auto& image: images) { 
        image.CopyFileData(fp); 
    } 
} 

