//
//
//
// BitmapInfoHeader.h

// Notes:   More formatting for creating bitmaps

#ifndef BITMAPINFOHEADER_H
#define BITMAPINFOHEADER_H

#include<cstdint>

#pragma pack(push, 2)               //force C++ to align everything on two byte bounds and get rid of padding, padding would make this not work.

struct BitmapInfoHeader {
    int32_t headerSize{40};                     //These all add up to 40 bytes, which is why this is set to 40
    int32_t width;
    int32_t height;
    int16_t planes{1};                          //these are int16 bytes.
    int16_t bitsPerPixel{24};                   //these are int16 bytes.  This is set to 24 so it uses one byte (8 bits) for each color in the bitmap
    int32_t compression{0};
    int32_t dataSize{0};
    int32_t horizontalResolution{2400};
    int32_t verticalResolution{2400};
    int32_t colors{0};
    int32_t importantColors{0};
};

#pragma pack(pop)                   //stops the stopped padding

#endif // BITMAPINFOHEADER_H
