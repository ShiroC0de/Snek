//*****************************************************************************
//
//                               c o n s o l e
//
//                       Feb 2017, for linux & windows
//
//
//*****************************************************************************
#include "console.h"

#define CONSOLE_MODE_ON   1
#define CONSOLE_MODE_OFF  0

static int cmode;

#ifdef __linux__



#undef printf
#include <stdarg.h>
#include <termios.h>
#include <stdio.h>
#include <unistd.h>   // for read()

static struct termios initial_settings, new_settings;
static int peek_character = -1;


void initConsole(void)
{
    cmode = CONSOLE_MODE_ON;
    tcgetattr(0,&initial_settings);
    new_settings = initial_settings;
    new_settings.c_lflag &= ~ICANON;
    new_settings.c_lflag &= ~ECHO;
    new_settings.c_lflag &= ~ISIG;
    new_settings.c_cc[VMIN] = 1;
    new_settings.c_cc[VTIME] = 0;
    tcsetattr(0, TCSANOW, &new_settings);
    clrscr();
}

void gotoxy(int x,int y)
{
    if (y > 24) y = 1;

    if ((x >= 0) && (x <= 80) && (y >= 0) && (y < 25))
        printf("\033[%d;%df", y, x);
}

void textcolor(int c)
{
    switch(c)
    {
        case BLACK    : textcolorRGB(  0,  0,  0); break;
        case RED      : textcolorRGB(255,  0,  0); break;
        case GREEN    : textcolorRGB(  0,255,  0); break;
        case YELLOW   : textcolorRGB(255,255,  0); break;
        case BLUE     : textcolorRGB(  0,  0,255); break;
        case MAGENTA  : textcolorRGB(  0,255,255); break;
        case CYAN     : textcolorRGB(255,  0,255); break;
        case WHITE    : textcolorRGB(255,255,255); break;
        case GRAY     : textcolorRGB( 63, 63, 63); break;
        case H_RED    : textcolorRGB(127,  0,  0); break;
        case H_GREEN  : textcolorRGB(  0,127,  0); break;
        case H_YELLOW : textcolorRGB(127,127,  0); break;
        case H_BLUE   : textcolorRGB(  0,  0,127); break;
        case H_MAGENTA: textcolorRGB(  0,127,127); break;
        case H_CYAN   : textcolorRGB(127,  0,127); break;
        case H_WHITE  : textcolorRGB(127,127,127); break;
        default       : textcolorRGB(  0,  0,  0);

    }

//     printf("\033[0;%dm",c+30);
}

void textbackground(int c)
{
    switch(c)
    {
        case BLACK   : textbackgroundRGB(  0,  0,  0); break;
        case RED     : textbackgroundRGB(255,  0,  0); break;
        case GREEN   : textbackgroundRGB(  0,255,  0); break;
        case YELLOW  : textbackgroundRGB(255,255,  0); break;
        case BLUE    : textbackgroundRGB(  0,  0,255); break;
        case MAGENTA : textbackgroundRGB(  0,255,255); break;
        case CYAN    : textbackgroundRGB(255,  0,255); break;
        case WHITE   : textbackgroundRGB(255,255,255); break;
        default      : textbackgroundRGB(255,255,255);
    }
    //printf("\033[0;%dm",c+40);
}

void textcolorRGB(unsigned char r, unsigned char g, unsigned char b)
{
    printf("\033[38;2;%d;%d;%dm",r,g,b);
}

void textbackgroundRGB(unsigned char r, unsigned char g, unsigned char b)
{
    printf("\033[48;2;%d;%d;%dm",r,g,b);
}

int kbhit(void)
{
unsigned char ch;
int nread;


    if (peek_character != -1) return 1;
    new_settings.c_cc[VMIN]=0;
    tcsetattr(0, TCSANOW, &new_settings);
    nread = read(0,&ch,1);
    new_settings.c_cc[VMIN]=1;
    tcsetattr(0, TCSANOW, &new_settings);
    if(nread == 1)
    {
        peek_character = ch;
        return 1;
    }
    return 0;
}

int getch(void)
{
char ch;
int ret;

    if(peek_character != -1)
    {
        ch = peek_character;
        peek_character = -1;
    }
    else
    {
        read(0,&ch,1);
    }
    ret = ch;

    if (ch == 27)
    {
        if (kbhit())
        {
            ch = getch();

            if (ch == 91)  ret = 224;

        }
    }

    return ret;
}

void clrscr(void)
{
    textcolor(WHITE);
    textbackground(BLACK);
    printf("\033[2J");
    fflush(stdout);
}

int myPrintf(char * s, ...)
{
va_list arg_ptr;

    va_start(arg_ptr, s);

    vprintf(s, arg_ptr);

    if (cmode == CONSOLE_MODE_ON)
    {
        fflush(stdout);
    }

    va_end(arg_ptr);

    return 0;
}




void delay(int d)
{
     usleep(1000*d);
}

void closeConsole(void)
{
   textcolor(WHITE);
   textbackground(BLACK);
   tcsetattr(0, TCSANOW, &initial_settings);

   //clrscr();
   gotoxy(0,0);
   printf("EL htlstp");
   gotoxy(0,0);
   cmode = CONSOLE_MODE_OFF;
}

void setCursorType (int type)
{
    // do nothing
}



#else   // windows:

#include <windows.h>  // used for SetConsoleTextAttribute ...
#include <conio.h>
#include <time.h>
#include <stdio.h>


static int __BACKGROUND = 0;
static int __FOREGROUND = 0x7;


void initConsole(void)
{
    char text[] = "mode CON: COLS=80 LINES=25";

    system(text);
    textcolor(WHITE);
    cmode = CONSOLE_MODE_ON;
    clrscr();
}

void textcolor (int c)
{
int color = 0;

    switch(c)
    {
        case BLACK    : color =  0; break;
        case RED      : color = 12; break;
        case GREEN    : color = 10; break;
        case YELLOW   : color = 14; break;
        case BLUE     : color =  9; break;
        case MAGENTA  : color = 13; break;
        case CYAN     : color = 11; break;
        case WHITE    : color = 15; break;
        case GRAY     : color =  8; break;
        case H_RED    : color =  4; break;
        case H_GREEN  : color =  2; break;
        case H_YELLOW : color =  6; break;
        case H_BLUE   : color =  1; break;
        case H_MAGENTA: color =  5; break;
        case H_CYAN   : color =  3; break;
        case H_WHITE  : color =  7; break;
        default       : color =  0;
    }

    __FOREGROUND = color;
    color = __FOREGROUND + (__BACKGROUND << 4);
    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), color);
}

void textbackground (int c)
{
int color = 0;

    switch(c)
    {
        case BLACK    : color =  0; break;
        case RED      : color =  4; break;
        case GREEN    : color =  2; break;
        case YELLOW   : color =  6; break;
        case BLUE     : color =  1; break;
        case MAGENTA  : color =  5; break;
        case CYAN     : color =  3; break;
        case WHITE    : color =  7; break;
        default       : color =  0;
    }

    __BACKGROUND = color;
    color = __FOREGROUND + (__BACKGROUND << 4);
    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), color);
}



void clrscr(void)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    char color =  __FOREGROUND + (__BACKGROUND << 4);
    int anzahl = XMAX * YMAX;
    COORD Startpos = {0,0};
    DWORD ergebnis;
    // Anzahl des geschriebenen Zellen

    FillConsoleOutputAttribute( h, color, anzahl, Startpos, &ergebnis);
    FillConsoleOutputCharacter( h,  ' ' , anzahl, Startpos, &ergebnis);
}

void gotoxy(int xpos, int ypos)
{
COORD Screenpos;

    if ( 0 <= xpos && xpos < XMAX &&
         0 <= ypos && ypos < YMAX     )
    {
       Screenpos.X = xpos;
       Screenpos.Y = ypos;
       SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Screenpos);
    }
}

void getxy(int * px, int * py)
{
    int x, y;
    CONSOLE_SCREEN_BUFFER_INFO BufferInfo;
    GetConsoleScreenBufferInfo( GetStdHandle (STD_OUTPUT_HANDLE), &BufferInfo );
    *px = x = BufferInfo.dwCursorPosition.X;
    *py = y = BufferInfo.dwCursorPosition.Y;

}

void setCursorType (int type)
{
	CONSOLE_CURSOR_INFO Info;

    GetConsoleCursorInfo (GetStdHandle (STD_OUTPUT_HANDLE), &Info);
    if (type == 0)
    {
        Info.bVisible = FALSE;
    }
    else
    {
        Info.dwSize = type;
        Info.bVisible = TRUE;
    }

    SetConsoleCursorInfo (GetStdHandle (STD_OUTPUT_HANDLE), &Info);
}


void delay(int msec)
{
    long start = clock();
    // clock() liefert Zeit seit Start des Rechners
    long dauer = msec * (CLOCKS_PER_SEC / 1000);
    // Anpassen an PC speed
    long ende = start + dauer;

    while( clock() < ende );  // haut die Zeit aufwendig tot
}



void closeConsole(void)
{
   textcolor(WHITE);
   textbackground(BLACK);
   // clrscr();
   gotoxy(0,0);
   printf("EL htlstp");
   cmode = CONSOLE_MODE_OFF;
}


#endif // __linux__



