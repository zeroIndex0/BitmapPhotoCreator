//
//
//
// Bitmap.cpp

// Notes:   A bitmap class

#include <fstream>
#include "Bitmap.h"
#include "BitmapInfoHeader.h"
#include "BitmapFileHeader.h"


Bitmap::Bitmap(int width, int height) : m_width(width), m_height(height), m_pPixels(new uint8_t[height*width*3]{}) {} //height*width*3 sets each pixel to 3 bytes

// (x, y) is the coordinate of the pixel you're looking at
void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue) {

    uint8_t *pPixel = m_pPixels.get();          // .get() allows access to the goods of the pointer

    pPixel += (y * 3) * m_width + (x * 3);      // multiply x and y by three since each pixel has three bytes ( red, green, blue)
                                                // y * m_width is the number of bytes in all the rows before x
                                                // so this moves us to the right row, then x moves us to the right column
                                                // y * m_width = row to be on;   x = column to be on
                                                // ( y * 3) and (x * 3) means that each is 3 bytes since there is a rgb value we are storing as well

    //These are set in reverse order since a bitmap format is set to little endian
    pPixel[0] = blue;
    pPixel[1] = green;
    pPixel[2] = red;

}

// Where the real magic is
bool Bitmap::write(std::string filename) {

    BitmapFileHeader fileHeader;
    BitmapInfoHeader infoHeader;

    fileHeader.fileSize   = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) + m_width * m_height * 3;
    fileHeader.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);

    infoHeader.height = m_height;
    infoHeader.width  = m_width;

    std::ofstream file;
    file.open(filename, std::ios::out|std::ios::binary); //ios::out|ios::binary are set flags to indicate that this is an out stream that writes binary
    if(!file) {
        return false;   //file failed to open or cannot be written to, return false to indicate there is a problem
    }

    //file.write(char * address, number of bytes to write)
    file.write((char *)&fileHeader, sizeof(fileHeader));         //the first argument has to be a char * so it needs to be cast
    file.write((char *)&infoHeader, sizeof(infoHeader));         //the first argument has to be a char * so it needs to be cast
    //the number of bytes to write here is the total number of pixels for the bitmap (width * height * ( 3 pixel bytes )
    file.write((char *)m_pPixels.get(), m_width * m_height * 3); //unique_ptr.get() allows you to get the real deal pointer from a shared pointer allowing it to be cast
    file.close();
    if(!file) {
        return false;  //file failed return false to indicate there is a problem
    }

    //everything worked so
    return true;

}

Bitmap::~Bitmap() {} //we are using smart pointers so the destructor currently is not being used
