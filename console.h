//*****************************************************************************
//
//                               c o n s o l e
//
//                       Feb 2017, for linux & windows
//
//
//*****************************************************************************

//#ifndef __linux__
//    #define __linux   1
//#endif


#ifndef _CONSOLE_H
#define _CONSOLE_H

#define XMAX                          80
#define YMAX                          25

#define BLACK                          0
#define RED                            1
#define GREEN                          2
#define YELLOW                         3
#define BLUE                           4
#define MAGENTA                        5
#define CYAN                           6
#define WHITE                          7

#define GRAY                           8
#define H_RED                          9
#define H_GREEN                       10
#define H_YELLOW                      11
#define H_BLUE                        12
#define H_MAGENTA                     13
#define H_CYAN                        14
#define H_WHITE                       15


#define SEC                         1000
#define CURSOR                       224


#define gotoYX(y,x) gotoxy(x,y)

void initConsole(void);
// what4: this call opens the console mode for both systems: linux and windows

void closeConsole(void);
// what4: close the console mode

void textcolor(int c);
// what4: prepare a color for next writing operations
// IN: 0 - 15 see the define-list of colors


void textbackground(int c);
// what4: prepare the back-ground color
// IN: 0 - 7 see the define list of colors

void clrscr(void);
// what4: cleans up the screen

void getxy(int * px, int * py);
// what4: to find out, where the cursor is at the moment
// IN: the adress for the x-and the y-variable to store the result there.

#ifdef __linux__

void gotoxy(int x,int y);
// what4: to set the position of the cursor
// in: X BETWEEN 0 AND 79, Y BETWEEN 0 AND 24

void textcolorRGB(unsigned char r, unsigned char g, unsigned char b);
// what4: to modify the color in an rgb- format (red-green-blue)
// IN: r,g,b between 0 and 255

void textbackgroundRGB(unsigned char r, unsigned char g, unsigned char b);
// what4: to modify the backgroundcolor in an rgb format
// IN: r,g,b between 0 and 255

int kbhit(void);
// what4: to ask for an key-event.
// RETURN: 1 if a key was pressed in the meantime

int getch(void);
// what4: to get the code for a key
// RETURN: a key-code
// NOOTE: for a compare use the defined KEY-WORDS like UP, DOWN, ESC  ...

void delay(int d);
// what4: the system has to wait for a certain time
// IN: the wait-time in msec

void setCursorType (int type);
// what4: to modify the cursor type
// IN: 0: for no cursor

#define UP                            65
#define LEFT                          68
#define RIGHT                         67
#define DOWN                          66
#define ESC                           27



int myPrintf(char * s, ...);
// internal used!
// not public

#define printf                        myPrintf



#else   // windows:

#include <windows.h>
#include <conio.h>



#define BLACK                          0
#define RED                            1
#define GREEN                          2
#define YELLOW                         3
#define BLUE                           4
#define MAGENTA                        5
#define CYAN                           6
#define WHITE                          7

#define GRAY                           8
#define H_RED                          9
#define H_GREEN                       10
#define H_YELLOW                      11
#define H_BLUE                        12
#define H_MAGENTA                     13
#define H_CYAN                        14
#define H_WHITE                       15

#define C_INVISABLE                    0
#define C_SMALL                        1
#define C_MEDIUM                      16
#define C_LARGE                     1024

#define UP                            72
#define LEFT                          75
#define RIGHT                         77
#define DOWN                          80
#define ESC                           27


void setCursorType (int type);
// what4: to modify the cursor type
// IN: 0: for no cursor

void gotoxy(int xpos, int ypos);
// what4: to set the position of the cursor
// in: X BETWEEN 0 AND 79, Y BETWEEN 0 AND 24

void delay(int msec);
// what4: the system has to wait for a certain time
// IN: the wait-time in msec


int getch(void);
// what4: to get the code for a key
// RETURN: a key-code
// NOOTE: for a compare use the defined KEY-WORDS like UP, DOWN, ESC  ...


#endif // __linux__

#endif // _CONSOLE_H


