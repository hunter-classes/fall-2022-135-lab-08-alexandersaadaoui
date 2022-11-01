#include <string>
#include "imageio.h"
#include "funcs.h"

void copy(int img[MAX_H][MAX_W], int result[MAX_H][MAX_W], int h, int w){
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            result[i][j] = img[i][j];
        }
    }
}

void invert(int img[MAX_H][MAX_W], int h, int w){
    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++){
            img[i][j] = 255 - img[i][j];
        }
    }
}

void invert_half(int img[MAX_H][MAX_W], int h, int w){
    for (int i = 0; i < h; i++){
        for (int j = (w/2); j < w; j++){
            img[i][j] = 255 - img[i][j];
        }
    }
}

void box(int img[MAX_H][MAX_W], int h, int w){
    int heightHalf = h/2;
    int heightQuar = h/4;
    int widthHalf = w/2;
    int widthQuar = w/4;

    for (int i = heightQuar; i < (heightHalf + heightQuar); i++){
        for (int j = widthQuar; j < (widthHalf + widthQuar); j++){
            img[i][j] = 255;
        }
    }
}

void frame(int img[MAX_H][MAX_W], int h, int w){
    int heightHalf = h/2;
    int heightQuar = h/4;
    int widthHalf = w/2;
    int widthQuar = w/4;

    for (int i = 0; i < heightHalf; i++){
        for (int j = 0; j < widthHalf; j++){
            if (i == 0 || i == heightHalf - 1 || j == 0 || j == (widthHalf - 1)){
                img[heightQuar + i][widthQuar + j] = 255;
            }
        }
    }
}

void scale(int img[MAX_H][MAX_W], int num[MAX_H][MAX_W], int h, int w){
    for (int i = 0; i < h ; i++){
        for (int j = 0; j < w; j++){
            num[i*2][j*2] = img[i][j];
            num[i*2+1][j*2] = img[i][j];
            num[i*2][j*2+1] = img[i][j];
            num[i*2+1][j*2+1] = img[i][j];
        }
    }
}

void pixelate(int img[MAX_H][MAX_W], int h, int w){
    for (int i = 0; i < h; i = i+2){
        for (int j = 0; j < w; j = j+2){
            int num = 0;
            num += img[i][j];
            num += img[i+1][j];
            num += img[i][j+1];
            num += img[i+1][j+1];
            img[i][j] = num/4;
            img[i+1][j] = num/4;
            img[i][j+1] = num/4;
            img[i+1][j+1] = num/4;
        }
    }
}