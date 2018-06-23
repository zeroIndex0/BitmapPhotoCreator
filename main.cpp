//
//
//
// main.cpp

// Notes:   Main file for creating bitmaps

#include <iostream>
#include "Bitmap.h"


int main(void) {

    int const WIDTH  = 800;
    int const HEIGHT = 600;

    Bitmap example(WIDTH, HEIGHT);    //sets the size of the bitmap using the constructor

    //An example to loop through each pixel and set it depending on whatever logic you would like
    for(int y = 0; y < HEIGHT; y++) {
        for(int x = 0; x < WIDTH; x++) {
            if((x != WIDTH / 2) && (y != HEIGHT / 2)) {
                example.setPixel(x, y, 0, 0, 255);
            } else {
                example.setPixel(x, y, 0, 255, 0);
            }
        }
    }

    //Another example
    for(int y = 0; y < HEIGHT; y++) {
        for(int x = 0; x < WIDTH; x++) {
            if(x % 50 == 0) {
                example.setPixel(x, y, 255, 0, 0);
            } else if(x % 40 == 0) {
                example.setPixel(x, y, 0, 255, 0);
            } else if(y % 50 == 0) {
                example.setPixel(x, y, 255, 255, 255);
            } else if(y % 40 == 0) {
                example.setPixel(x, y, 255, 0, 255);
            } else {
                example.setPixel(x, y, 0, 0, 0);
            }
        }
    }

    //Lines
    //y = mx + b
    //y = 2x + 1
    for(int x = 0; x < WIDTH; x++) {
        if((2 * x) + 1 > HEIGHT) {
            break;
        } else {
            example.setPixel(x, ((2 * x) + 1), 255, 255, 255);
        }
    }
    //y = 3x + 2
    for(int x = 0; x < WIDTH; x++) {
        if((3 * x) + 2 > HEIGHT) {
            break;
        } else {
            example.setPixel(x, ((3 * x) + 2), 255, 255, 255);
        }
    }

    // y = x^2
    for(int x = 0; x < WIDTH; x++) {
        if(x*x > HEIGHT) {
            break;
        } else {
            example.setPixel(x + 500, (x*x), 255, 255, 255);
        }
    }

    //Circles!
    int r = 100;
    int xOrig = WIDTH / 2;
    int yOrig = HEIGHT / 2;
    for(int y = -r; y <= r; y++) {
        for(int x = -r; x <= r; x++) {
            if( x*x + y*y <= r*r) {
                example.setPixel(x + xOrig, y + yOrig, 255, 255, 120);
            }
        }
    }

    //repeated pattern
    int zoom = 8;
    for(int y = 0; y < HEIGHT; y+=2) {
        for(int x = 0; x < WIDTH; x+=2) {
            int value = ( x / zoom * y / zoom ) % 2;
            if (value) {
                example.setPixel(x, y, 150, 150, 150);
            } else {
                example.setPixel(x, y, 0, 0, 0);
            }
        }
    }


    example.write("test.bmp");   //writes the bitmap and the name passed in will be a created bitmap

    std::cout << "Finished Creating Bitmap Image" << std::endl;

    return 0;
}
