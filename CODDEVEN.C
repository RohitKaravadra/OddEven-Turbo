
/* ODD YA EVEN is a simple game created for learning and for fun
    Do not mess with the code it can lead to misbehaviour of the game
			ENJOY THE CODE
*/
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dos.h>

/* structure which holds all the characters usen in the game */

struct characters
{
	char name[11];
	int color,points,win,lose,draw;
}character[10];

/* structure containing all the basic components of the game */

struct game
{
	int player,computer,pruns,cruns,difficulty,toss;
}g;

void hand(int a,int b,int c);
void outline();
void menu();
void matchselect(int a);
void assign();
void match();
int checkresult(int temp);
void pointtable(int arr[]);
void trounament();
void choosedifficulty();
void execute();
int popmenu();

void main()
{
	execute();
}

int popmenu()
{
	int i=3;
	outline();
	textcolor(YELLOW);
	gotoxy(33,12);
	cprintf("SURE TO QUIT?");
	while(i!=1&&i!=0)
	{
		textcolor(YELLOW);
		if(i==3)
		{ gotoxy(36,14); cprintf("< YES >"); }
		else
		{ gotoxy(36,14); cprintf("< NO  >"); }
		textcolor(MAGENTA);
		_setcursortype(0);
		switch(getche())
		{
			case 13: if(i==3) i=1; else i=0;
			break;
			case 77: if(i==3) i=4; else i=3;
				 gotoxy(42,14); cprintf(" "); delay(50);
			break;
			case 75: if(i==4) i=3; else i=4;
				 gotoxy(36,14); cprintf(" "); delay(50);
			break;
		}
	}
	return i;
}

void hand(int a,int b,int c)
{
	if(a==1&&b==0)
	{
		gotoxy(11+c,12); cprintf(" "); gotoxy(11+c,13); cprintf(" "); gotoxy(11+c,14); cprintf(" "); gotoxy(11+c,15); cprintf(" "); gotoxy(11+c,16); cprintf(" "); gotoxy(15+c,17); cprintf(" ");
		gotoxy(12+c,12); cprintf(" "); gotoxy(12+c,13); cprintf(" "); gotoxy(12+c,14); cprintf(" "); gotoxy(12+c,15); cprintf(" "); gotoxy(12+c,16); cprintf(" "); gotoxy(24+c,17); cprintf(" ");
		gotoxy(13+c,12); cprintf(" "); gotoxy(13+c,13); cprintf(" "); gotoxy(13+c,14); cprintf(" "); gotoxy(13+c,15); cprintf(" "); gotoxy(13+c,16); cprintf(" "); gotoxy(23+c,17); cprintf(" ");
		gotoxy(14+c,12); cprintf(" "); gotoxy(14+c,13); cprintf(" "); gotoxy(14+c,14); cprintf(" "); gotoxy(14+c,15); cprintf(" "); gotoxy(14+c,16); cprintf(" "); gotoxy(22+c,17); cprintf(" ");
		gotoxy(15+c,11); cprintf(" "); gotoxy(15+c,12); cprintf(" "); gotoxy(15+c,13); cprintf(" "); gotoxy(15+c,14); cprintf(" "); gotoxy(15+c,15); cprintf(" "); gotoxy(15+c,16); cprintf(" ");
		gotoxy(16+c,11); cprintf(" "); gotoxy(16+c,12); cprintf(" "); gotoxy(16+c,13); cprintf(" "); gotoxy(16+c,14); cprintf(" "); gotoxy(16+c,15); cprintf(" "); gotoxy(16+c,16); cprintf(" ");
		gotoxy(17+c,11); cprintf(" "); gotoxy(17+c,12); cprintf(" "); gotoxy(17+c,13); cprintf(" "); gotoxy(17+c,14); cprintf(" "); gotoxy(17+c,15); cprintf(" "); gotoxy(17+c,16); cprintf(" ");
		gotoxy(18+c,11); cprintf(" "); gotoxy(18+c,12); cprintf(" "); gotoxy(18+c,13); cprintf(" "); gotoxy(18+c,14); cprintf(" "); gotoxy(18+c,15); cprintf(" "); gotoxy(18+c,16); cprintf(" ");
		gotoxy(19+c,11); cprintf(" "); gotoxy(19+c,12); cprintf(" "); gotoxy(19+c,13); cprintf(" "); gotoxy(19+c,14); cprintf(" "); gotoxy(19+c,15); cprintf(" "); gotoxy(19+c,16); cprintf(" ");
		gotoxy(20+c,10); cprintf(" "); gotoxy(20+c,11); cprintf(" "); gotoxy(20+c,12); cprintf(" "); gotoxy(20+c,13); cprintf(" "); gotoxy(20+c,14); cprintf(" "); gotoxy(20+c,15); cprintf(" ");
		gotoxy(21+c,10); cprintf(" "); gotoxy(21+c,11); cprintf(" "); gotoxy(21+c,12); cprintf(" "); gotoxy(21+c,13); cprintf(" "); gotoxy(21+c,14); cprintf(" "); gotoxy(21+c,15); cprintf(" ");
		gotoxy(22+c,10); cprintf(" "); gotoxy(22+c,11); cprintf(" "); gotoxy(22+c,12); cprintf(" "); gotoxy(22+c,13); cprintf(" "); gotoxy(22+c,14); cprintf(" "); gotoxy(22+c,15); cprintf(" ");
		gotoxy(23+c,10); cprintf(" "); gotoxy(23+c,11); cprintf(" "); gotoxy(23+c,12); cprintf(" "); gotoxy(23+c,13); cprintf(" "); gotoxy(23+c,14); cprintf(" "); gotoxy(23+c,15); cprintf(" ");
		gotoxy(24+c,10); cprintf(" "); gotoxy(24+c,11); cprintf(" "); gotoxy(24+c,12); cprintf(" "); gotoxy(24+c,13); cprintf(" "); gotoxy(24+c,14); cprintf(" "); gotoxy(24+c,15); cprintf(" ");
		gotoxy(25+c,11); cprintf(" "); gotoxy(25+c,12); cprintf(" "); gotoxy(25+c,13); cprintf(" "); gotoxy(25+c,14); cprintf(" "); gotoxy(25+c,15); cprintf(" "); gotoxy(25+c,16); cprintf(" ");
		gotoxy(26+c,11); cprintf(" "); gotoxy(26+c,12); cprintf(" "); gotoxy(26+c,13); cprintf(" "); gotoxy(26+c,14); cprintf(" "); gotoxy(26+c,15); cprintf(" "); gotoxy(26+c,16); cprintf(" ");
		gotoxy(27+c,11); cprintf(" "); gotoxy(27+c,13); cprintf(" "); gotoxy(27+c,15); cprintf(" "); gotoxy(27+c,17); cprintf(" "); gotoxy(20+c,17); cprintf(" "); gotoxy(16+c,17); cprintf(" ");
		gotoxy(28+c,11); cprintf(" "); gotoxy(28+c,13); cprintf(" "); gotoxy(28+c,15); cprintf(" "); gotoxy(28+c,17); cprintf(" "); gotoxy(21+c,17); cprintf(" "); gotoxy(17+c,17); cprintf(" ");
		gotoxy(18+c,17); cprintf(" "); gotoxy(19+c,17); cprintf(" "); gotoxy(20+c,16); cprintf(" "); gotoxy(21+c,16); cprintf(" "); gotoxy(22+c,16); cprintf(" "); gotoxy(23+c,16); cprintf(" ");
		gotoxy(24+c,16); cprintf(" "); gotoxy(25+c,17); cprintf(" "); gotoxy(26+c,17); cprintf(" ");
	}
	else if(a==2&&b==0)
	{
		gotoxy(70,12+c); cprintf(" "); gotoxy(70,13+c); cprintf(" "); gotoxy(70,14+c); cprintf(" "); gotoxy(70,15+c); cprintf(" "); gotoxy(70,16+c); cprintf(" "); gotoxy(61,17+c); cprintf(" ");
		gotoxy(69,12+c); cprintf(" "); gotoxy(69,13+c); cprintf(" "); gotoxy(69,14+c); cprintf(" "); gotoxy(69,15+c); cprintf(" "); gotoxy(69,16+c); cprintf(" "); gotoxy(60,17+c); cprintf(" ");
		gotoxy(68,12+c); cprintf(" "); gotoxy(68,13+c); cprintf(" "); gotoxy(68,14+c); cprintf(" "); gotoxy(68,15+c); cprintf(" "); gotoxy(68,16+c); cprintf(" "); gotoxy(59,17+c); cprintf(" ");
		gotoxy(67,12+c); cprintf(" "); gotoxy(67,13+c); cprintf(" "); gotoxy(67,14+c); cprintf(" "); gotoxy(67,15+c); cprintf(" "); gotoxy(67,16+c); cprintf(" "); gotoxy(58,17+c); cprintf(" ");
		gotoxy(66,11+c); cprintf(" "); gotoxy(66,12+c); cprintf(" "); gotoxy(66,13+c); cprintf(" "); gotoxy(66,14+c); cprintf(" "); gotoxy(66,15+c); cprintf(" "); gotoxy(66,16+c); cprintf(" ");
		gotoxy(65,11+c); cprintf(" "); gotoxy(65,12+c); cprintf(" "); gotoxy(65,13+c); cprintf(" "); gotoxy(65,14+c); cprintf(" "); gotoxy(65,15+c); cprintf(" "); gotoxy(65,16+c); cprintf(" ");
		gotoxy(64,11+c); cprintf(" "); gotoxy(64,12+c); cprintf(" "); gotoxy(64,13+c); cprintf(" "); gotoxy(64,14+c); cprintf(" "); gotoxy(64,15+c); cprintf(" "); gotoxy(64,16+c); cprintf(" ");
		gotoxy(63,11+c); cprintf(" "); gotoxy(63,12+c); cprintf(" "); gotoxy(63,13+c); cprintf(" "); gotoxy(63,14+c); cprintf(" "); gotoxy(63,15+c); cprintf(" "); gotoxy(63,16+c); cprintf(" ");
		gotoxy(62,11+c); cprintf(" "); gotoxy(62,12+c); cprintf(" "); gotoxy(62,13+c); cprintf(" "); gotoxy(62,14+c); cprintf(" "); gotoxy(62,15+c); cprintf(" "); gotoxy(62,16+c); cprintf(" ");
		gotoxy(61,10+c); cprintf(" "); gotoxy(61,11+c); cprintf(" "); gotoxy(61,12+c); cprintf(" "); gotoxy(61,13+c); cprintf(" "); gotoxy(61,14+c); cprintf(" "); gotoxy(61,15+c); cprintf(" ");
		gotoxy(60,10+c); cprintf(" "); gotoxy(60,11+c); cprintf(" "); gotoxy(60,12+c); cprintf(" "); gotoxy(60,13+c); cprintf(" "); gotoxy(60,14+c); cprintf(" "); gotoxy(60,15+c); cprintf(" ");
		gotoxy(59,10+c); cprintf(" "); gotoxy(59,11+c); cprintf(" "); gotoxy(59,12+c); cprintf(" "); gotoxy(59,13+c); cprintf(" "); gotoxy(59,14+c); cprintf(" "); gotoxy(59,15+c); cprintf(" ");
		gotoxy(58,10+c); cprintf(" "); gotoxy(58,11+c); cprintf(" "); gotoxy(58,12+c); cprintf(" "); gotoxy(58,13+c); cprintf(" "); gotoxy(58,14+c); cprintf(" "); gotoxy(58,15+c); cprintf(" ");
		gotoxy(57,10+c); cprintf(" "); gotoxy(57,11+c); cprintf(" "); gotoxy(57,12+c); cprintf(" "); gotoxy(57,13+c); cprintf(" "); gotoxy(57,14+c); cprintf(" "); gotoxy(57,15+c); cprintf(" ");
		gotoxy(56,11+c); cprintf(" "); gotoxy(56,12+c); cprintf(" "); gotoxy(56,13+c); cprintf(" "); gotoxy(56,14+c); cprintf(" "); gotoxy(56,15+c); cprintf(" "); gotoxy(56,16+c); cprintf(" ");
		gotoxy(55,11+c); cprintf(" "); gotoxy(55,12+c); cprintf(" "); gotoxy(55,13+c); cprintf(" "); gotoxy(55,14+c); cprintf(" "); gotoxy(55,15+c); cprintf(" "); gotoxy(55,16+c); cprintf(" ");
		gotoxy(54,11+c); cprintf(" "); gotoxy(54,13+c); cprintf(" "); gotoxy(54,15+c); cprintf(" "); gotoxy(54,17+c); cprintf(" "); gotoxy(57,17+c); cprintf(" "); gotoxy(66,17+c); cprintf(" ");
		gotoxy(53,11+c); cprintf(" "); gotoxy(53,13+c); cprintf(" "); gotoxy(53,15+c); cprintf(" "); gotoxy(53,17+c); cprintf(" "); gotoxy(65,17+c); cprintf(" "); gotoxy(64,17+c); cprintf(" ");
		gotoxy(63,17+c); cprintf(" "); gotoxy(62,17+c); cprintf(" "); gotoxy(61,16+c); cprintf(" "); gotoxy(60,16+c); cprintf(" "); gotoxy(59,16+c); cprintf(" "); gotoxy(58,16+c); cprintf(" ");
		gotoxy(57,16+c); cprintf(" "); gotoxy(56,17+c); cprintf(" "); gotoxy(55,17+c); cprintf(" ");
	}
	else if(a==1)
	{
		if(b>=1&&b!=6)
		{
			gotoxy(29,11); cprintf(" "); gotoxy(30,11); cprintf(" "); gotoxy(31,11); cprintf(" "); gotoxy(32,11); cprintf(" "); gotoxy(34,11); cprintf(" ");
			gotoxy(35,11); cprintf(" "); gotoxy(36,11); cprintf(" "); gotoxy(37,11); cprintf(" "); gotoxy(33,11); cprintf(" ");
		}
		if(b>=2&&b!=6)
		{
			gotoxy(29,13); cprintf(" "); gotoxy(30,13); cprintf(" "); gotoxy(31,13); cprintf(" "); gotoxy(32,13); cprintf(" "); gotoxy(33,13); cprintf(" ");
			gotoxy(34,13); cprintf(" "); gotoxy(35,13); cprintf(" "); gotoxy(36,13); cprintf(" "); gotoxy(37,13); cprintf(" "); gotoxy(38,13); cprintf(" ");
		}
		if(b>=3&&b!=6)
		{
			gotoxy(29,15); cprintf(" "); gotoxy(30,15); cprintf(" "); gotoxy(31,15); cprintf(" "); gotoxy(32,15); cprintf(" "); gotoxy(33,15); cprintf(" ");
			gotoxy(34,15); cprintf(" "); gotoxy(35,15); cprintf(" "); gotoxy(36,15); cprintf(" ");
		}
		if(b>=4&&b!=6)
		{
			gotoxy(29,17); cprintf(" "); gotoxy(30,17); cprintf(" "); gotoxy(31,17); cprintf(" "); gotoxy(32,17); cprintf(" "); gotoxy(33,17); cprintf(" ");
		}
		if(b==5||b==6)
		{
			gotoxy(21+c,9); cprintf(" "); gotoxy(22+c,9); cprintf(" "); gotoxy(23+c,9); cprintf(" "); gotoxy(24+c,9); cprintf(" "); gotoxy(22+c,8); cprintf(" ");
			gotoxy(23+c,8); cprintf(" "); gotoxy(24+c,8); cprintf(" "); gotoxy(22+c,7); cprintf(" "); gotoxy(23+c,7); cprintf(" ");
		}
	}
	else
	{
		if(b>=1&&b!=6)
		{
			gotoxy(44,11); cprintf(" "); gotoxy(45,11); cprintf(" "); gotoxy(46,11); cprintf(" "); gotoxy(47,11); cprintf(" "); gotoxy(48,11); cprintf(" ");
			gotoxy(49,11); cprintf(" "); gotoxy(50,11); cprintf(" "); gotoxy(51,11); cprintf(" "); gotoxy(52,11); cprintf(" ");
		}
		if(b>=2&&b!=6)
		{
			gotoxy(44,13); cprintf(" "); gotoxy(45,13); cprintf(" "); gotoxy(46,13); cprintf(" "); gotoxy(47,13); cprintf(" "); gotoxy(48,13); cprintf(" ");
			gotoxy(49,13); cprintf(" "); gotoxy(50,13); cprintf(" "); gotoxy(51,13); cprintf(" "); gotoxy(52,13); cprintf(" "); gotoxy(43,13); cprintf(" ");
		}
		if(b>=3&&b!=6)
		{
			gotoxy(45,15); cprintf(" "); gotoxy(46,15); cprintf(" "); gotoxy(47,15); cprintf(" "); gotoxy(48,15); cprintf(" "); gotoxy(49,15); cprintf(" ");
			gotoxy(50,15); cprintf(" "); gotoxy(51,15); cprintf(" "); gotoxy(52,15); cprintf(" ");
		}
		if(b>=4&&b!=6)
		{
			gotoxy(48,17); cprintf(" "); gotoxy(49,17); cprintf(" "); gotoxy(50,17); cprintf(" "); gotoxy(51,17); cprintf(" "); gotoxy(52,17); cprintf(" ");
		}
		if(b==5||b==6)
		{
			gotoxy(57,9); cprintf(" "); gotoxy(58,9); cprintf(" "); gotoxy(59,9); cprintf(" "); gotoxy(60,9); cprintf(" "); gotoxy(57,8); cprintf(" ");
			gotoxy(58,8); cprintf(" "); gotoxy(59,8); cprintf(" "); gotoxy(58,7); cprintf(" "); gotoxy(59,7); cprintf(" ");
		}
	}
}

void assign()
{
	g.difficulty=2;
	character[0].color=0; strcpy(character[0].name,"  ROHIT  ");
	character[1].color=1; strcpy(character[1].name,"  RAHUL  ");
	character[2].color=2; strcpy(character[2].name,"  RONAK  ");
	character[3].color=3; strcpy(character[3].name,"  PARTH  ");
	character[4].color=7; strcpy(character[4].name,"  VIVEK  ");
	character[5].color=6; strcpy(character[5].name,"  MIRAL  ");
	character[6].color=2; strcpy(character[6].name,"  DEVEN  ");
	character[7].color=3; strcpy(character[7].name,"   RAJ   ");
	character[8].color=7; strcpy(character[8].name,"  ASHISH ");
	character[9].color=6; strcpy(character[9].name,"  TEJASH ");
}
void outline()
{
	int i;
	textbackground(MAGENTA);
	clrscr();
	textbackground(LIGHTGREEN);
	for(i=2;i<80;i++)
	{
		gotoxy(i,1);
		cprintf(" ");
		gotoxy(i,25);
		cprintf(" ");
		if(i<25)
		{
			gotoxy(1,i);
			cprintf("  ");
			gotoxy(79,i);
			cprintf("  ");
		}
		_setcursortype(0);
	}
	textbackground(MAGENTA);
}

void menu()
{
	int i,y=8,x;
	outline();
	do
	{
		for(i=0;i<5;i++)
		{
			textbackground(MAGENTA);
			textcolor(BLACK);
			if(y==8+(2*i))
			textcolor(YELLOW);
			switch(i)
			{
				case 0:gotoxy(32,8);  cprintf("* QUICK  MATCH *");
				break;
				case 1:gotoxy(32,10); cprintf("*  TOURNAMENT  *");
				break;
				case 2:gotoxy(32,12); cprintf("* INSTRUCTIONS *");
				break;
				case 3:gotoxy(32,14); cprintf("*  DIFFICULTY  *");
				break;
				case 4:gotoxy(32,16); cprintf("*     EXIT     *");
				break;
			}
		}
		textcolor(MAGENTA);
		gotoxy(1,1);
		_setcursortype(0);
		x=getche();
		if(x==13)
		{
			switch(y)
			{
				case 8: matchselect(0); y=8; outline();
				break;
				case 10: matchselect(1); y=10; outline();
				break;
				case 14: choosedifficulty(); y=14; outline();
				break;
				case 16: exit(0);
			}
		}
		switch(x)
		{
			case 80:if(y!=16) y=y+2; else y=8;
			break;
			case 72:if(y!=8) y=y-2;  else y=16;
			break;
		}
	}while(1);
}

void matchselect(int a)
{
	int c=0,x;
	g.player=0,g.computer=0;
	outline();
	if(a==0)
	{
		textbackground(character[g.computer].color); hand(2,0,0);
		textbackground(MAGENTA);
		gotoxy(40,14);
		textcolor(15);
		cprintf("VS");
		while(1)
		{
			if(c==0)
			{ textbackground(character[g.player].color); hand(1,0,0); }
			if(c==1)
			{ textbackground(character[g.computer].color); hand(2,0,0); }
			textbackground(MAGENTA);
			gotoxy(13,19);
			textcolor(YELLOW);
			cprintf("<"); cprintf(character[g.player].name); cprintf(">");
			gotoxy(57,19);
			cprintf("<"); cprintf(character[g.computer].name); cprintf(">");
			_setcursortype(0);
			x=getch();
			textcolor(YELLOW);
			if(x==13)
			{
				if(c==2)
				{ match(); break; }
				else if(c==0)
				{
					c=1; x=0;
					gotoxy(15,9);
					cprintf("READY");
					textbackground(character[g.player].color);
					hand(1,6,0);
					continue;
				}
				else if(c==1||c==2)
				{
					gotoxy(62,9);
					cprintf("READY");
					textbackground(character[g.computer].color);
					hand(2,6,0);
					textcolor(MAGENTA); textbackground(MAGENTA);
					x=getche();
					c=2;
					if(x==13)
					{ match(); break; }
				}
			}
			if(x==8)
			{
				if(c==0)
				break;
				else if(c==1)
				{
					c=0;
					gotoxy(15,9);
					cprintf("     ");
					hand(1,6,0);
				}
				else
				{
					c=1;
					gotoxy(62,9);
					cprintf("     ");
					hand(2,6,0);
				}
			}
			switch(x)
			{
				case 75:
					if(c==1)
					{
						if(g.computer>0) g.computer--; else g.computer=9;
						gotoxy(57,19); textcolor(MAGENTA); cprintf("<"); delay(50);
					}
					else if(c==0)
					{
						if(g.player>0) g.player--; else g.player=9;
						gotoxy(13,19); textcolor(MAGENTA); cprintf("<"); delay(50);
					}
				break;
				case 77: if(c==1)
					  {
						if(g.computer<9) g.computer++; else g.computer=0;
						gotoxy(67,19); textcolor(MAGENTA); cprintf(">"); delay(50);
					  }
					  else if(c==0)
					  {
						if(g.player<9) g.player++; else g.player=0;
						gotoxy(23,19); textcolor(MAGENTA); cprintf(">"); delay(50);
					  }
					break;

			}
		}
	}
	else
	{
		while(1)
		{
			textbackground(character[g.player].color);
			hand(1,0,20);
			textbackground(MAGENTA);
			gotoxy(35,19);
			textcolor(YELLOW);
			cprintf("<"); cprintf(character[g.player].name); cprintf(">");
			textcolor(MAGENTA);
			x=getche();
			if(x==8)
			{
				if(c==1)
				{
					c=0;
					gotoxy(35,9);
					cprintf("     ");
					hand(1,6,20);
					continue;
				}
				else
				break;
			}
			else if(x==13)
			{
				if(c==1)
				break;
				else
				{
					c=1;
					textcolor(YELLOW);
					gotoxy(35,9);
					cprintf("READY");
					textbackground(character[g.player].color);
					hand(1,6,20);
					continue;
				}
			}
			if(c==0)
			{
				switch(x)
				{
					case 75:if(g.player>0) g.player--; else g.player=9;
						 gotoxy(35,19); textcolor(MAGENTA); cprintf("<"); delay(50);

					break;
					case 77:if(g.player<9) g.player++; else g.player=0;
						 gotoxy(45,19); textcolor(MAGENTA); cprintf(">"); delay(50);
					break;
				}
			}
		}
		if(x==13)
		trounament();
	}
}

int checkresult(int temp)
{
	if(g.cruns>g.pruns)
	{
		outline();
		textcolor(YELLOW); textbackground(MAGENTA);
		gotoxy(35,13); cprintf(" YOU  LOSE ");
		temp=0;
	}
	else if(temp==0)
	{
		if(g.pruns>g.cruns)
		{
			outline();
			textcolor(YELLOW); textbackground(MAGENTA);
			gotoxy(35,13); cprintf("  YOU WON  ");
			temp=1;
		}
		else
		{
			outline();
			textcolor(YELLOW); textbackground(MAGENTA);
			gotoxy(35,13); cprintf("   DRAW:   ");
			temp=2;
		}
	}
	return temp;
}

void match()
{
	int ch1=0,temp,ch=8,i;
	outline();
	g.pruns=0,g.cruns=0,g.toss=0;
	randomize();
	while(1)
	{
		i=0;
		lb:
		if(ch==8)
		{
			outline();
			textcolor(YELLOW); textbackground(MAGENTA);
			gotoxy(30,4); cprintf(character[g.player].name); cprintf(" VS "); cprintf(character[g.computer].name);
			textbackground(character[g.player].color);
			hand(1,0,0);
			textbackground(MAGENTA); textcolor(YELLOW);
			gotoxy(4,3); cprintf("RUNS:- %d",g.pruns);
			gotoxy(69,3); cprintf("RUNS:- %d",g.cruns);
			gotoxy(38,15);
			cprintf("< 0");cprintf("%d",ch1);cprintf(" >");
		}
		while(1)
		{
			if(kbhit())
			{
				_setcursortype(0);
				gotoxy(1,1);
				textcolor(MAGENTA);
				textbackground(MAGENTA);
				ch=getche();
				if(ch==13)
				{
					textbackground(character[g.computer].color);
					hand(2,0,0);
					break;
				}
				else if(ch==8)
				break;
				if(ch!=13&&ch1!=0)
				{
					hand(1,ch1,0);
					_setcursortype(0);
				}
				switch(ch)
				{
					case 75:if(ch1!=0) ch1--; else ch1=6;
					break;
					case 77:if(ch1!=6) ch1++; else ch1=0;
					break;
				}
				textcolor(YELLOW);
				gotoxy(38,15);
				cprintf("< 0");cprintf("%d",ch1);cprintf(" >");
				if(ch1!=0)
				{
					textbackground(character[g.player].color);
					hand(1,ch1,0);
				}
			}
			else
			{
				textbackground(character[g.computer].color);
				hand(2,0,i); delay(120);
				textbackground(MAGENTA);
				hand(2,0,i);
				if(i==2)
				i=-2;
				else if(i==-2)
				i=2;
				else if(i>-2)
				i--;
				else
				i++;
			}
		}
		if(ch==8)
		{
			if(popmenu())
			break;
			else
			goto lb;
		}
		if(g.toss==0)
		{
			for(i=0;i<g.difficulty;i++)
			{ temp=random(7);  if(temp==ch1) break; }
		}
		else if(g.difficulty==4)
		{
			for(i=0;i<3;i++)
			{ temp=random(7); if(temp!=ch1) break; }
		}
		else
		temp=random(7);
		textbackground(character[g.computer].color);
		hand(2,temp,0);
		textcolor(YELLOW); textbackground(MAGENTA);
		if(ch1==temp)
		{
			gotoxy(39,8); textcolor(RED); cprintf("GONE");
			if(g.toss!=1) g.toss=1;
			else { getche(); break; }
		}
		else
		{
			if(g.toss==0) g.pruns+=ch1;
			else g.cruns+=temp;
		}
		textcolor(YELLOW);
		if(g.toss==0)
		{ gotoxy(11,3); cprintf("%d",g.pruns); }
		else
		{ gotoxy(76,3); cprintf("%d",g.cruns); }
		getche();
		if(ch1==temp)
		{ gotoxy(39,8); cprintf("    "); }
		if(!checkresult(1))
		{ break; }
		if(temp!=0)
		hand(2,temp,0);
		_setcursortype(0);
	}
	checkresult(0);
	textcolor(MAGENTA);
	while(getche()!=13)
	{ gotoxy(1,1); };
}

void pointtable(int arr[])
{
	int i,j;
	outline();
	textbackground(GREEN);
	for(i=8;i<21;i++)
	{
		if(i%2==0)
		{
			for(j=11;j<38;j++)
			{
				gotoxy(j,i); cprintf(" ");
				gotoxy(j+33,i); cprintf(" ");
			}
		}
	}
	for(i=11;i<38;i++)
	{
		if(i==11||i==21||i==25||i==29||i==33||i==37)
		{
			for(j=9;j<20;j++)
			{
				gotoxy(i,j); cprintf(" ");
				gotoxy(i+33,j); cprintf(" ");
			}
		}
	}
	for(i=0;i<10;i++)
	character[i].points=(character[i].win*3)-character[i].lose+character[i].draw;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4-i;j++)
		{
			if(character[arr[j]].points<character[arr[j+1]].points)
			{
				arr[j]=arr[j]+arr[j+1];
				arr[j+1]=arr[j]-arr[j+1];
				arr[j]=arr[j]-arr[j+1];
			}
			if(character[arr[j+5]].points<character[arr[j+6]].points)
			{
				arr[j+5]=arr[j+5]+arr[j+6];
				arr[j+6]=arr[j+5]-arr[j+6];
				arr[j+5]=arr[j+5]-arr[j+6];
			}
		}
	}
	textbackground(MAGENTA); textcolor(YELLOW);
	gotoxy(21,5); cprintf("GROUP A");
	gotoxy(54,5); cprintf("GROUP B");
	for(i=0;i<2;i++)
	{
		gotoxy(12+i*33,9); cprintf("  NAMES  ");
		gotoxy(22+i*33,9); cprintf("WIN");
		gotoxy(26+i*33,9); cprintf("LOS");
		gotoxy(30+i*33,9); cprintf("DRW");
		gotoxy(34+i*33,9); cprintf("PTS");
	}
	for(i=0;i<5;i++)
	{
		if(arr[i]==g.player)
		textbackground(CYAN);
		gotoxy(12,11+i*2); cprintf(character[arr[i]].name);
		textbackground(MAGENTA);
		gotoxy(23,11+i*2); cprintf("%d",character[arr[i]].win);
		gotoxy(27,11+i*2); cprintf("%d",character[arr[i]].lose);
		gotoxy(31,11+i*2); cprintf("%d",character[arr[i]].draw);
		gotoxy(35,11+i*2); cprintf("%d",character[arr[i]].points);
		if(arr[i+5]==g.player)
		textbackground(CYAN);
		gotoxy(45,11+i*2); cprintf(character[arr[i+5]].name);
		textbackground(MAGENTA);
		gotoxy(56,11+i*2); cprintf("%d",character[arr[i+5]].win);
		gotoxy(60,11+i*2); cprintf("%d",character[arr[i+5]].lose);
		gotoxy(64,11+i*2); cprintf("%d",character[arr[i+5]].draw);
		gotoxy(68,11+i*2); cprintf("%d",character[arr[i+5]].points);
	}
	do
	{
		gotoxy(1,1);
		textcolor(MAGENTA);
		i=getche();
		if(i==8)
		menu();
	}while(i!=13);
}

void trounament()
{
	int arr[10],matches[40][2],i,j,temp;
	for(i=0;i<10;i++)
	{
		character[i].win=0;
		character[i].lose=0;
		character[i].draw=0;
		character[i].points=0;
	}
	randomize();
	for(i=0;i<10;i++)
	{
		do
		{
			temp=0;
			arr[i]=random(10);
			for(j=i-1;j>=0;j--)
			{
				if(arr[i]==arr[j])
				{ temp=1; break; }
			}
		}while(temp==1);
	}
	for(i=0;i<2;i++)
	{
		matches[0+10*i][0]=arr[2+i*5]; matches[0+10*i][1]=arr[3+i*5];
		matches[1+10*i][0]=arr[0+i*5]; matches[1+10*i][1]=arr[1+i*5];
		matches[2+10*i][0]=arr[3+i*5]; matches[2+10*i][1]=arr[4+i*5];
		matches[3+10*i][0]=arr[2+i*5]; matches[3+10*i][1]=arr[0+i*5];
		matches[4+10*i][0]=arr[1+i*5]; matches[4+10*i][1]=arr[4+i*5];
		matches[5+10*i][0]=arr[0+i*5]; matches[5+10*i][1]=arr[3+i*5];
		matches[6+10*i][0]=arr[1+i*5]; matches[6+10*i][1]=arr[2+i*5];
		matches[7+10*i][0]=arr[4+i*5]; matches[7+10*i][1]=arr[0+i*5];
		matches[8+10*i][0]=arr[3+i*5]; matches[8+10*i][1]=arr[1+i*5];
		matches[9+10*i][0]=arr[2+i*5]; matches[9+10*i][1]=arr[4+i*5];
	}
	for(i=0;i<10;i++)
	{
		lb:
		pointtable(arr);
		outline();
		textcolor(YELLOW);
		gotoxy(33,3); cprintf("-: QUALIFIERS :-");
		for(temp=0;temp<10;temp++)
		{
			if(temp==i)
			textcolor(YELLOW);
			else if(temp<i)
			textcolor(RED);
			else
			textcolor(GREEN);
			gotoxy(11,5+temp*2);
			cprintf(character[matches[temp][0]].name); cprintf(" VS ");
			cprintf(character[matches[temp][1]].name); gotoxy(49,5+temp*2);
			cprintf(character[matches[temp+10][0]].name); cprintf(" VS ");
			cprintf(character[matches[temp+10][1]].name);
		}
		do
		{
			gotoxy(1,1);
			textcolor(MAGENTA);
			temp=getche();
			if(temp==8)
			goto lb;;
		}while(temp!=13);
		temp=0;
		if(g.player==matches[i][0]||g.player==matches[i][1])
		{
			if(matches[i][0]==g.player)
			{ g.computer=matches[i][1]; match(); }
			else
			{ g.computer=matches[i][0]; match(); }
			temp=1;
		}
		else if((g.player==matches[i+10][0]||g.player==matches[i+10][1]))
		{
			if(matches[i+10][0]==g.player)
			{ g.computer=matches[i+10][1]; match(); }
			else
			{ g.computer=matches[i+10][0]; match(); }
			temp=2;
		}
		if(temp==0)
		{
			temp=random(6);
			if(temp==0||temp==3)
			{
				character[matches[i][0]].win++;
				character[matches[i][1]].lose++;
			}
			else if(temp==1||temp==4)
			{
				character[matches[i][1]].win++;
				character[matches[i][0]].lose++;
			}
			else
			{
				character[matches[i][1]].draw++;
				character[matches[i][0]].draw++;
			}
			temp=random(6);
			if(temp==0||temp==3)
			{
				character[matches[i+10][0]].win++;
				character[matches[i+10][1]].lose++;
			}
			else if(temp==1||temp==4)
			{
				character[matches[i+10][1]].win++;
				character[matches[i+10][0]].lose++;
			}
			else
			{
				character[matches[i+10][1]].draw++;
				character[matches[i+10][0]].draw++;
			}
		}
		else
		{
			if(checkresult(0)==1)
			{
				character[g.player].win++;
				character[g.computer].lose++;
			}
			else if(checkresult(0)==0)
			{
				character[g.computer].win++;
				character[g.player].lose++;
			}
			else
			{
				character[g.computer].draw++;
				character[g.player].draw++;
			}
			if(temp==1)
			{
				temp=random(6);
				if(temp==0||temp==3)
				{
					character[matches[i+10][0]].win++;
					character[matches[i+10][1]].lose++;
				}
				else if(temp==1||temp==4)
				{
					character[matches[i+10][1]].win++;
					character[matches[i+10][0]].lose++;
				}
				else
				{
					character[matches[i+10][1]].draw++;
					character[matches[i+10][0]].draw++;
				}
			}
			else
			{
				temp=random(6);
				if(temp==0||temp==3)
				{
					character[matches[i][0]].win++;
					character[matches[i][1]].lose++;
				}
				else if(temp==1||temp==4)
				{
					character[matches[i][1]].win++;
					character[matches[i][0]].lose++;
				}
				else
				{
					character[matches[i][1]].draw++;
					character[matches[i][0]].draw++;
				}
			}
		}
	}
	outline();
	textcolor(YELLOW);
	gotoxy(33,7); cprintf("-: QUALIFIED :-");
	for(i=0;i<2;i++)
	{
		delay(300);
		gotoxy(26,11+i*3); cprintf(character[arr[0+i]].name);
		delay(300);
		gotoxy(46,11+i*3); cprintf(character[arr[5+i]].name);
	}
	delay(200);
	if(arr[0]==g.player||arr[1]==g.player||arr[5]==g.player||arr[6]==g.player)
	{ gotoxy(33,18); cprintf(" YOU QUALIFIED "); }
	else
	{
		gotoxy(25,18); textcolor(RED);
		cprintf(" YOU ARE OUT OF THE TOURNAMENT ");
	}
	while(getche()!=13) { gotoxy(1,1); textcolor(MAGENTA); }
	outline();
	textcolor(YELLOW);
	gotoxy(32,9); cprintf("-: SEMI FINALS :-");
	gotoxy(11,14);
	cprintf(character[arr[0]].name); cprintf(" VS ");
	cprintf(character[arr[1]].name); gotoxy(49,14);
	cprintf(character[arr[5]].name); cprintf(" VS ");
	cprintf(character[arr[6]].name);
	if(arr[0]!=g.player&&arr[1]!=g.player&&arr[5]!=g.player&&arr[6]!=g.player)
	{
		gotoxy(25,18); textcolor(RED);
		cprintf(" YOU ARE OUT OF THE TOURNAMENT ");
	}
	while(getche()!=13) { gotoxy(1,1); textcolor(MAGENTA); }
	textcolor(YELLOW);
	for(i=0;i<2;i++)
	{
		if(arr[0+i*5]==g.player||arr[1+i*5]==g.player)
		{
			if(arr[0+i*5]==g.player)
			g.computer=arr[1+i*5];
			else
			g.computer=arr[0+i*2];
			lb1:
			match();
			if(checkresult(0)==1)
			matches[0][0+i]=g.player;
			else if(checkresult(0)==0)
			matches[0][0+i]=g.computer;
			else
			goto lb1;
		}
		else
		matches[0][0+i]=arr[random(2)+i*5];
	}
	outline();
	gotoxy(32,9); cprintf("-:    FINALS    :-");
	gotoxy(30,14);
	cprintf(character[matches[0][0]].name); cprintf(" VS ");
	cprintf(character[matches[0][1]].name);
	if(matches[0][0]!=g.player&&matches[0][1]!=g.player)
	{
		gotoxy(25,18); textcolor(RED);
		cprintf(" YOU ARE OUT OF THE TOURNAMENT ");
	}
	while(getche()!=13) { gotoxy(1,1); textcolor(MAGENTA); }
	textcolor(YELLOW);
	if(matches[0][0]==g.player||matches[0][1]==g.player)
	{
		if(matches[0][0]==g.player)
		g.computer=matches[0][1];
		else
		g.computer=matches[0][0];
		lb2:
		match();
		outline();
		if(checkresult(0)==1)
		{ gotoxy(28,13); cprintf(" YOU WON THE TOURNAMENT "); }
		else if(checkresult(0)==0)
		{ gotoxy(27,13); cprintf(character[g.computer].name); cprintf("WON THE TROUNAMENT"); }
		else
		goto lb2;
	}
	else
	{
		temp=matches[0][random(2)]; outline();
		gotoxy(27,13); cprintf(character[temp].name);
		cprintf(" WON THE TOURNAMENT ");
	}
	while(getche()!=13) { gotoxy(1,1); textcolor(MAGENTA); }
}

void choosedifficulty()
{
	int tempdif=g.difficulty,x;
	outline();
	textbackground(MAGENTA); textcolor(YELLOW);
	gotoxy(29,4); cprintf("CHOOSE DIFFICULTY LEVEL");
	while(1)
	{
		textcolor(YELLOW);
		switch(tempdif)
		{
			case 2: gotoxy(34,14); cprintf("<   EASY   >");
			break;
			case 3: gotoxy(34,14); cprintf("< MODERATE >");
			break;
			case 4: gotoxy(34,14); cprintf("<   HARD   >");
			break;
		}
		textcolor(MAGENTA);
		x=getche();
		if(x==13)
		{ g.difficulty=tempdif; break; }
		else if(x==8)
		break;
		switch(x)
		{
			case 75:
				if(tempdif!=2) tempdif--; else tempdif=4;
				gotoxy(34,14); cprintf("<"); delay(50);
			break;
			case 77:
				if(tempdif!=4) tempdif++; else tempdif=2;
				gotoxy(45,14); cprintf(">"); delay(50);
			break;
		}
	}
}

void execute()
{
	assign();
	menu();
}

