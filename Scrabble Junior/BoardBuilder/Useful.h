#pragma once
#include <windows.h>
#include <string>
#include <conio.h>
#define BLACK 0
#define DARKGRAY 8
#define WHITE 15
using namespace std;

void setcolor(unsigned int color, unsigned int background_color);

void clrscr(void); //clear screen

string upper(string word); //capitalize words