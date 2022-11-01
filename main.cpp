#include <iostream>
#include "imageio.h"
#include "funcs.h"

int main()
{
    std::string input = "inImage.pgm";
    int img[MAX_H][MAX_W];
    int h = 0;
    int w = 0;
    readImage(input, img, h, w);
    int result[MAX_H][MAX_W];

    //A
    copy(img, result, h, w);
    invert(result, h, w);
    writeImage("a.pgm", result, h, w);

    //B
    copy(img, result, h, w);
    invert_half(result, h, w);
    writeImage("b.pgm", result, h, w);

    //C
    copy(img, result, h, w);
    box(result, h, w);
    writeImage("c.pgm", result, h, w);

    //D
    copy(img, result, h, w);
    frame(result, h, w);
    writeImage("d.pgm", result, h, w);

    //E
    int num[MAX_H][MAX_W];
    copy(img, result, h, w);
    scale(result, num, h, w);
    writeImage("e.pgm", num, h*2, w*2);

    //F
    copy(img, result, h, w);
    pixelate(result, h, w);
    writeImage("f.pgm", result, h, w);

    return 0;

}