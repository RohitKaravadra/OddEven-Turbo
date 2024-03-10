#include<windows.h>

//function to produce random number between given argument
int random(int ch)
{
    int a;
    a=rand();
    while(!(a>=0&&a<ch))
    {
        a=rand();
    }
    return a;
}
//function to change cursor type
int _setcursortype(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
    return 0;
}

//function for textbackground color
int textbackground(int ForgC,int BackC)
{
     WORD wColor = ((BackC & 0x0F)<<4) + (ForgC & 0x0F);
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),wColor);
     return 0;
}

//function for text color
int textcolor(int ForgC)
{
     WORD wColor = (ForgC & 0x0F);
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),wColor);
     return 0;
}

//function gotoxy for cursor
BOOL gotoxy( const WORD x, const WORD y )
{
   COORD xy;
   xy.X = x;
   xy.Y = y;
   return SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), xy );
}
