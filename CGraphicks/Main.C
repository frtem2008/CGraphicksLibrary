#include <glut.h>
#include <stdlib.h>

#include <windows.h> //for delay between frames
#include <errno.h>  

#include "GraphicksBase.h"

#define CRT_SECURE_NO_WARNINGS //for vs 2022 or 2019

#define W 800
#define H 600

static byte Frame[W * H * 3];

//структуры для координат, скорости и размера "игрока"
struct Coords
{
  int x, y;
} coords; 

struct Speed
{
  int xSpeed, ySpeed;
} speed;

struct Sizw
{
  int w, h;
} size;

void UpdateCoords( void )
{
  coords.x += speed.xSpeed;
  coords.y += speed.ySpeed;

  if (coords.x < 0 || coords.x > W - size.w)
	speed.xSpeed = -speed.xSpeed;

  if (coords.y < 0 || coords.y > H - size.h)
	speed.ySpeed = -speed.ySpeed;
}

void Display()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glPixelZoom(1, -1);
  glRasterPos2d(-1, 1);
  

  MyFillCircle(coords.x, coords.y, size.w / 2, 0, 0, 0); //очистка предидущего положения 

  UpdateCoords();
  MyFillCircle(coords.x, coords.y, size.w / 2, coords.x / 2, 64, coords.x / 2);

  /* demo for all from GraphicksBase.h
  PutPixel(10, 100, 0, 255, 0);
  PutLine(50, 100, 100, 100, 255, 255, 0);
  PutRect(250, 180, 200, 100, 255, 128, 255);
  PutCircle(500, 150, 50, 255, 0, 64);
  MyFillRect(330, 320, 300, 100, 64, 255, 128);
  MyFillCircle(100, 340, 75, 128, 64, 128);
   */
  
  glDrawPixels(W, H, GL_BGR_EXT, GL_UNSIGNED_BYTE, Frame);

  glFlush();
  glutSwapBuffers();
  glutPostRedisplay();
  Sleep(1000 / 60);
}

void Keyboard(byte key, int x, int y)
{
  if (key == (byte)'q' || key == (byte)'Q')
	exit(0);
}

void main( void )
{
  //начайное положение игрока
  coords.x = 100;
  coords.y = 200;
  //скорость игрока по каждой оси
  speed.xSpeed = 1;
  speed.ySpeed = 1;
  //размер игрока (если круг, то должен быть одинаковый)
  size.w = 75;
  size.h = 75;

  createGraphicksBase(W, H, Frame); //For my own lib

  glutInitDisplayMode(GLUT_RGB);
  glutInitWindowPosition(300, 200);
  glutInitWindowSize(W, H);
  glutCreateWindow("AN2 C graphicks");

  glutDisplayFunc(Display);
  glutKeyboardFunc(Keyboard);

  glClearColor(0.30, 0.47, 0.8, 1);
  glutMainLoop();
}