#include "GraphicksBase.h"

#include <math.h>

int W, H;

static byte* Frame;

void createGraphicksBase(int width, int heigth, byte* FrameByte)
{
  W = width;
  H = heigth;

  Frame = FrameByte;
}

static double dist(int x1, int y1, int x2, int y2)
{
  return(sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void PutPixel(int x, int y, byte R, byte G, byte B)
{
  if (x >= 0 && x < W && y >= 0 && y < H)
  {
	Frame[y * W * 3 + x * 3 + 0] = R;
	Frame[y * W * 3 + x * 3 + 1] = G;
	Frame[y * W * 3 + x * 3 + 2] = B;
  }
}

void PutLine(int x1, int y1, int x2, int y2, byte R, byte G, byte B)
{
  int j, tmp = 0;

  //swap for correct iteration
  if (x1 > x2)
  {
	x2 = tmp;
	x2 = x1;
	x1 = tmp;
  }
  if (y1 > y2)
  {
	y2 = tmp;
	y2 = y1;
	y1 = tmp;
  }

  if (x1 == x2)
	for (j = y1; j < y2; j++)
	  PutPixel(x1, j, R, G, B);
  else if (y1 == y2)
	for (j = x1; j < x2; j++)
	  PutPixel(j, y1, R, G, B);
}

void PutRect(int x, int y, int w, int h, int R, int G, int B)
{
  PutLine(x, y, x + w, y, R, G, B);
  PutLine(x, y, x, y + h, R, G, B);
  PutLine(x + w, y, x + w, y + h, R, G, B);
  PutLine(x, y + h, x + w, y + h, R, G, B);
}

void PutCircle(int x, int y, int r, int R, int G, int B)
{
  int i, j;

  for (j = 0; j <= r * 2; j++)
	for (i = 0; i <= r * 2; i++)
	  if (dist(x + i, y + j, x + r, y + r) - r >= 0 && dist(x + i, y + j, x + r, y + r) - r < 1)
		PutPixel(x + i, y + j, R, G, B);
}

void MyFillCircle(int x, int y, int r, int R, int G, int B)
{
  int i, j;

  for (j = 0; j < r * 2; j++)
	for (i = 0; i < r * 2; i++)
	  if (dist(x + i, y + j, x + r, y + r) - r < 0.1)
		PutPixel(x + i, y + j, R, G, B);
}

void MyFillRect(int x, int y, int w, int h, int R, int G, int B)
{
  int i, j;

  for (j = 0; j < h; j++)
	for (i = 0; i < w; i++)
	  PutPixel(x + i, y + j, R, G, B);
}
