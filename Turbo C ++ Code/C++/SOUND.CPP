#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include<fstream.h>
#include<dos.h>
#define C sound(262)
#define d sound(277)
#define D sound(294)
#define e sound(311)
#define E sound(330)
#define F sound(349)
#define f sound(370)
#define G sound(392)
#define a sound(415)
#define A sound(440)
#define b sound(466)
#define B sound(494)
void main()
{
	clrscr();
	E; delay(200); nosound(); delay(2);
	D; delay(200); nosound(); delay(2);
	E; delay(400); nosound(); delay(30);
	for(int i=0;i<2;i++)
	{E;delay(600); nosound(); delay(20);
	B;delay(250); nosound(); delay(20);
	A;delay(600); nosound(); delay(20);
	G;delay(500); nosound(); delay(20);
	f;delay(500); nosound(); delay(20);
	E;delay(700); delay(20);
	}
	nosound();
	getch();
}