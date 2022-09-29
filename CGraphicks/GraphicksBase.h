#pragma once
typedef unsigned char byte;

void createGraphicksBase(int width, int heigth, byte* FrameByte);

void PutPixel(int x, int y, byte R, byte G, byte B);
void PutLine(int x1, int y1, int x2, int y2, byte R, byte G, byte B);
void PutRect(int x, int y, int w, int h, int R, int G, int B);
void PutCircle(int x, int y, int r, int R, int G, int B);

void MyFillRect(int x, int y, int w, int h, int R, int G, int B);
void MyFillCircle(int x, int y, int r, int R, int G, int B);

