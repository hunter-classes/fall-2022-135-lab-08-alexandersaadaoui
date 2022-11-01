#pragma once

void copy(int img[MAX_H][MAX_W], int result[MAX_H][MAX_W], int h, int w);
void invert(int img[MAX_H][MAX_W], int h , int w);
void invert_half(int img[MAX_H][MAX_W], int h, int w);
void box(int img[MAX_H][MAX_W], int h, int w);
void frame(int img[MAX_H][MAX_W], int h, int w);
void scale(int img[MAX_H][MAX_W], int[MAX_H][MAX_W], int h, int w);
void pixelate(int img[MAX_H][MAX_W], int h, int w);
