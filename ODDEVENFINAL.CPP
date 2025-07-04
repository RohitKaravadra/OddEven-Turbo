#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<iostream>
#include<fstream>

using namespace std;

int random(int val)
{
	return rand() % val;
}

void gets(char* var)
{
	cin >> var;
}

//class which contains some commonly used parameters in the following code
class common
{
	protected:
	char ch1;
	int toss;
	float overs;
	int difficulty,pruns,pwickets,oruns,owickets;
	int compare();
	void showteams();
	int conversion(char var);
	int conversion(char var[]);
	void init() 	{ pruns=0; pwickets=0; oruns=0; owickets=0; };
	common()
	{ pruns=0; pwickets=0; oruns=0; owickets=0; }
};

class load:public common
{
	protected:
	char str[20],name[20],prop[40];
	float level;
	int newprofile();
	int show(),check(char str1[]);
	void loadfile(int a);
	void update(),profile();
	void levelcheck(int nlevel);
};
void load::update()
{
	ofstream obj(prop);
	obj<<name<<endl;
	obj<<difficulty<<endl;
	obj<<level;
	obj.close();
}

class sounds
{
	protected:
	void winsound();
	void loosesound();
	void startingsound();
	void tosswinsound();
	void tossloosesound();
	void shotsound(int shot);
};

//class which stores the necessary details of opponent
class opponent:public load,public sounds
{
	protected:
	float oovers;
	char opponentsteam[15];
	void opponentsturn();
};


//class which stores the necessary details for the player
class player:public opponent
{
	protected:
	float povers;
	char  playersteam[15];
	void playersturn();
	void commentatory(int shot);
};

class platelates:public player
{
	protected:
	void winning();
	void loosing();
};

//class which allows to store the records of the wins in tournament
class records
{
	protected:
	int tm;
	void showteam(int i);
	void input(int difficulty);
	void output();
};

//class which stores necessary data used to run touranament in following code
class tournament:public platelates,public records
{
	protected:
	int n,teamselection[16];
	void matchselection();
	void matches();
	void getdetails();
	void finalcommentatory();
};

//main class for executing game
class game:public tournament
{
	protected:
	void tossgame();
	void getdetails();
	void quickmatch();
	void tournament();
	void statistics();
	void finalcommentatory();
	void match();
	void superover();
	void instruction();
	void selectteam(int ch,int o);
	void loadingbar();
	void check(){};
	public:
	void execute();
};

void load::loadfile(int a)
{
	int i=1,j=0;
	ifstream obj("load.txt");
	while(!obj.eof())
	{
		obj>>str;
		if(i==a)
		{
			j++;
			strcpy(prop,str); strcat(prop,".bak");
			ifstream obj1(prop);
			obj1>>name;
			obj1>>difficulty;
			obj1>>level;
			obj1.close();
			break;
		}
		i++;
	}
	obj.close();
	if(j==0)
	{
		strcpy(name,"Default");
		difficulty=1;
		level=0.1;
	}
}

int load::show()
{
	system("cls");
	ifstream obj("load.txt");
	obj>>str;
	if(obj.eof())
	{       cout<<"\n\n\t\t\t";
		textcolor(13);
		cprintf("No existing profiles");  getche();
		obj.close();
		return 0;
	}
	else
	{       int c=1; cout<<endl;
		while(!obj.eof())
		{       textcolor(random(14)+1);
			cout<<"\t\t\t"<<c++<<".";cprintf(str);cout<<endl;
			obj>>str;
		}
		c=getche();
		if(c!=8)
		loadfile(conversion(char(c)));
		obj.close();
		if(c==8)
		return 0;
		else
		return 1;
	}
}

int load::check(char str1[])
{
	ifstream obj("load.txt");
	int a=0;   char str2[20];
	while(!obj.eof())
	{       textcolor(2);
		obj>>str2;
		if(strcmp(str2,str1)==0)
		{       a++;
			cout<<"\n\n\n\t\t";
			cprintf("Profile Already Exist");
			getche();
			break;
		}
	}
	obj.close();
	if(a==0)
	return 0;
	else
	return a;
}

int load::newprofile()
{       int c=0;
	textcolor(4);
	system("cls");  cout<<"\n\n\n\t\t";
	cprintf("Enter Profile Name :");
	gets(str);
	strcpy(prop,str);
	c=check(prop);
	if(c==0)
	{
		strcat(prop,".bak");
		ofstream obj("load.txt",ios::app);
		ofstream obj1(prop);
		obj<<str<<endl;
		obj1<<str<<endl;
		strcpy(name,str);   cout<<"\t\t";
		cprintf("Enter difficulty level");cout<<"\n\t\t\t1.Easy\n\t\t\t2.Medium\n\t\t\t3.Hard\n\t";
		difficulty=conversion(char(getche()));
		obj1<<difficulty<<endl;
		level=0.1;
		obj1<<level;
		obj1.close();
		textcolor(2);cout<<"\n\n\t\t";
		cprintf("PROFILE CTREATED");
		getche();
		obj.close();
		return 1;
	}
	else
	return 0;
}

//member function of class game to take necessary input to run the game
void game::getdetails()
{
	textcolor(2);
	update();
	cprintf("Profile :-");cprintf(name);cout<<"\n";cprintf("Level   :-");cout<<level;
	cout<<"\n\n\t\t\t";
	textcolor(13);
	cprintf("1 -Quick match");cout<<"\n\t\t\t";
	cprintf("2 -Tournament");cout<<"\n\t\t\t";
	cprintf("3 -Records");cout<<"\n\t\t\t";
	cprintf("4 -How to play");cout<<"\n\t\t\t";
	cprintf("5 -Exit");cout<<"\n\t\t\t";
	ch1=char(getche());
	switch(ch1)
	{
		case '1':quickmatch();   	break;
		case '2':tournament::getdetails();    tournament();  	break;
		case '3':records::output();   break;
		case '4':instruction();   break;
		case '5':exit(0);
	}
}

//member function of class game which runs quick match if selected by player
void game::quickmatch()
{
	char var[2];
	system("cls");
	cout<<"\n\n\n";
	showteams();
	cout<<"\n\tChoose Your team :";    int tm;
	tm=conversion(gets(var));
	selectteam(tm,1);
	cout<<"\tChoose opponents team (Computer) :";
	tm=conversion(gets(var));
	selectteam(tm,2);
	cout<<"\tChoose overs :";
	overs=conversion(gets(var));
	match();
}


//member function of class game which displayes all the teams on the screen
void common::showteams()
{
	char str[13];  int i=0;
	ifstream obj("teams.bak");    textcolor(10);
	while(i<16)
	{
		i++;  obj>>str;
		cout<<"\t"<<i<<" -";cprintf(str);cout<<"\t";
		i++;  obj>>str;
		cout<<i<<" -";cprintf(str);cout<<"\n";
	}
	obj.close();
}

//memberfunction of class game which selects team chosen by player
void game::selectteam(int ch,int o)
{
	ifstream obj("teams.bak");  int i=0;
	while(i<16)
	{
		i++;
		switch(o)
		{
			case 1:obj>>playersteam;
			break;
			case 2:obj>>opponentsteam;
			break;
		}
		if(ch==i)
		break;
	}
	obj.close();
}

//member function of class game to toss during the game
void game::tossgame()
{       int stroke,b;
	textcolor(3);
	cout<<"\n\t\t";
	cprintf("Now its time for toss");  cout<<endl;
	{textcolor(13);
	cprintf("       (1.ODD)  YA  (2.EVE) :");
	toss=conversion(char(getche()));cout<<endl;
	cprintf("Your stroke :");stroke=conversion(char(getche()));    cout<<endl;
	randomize();
	b=random(7);
	cprintf("Opponents Stroke :");cout<<b<<endl<<"Total :"<<stroke+b;}
	if((stroke+b)%2==0) stroke=2;    else stroke=1;
	textcolor(3);
	cout<<"\n\n\t\t";
	if(toss==stroke)
	{
		cprintf("You won the toss");cout<<endl;
		tosswinsound();
		cout<<"1.Batting\n2.Bowling\n";
		toss=conversion(char(getche()));
	}
	else
	{
		cprintf(opponentsteam); cprintf(" won the toss ");
		toss=random(2)+1;
		if(toss==1)
		cprintf("and choose to ball first");
		else
		cprintf("and choose to bat first");
		cout<<endl;
		tossloosesound();
	}
	if(toss==2)
	{cout<<"\n";opponentsturn();}
	getche();  system("cls");
}

//member function of class player which count necessary data durin proram run
void player::playersturn()
{       randomize();
	int shot,ball;
	textcolor(3);
	cout<<"\t\t"; cprintf("It's Your turn"); cout<<"\n";
	for(int i=1;i<=overs;i++)
	{
		textcolor(9);
		cprintf("OVER -");cout<<i<<"\n\n";
		for(int j=1;j<=6;j++)
		{
			{
				cout<<"\tBall: ";
				textcolor(4);
				for(int m=1;m<=j;m++)
				cprintf("");
				for(m=j;m<=6;m++)
				cout<<"";
				cout<<"\t\t("<<pruns<<"|"<<pwickets<<") ";
				if(toss==2)
				cout<<(oruns-pruns)+1<<" runs in "<<(overs*6)-(((i-1)*6)+(j-1))<<" balls";
				cout<<endl;
			}
			cout<<"\tSHOT: ";
			shot=conversion(getche()); cout<<"\n";
			for(int k=0;k<difficulty+1;k++)
			{
				ball=random(6)+1;
				if(ball==shot)
				break;
			}
			if(ball!=shot)
			{
				commentatory(shot);
				shotsound(shot);
				pruns+=shot;
				if(shot==5)
				j--;
			}
			else
			{
				sound(90);
				commentatory(6+shot);
				delay(200);
				nosound();
				pwickets++;
			}
			povers=((i-1)+((j)/10.0));
			if(pwickets==10||compare()==1)
			break;
		}
		if(pwickets==10||compare()==1)
		break;
		povers=i;
		cout<<"\n\tYour score after "<<i<<" over(s) is ("<<pruns<<"|"<<pwickets<<")\n";
		getche();
		system("cls");
		textcolor(14);
		textbackground(6);
		cout<<"\n\t\t\t";cprintf(playersteam);cprintf(" VS ");cprintf(opponentsteam);cout<<"\n\n";
		textbackground(0);
	}
}

//member function of class opponent to calclate necessary data for opponent(computer)
void opponent::opponentsturn()
{
	int shot,ball,a,b;
	randomize();
	for(int i=0;i<6*overs;i++)
	{
		shot=random(6)+1;
		for(int k=0;k<difficulty;k++)
		{
			ball=random(6)+1;
			if(shot==ball)
			break;
		}
		if(ball!=shot)
		oruns+=shot;
		else
		owickets++;
		a=(i+1)/6;
		b=(i+1)-(a*6);
		oovers=a+(b/10.0);
		if(owickets==10||compare()==1)
		break;
		if(shot==5)
		i--;
	}
	textcolor(5);   cout<<endl;
	cprintf(opponentsteam);
	cout<<" Scored ("<<oruns<<"|"<<owickets<<")"<<" in "<<i/6<<"."<<i%6<<" overs\n";
}

//member function of class common which compares status at a perticular instance
int common::compare()
{
	if(toss==1)
	{	if(oruns>pruns) return 1;
		else return 0;
	}
	else
	{       if(pruns>oruns) return 1;
		else return 0;
	}
}

//member function of class game which runs a part of single match
void game::match()
{
	system("cls");
	textcolor(14);
	textbackground(6);
	cout<<"\n\n\t\t\t";cprintf(playersteam);cprintf(" VS ");cprintf(opponentsteam);cout<<endl;
	textbackground(0);
	tossgame();
	textcolor(14);
	textbackground(6);
	cout<<"\n\n\t\t\t";cprintf(playersteam);cprintf(" VS ");cprintf(opponentsteam);cout<<endl;
	textbackground(0);
	if(toss==1)
	{
		playersturn();
		opponentsturn();
	}
	else
	playersturn();
	finalcommentatory();
}

void game::superover()
{
	init();
	overs=1.0;
	system("cls");
	match();
}

//member function of class game which shows the result of the match
void game::finalcommentatory()
{
	if(pruns>oruns)
	winning();
	else if(pruns<oruns)
	loosing();
	if(toss==2)
	{
		system("cls");
		textcolor(14);
		textbackground(6);
		cout<<"\n\n\t\t\t";cprintf(playersteam);cprintf(" VS ");cprintf(opponentsteam);cout<<endl;
		textbackground(0);
	}
	cout<<"\n\n\t\t";
	textcolor(1);
	if(pruns>oruns)
	{
		level+=0.25;
		textcolor(9);
		cprintf(" YOU WON \nby ");
		switch(toss)
		{
			case 1:cout<<pruns-oruns<<" Runs\n";
			break;
			case 2:cout<<10-pwickets<<" Wickets\n";
			break;
		}
		cout<<endl;
		statistics();
	}
	else if(pruns<oruns)
	{
		textcolor(12);
		cprintf(opponentsteam);cprintf(" WON\nby ");
		switch(toss)
		{
			case 1:cout<<10-owickets<<" Wickets\n";
			break;
			case 2:cout<<oruns-pruns<<" Runs\n";
			break;
		}
		cout<<endl;
		statistics();
	}
	else
	{
		cout<<"\t";
		cprintf("MATCH DRAW ");
		winsound();
		cout<<endl;
		statistics();
		cout<<"\n\n\t\t";   textcolor(3);
		cprintf("Time for super Over\n");
		getche();
		superover();
	}
	getche();
}

//member function of class game which shows calculated data
void game::statistics()
{
	textcolor(3);
	cout<<"\t\t\t"; cprintf("STATISTICS"); cout<<"\n\n";
	cout<<"\t\t\t"<<playersteam<<"\t\t"<<opponentsteam<<"\n\n";
	cout<<"\tRuns\t\t"<<pruns<<"\t\t"<<oruns<<endl;
	cout<<"\tWickets\t\t"<<pwickets<<"\t\t"<<owickets<<endl;
	cout<<"\tOvers played\t"<<povers<<"\t\t"<<oovers<<endl;
	cout<<"\tRun rate\t"<<setprecision(1);
	if(povers!=0) cout<<pruns/povers; else cout<<pruns*6;
	cout<<"rpo\t\t"<<oruns/oovers<<"rpo\n";
}

//member function of class tournament to take necessary input
void tournament::getdetails()
{
	char var[2]; system("cls");
	cout<<"\n\n\n";
	showteams();
	cout<<"\n\tChoose Your team :";
	tm=conversion(gets(var));
	cout<<"\tChoose overs :";
	overs=conversion(gets(var));;
	matchselection();
}


void tournament::matchselection()
{
	int a,c=2;
	randomize();
	a=random(16)+1;
	while(a==tm)
	a=random(16)+1;
	teamselection[0]=tm;
	teamselection[1]=a;
	for(int i=0;i<16;i++)
	{
		if(i+1!=a&&i+1!=tm)
		{ teamselection[c]=i+1;  c++; }
	}
}

void game::tournament()
{       n=8;
	int a,b;
	while(n>0)
	{
		system("cls");
		matches();
		getche();
		if(teamselection[0]==tm)
		{
			selectteam(teamselection[0],1);
			selectteam(teamselection[1],2);
			match();
			if(pruns<oruns)
			teamselection[0]=teamselection[1];
			init();
			b=2;
			for(int j=1;j<n;j++)
			{	a=random(2)+1;
				switch(a)
				{
					case 1:teamselection[j]=teamselection[b];
					break;
					case 2:teamselection[j]=teamselection[b+1];
					break;
				}
				b+=2;
			}
		}
		else
		{       b=0;
			for(int j=0;j<n;j++)
			{	a=random(2)+1;
				switch(a)
				{
					case 1:teamselection[j]=teamselection[b];
					break;
					case 2:teamselection[j]=teamselection[b+1];
					break;
				}
				b+=2;
			}
		}
		n=n/2;
	}
	tournament::finalcommentatory();
}

void tournament::matches()
{
	textbackground(6);
	textcolor(11);
	cout<<"\t\t\t\t";
	switch(n)
	{
		case 8:cprintf("KNOCK OUTS");
		break;
		case 4:cprintf("QUATER FINALS");
		break;
		case 2:cprintf("SEMI FINALS");
		break;
		case 1:cprintf("FINAL");
		break;
	}
	textbackground(0);
	cout<<"\n\n\n\t\t\t";
	for(int i=0;i<n*2;i++)
	{
		if(teamselection[0]==tm&&(i==0||i==1))    textcolor(13); else textcolor(14);
		showteam(teamselection[i]);
		if(i%2==0) cprintf(" VS ");
		else cout<<"\n\n\t\t\t";
	}
}

void tournament::finalcommentatory()
{
	system("cls");
	cout<<"\n\n\n\t\t\t";
	textcolor(13);
	textbackground(1);
	showteam(teamselection[0]);cprintf(" WON THE TOURNAMENT"); cout<<endl;
	textbackground(0);
	if(teamselection[0]==tm)
	{       textcolor(15);
		cprintf("	YOU WON"); cout<<"\n";
		input(difficulty);
	}
	getche();
}

void records::showteam(int i)
{
	int a=1; char team[20];
	ifstream obj("teams.bak");
	while(!obj.eof())
	{	obj>>team;
		if(a==i)
		{  cprintf("(");cprintf(team);cprintf(")"); }
		a++;
	}
	obj.close();
}

void records::output()
{       system("cls");
	char str[30];
	ifstream obj("records.bak");
	{textcolor(14);
	cout<<"\t\t\t";cprintf("LIST OF TOURNAMENT WINNERS");cout<<"\n";}
	obj>>str;
	if(obj.eof())
	cout<<"No Records Found\n";
	else
	{       int a=1;
		while(!obj.eof())
		{
			cout<<"Record number "<<a++<<endl;
			cprintf("NAME  - ");cprintf(str);cout<<endl;
			cprintf("DATE  - ");obj>>str;cprintf(str);cout<<endl;
			cprintf("LEVEL - ");obj>>str;cprintf(str);cout<<endl;
			cprintf("TEAM  - ");obj>>str;cprintf(str);cout<<endl;
			obj>>str;
		}
	}
	obj.close();
	getche();
}
void records::input(int difficulty)
{       char str[30];
	ofstream obj("records.bak",ios::app);
	cout<<endl; cprintf("Save Record");
	cout<<"\nName - "; gets(str);
	obj<<str<<endl;
	cout<<"Date - "; gets(str);
	obj<<str<<endl;
	switch(difficulty)
	{
		case 1:strcpy(str,"Easy");
		break;
		case 2:strcpy(str,"Medium");
		break;
		case 3:strcpy(str,"Hard");
		break;
		default:strcpy(str,"ERROR");
	}
	obj<<str<<endl;
	int a=1;
	ifstream obj1("teams.bak");
	while(!obj1.eof())
	{	obj1>>str;
		if(a==tm)
		break;
		a++;
	}
	obj1.close();
	obj<<str<<endl;
	obj.close();
	cprintf("Record saved "); cout<<endl;
}

int common::conversion(char var)
{
	switch(var)
	{
		case '1':return 1;
		case '2':return 2;
		case '3':return 3;
		case '4':return 4;
		case '5':return 5;
		case '6':return 6;
		default:return 0;
	}
}

int common::conversion(char var[])
{
	if(strcmpi(var,"1")==0)
	return 1;
	else if(strcmpi(var,"2")==0)
	return 2;
	else if(strcmpi(var,"3")==0)
	return 3;
	else if(strcmpi(var,"4")==0)
	return 4;
	else if(strcmpi(var,"5")==0)
	return 5;
	else if(strcmpi(var,"6")==0)
	return 6;
	else if(strcmpi(var,"7")==0)
	return 7;
	else if(strcmpi(var,"8")==0)
	return 8;
	else if(strcmpi(var,"9")==0)
	return 9;
	else if(strcmpi(var,"10")==0)
	return 10;
	else if(strcmpi(var,"11")==0)
	return 11;
	else if(strcmpi(var,"12")==0)
	return 12;
	else if(strcmpi(var,"13")==0)
	return 13;
	else if(strcmpi(var,"14")==0)
	return 14;
	else if(strcmpi(var,"15")==0)
	return 15;
	else if(strcmpi(var,"16")==0)
	return 16;
	else
	return 1;
}

void platelates::winning()
{
	int gd=DETECT,gm=0;
	initgraph(&gd,&gm,"c://turboc3//bgi");
	setcolor(GREEN);
	for(int i=0;i<7;i++)
	{
		cleardevice();
		settextstyle(1,0,1+i);
		outtextxy(150,200,"YOU WON");
		delay(100);
	}
	randomize();
	for( i=0;i<2000;i++)
	{
		putpixel(random(650),random(480),random(14)+1);
		putpixel(random(650),random(480),random(14)+1);
		delay(1);
	}
	winsound();
	getche();
	closegraph();
}

void platelates::loosing()
{
	int gd=DETECT,gm=0;
	initgraph(&gd,&gm,"c://turboc3//bgi");
	setcolor(RED);
	for(int i=0;i<7;i++)
	{
		cleardevice();
		settextstyle(1,0,1+i);
		outtextxy(150,200,"YOU LOOSE");
		delay(100);
	}
	randomize();
	for( i=0;i<1000;i++)
	{
		putpixel(random(650),random(480),4);
		putpixel(random(650),random(480),12);
		delay(1);
	}
	loosesound();
	getche();
	closegraph();
}
void player::commentatory(int shot)
{
	int i=0;
	cout<<"\t\t";
	if(shot<7)
	textcolor(2);
	else
	textcolor(6);
	char str[70];
	ifstream obj("commentary.bak");
	while(!obj.eof())
	{       i++;
		obj.getline(str,70);
		if(i==shot)
		break;
	}
	cprintf(str);
	cout<<"\n\n";
	obj.close();
}

void game::instruction()
{
	system("cls");
	textcolor(11);     char str[250];
	ifstream obj("instructions.bak");
	while(!obj.eof())
	{
		obj.getline(str,250);
		cprintf(str);
		cout<<endl;
		delay(200);
	}
	obj.close();
	getche();
};

void game::loadingbar()
{
	_setcursortype(0);
	textbackground(3);
	for(int i=0;i<78;i++)
	{
		window(2+i,20,80,21);
		cprintf(" ");
		delay(20+i);
		if(i==random(78)+1)
		sleep(1);
		window(2,22,15,23);
		cout<<"LOADING..."<<i+23<<"%";
	}
	sleep(1);
	system("cls");
	int a=0;
	ifstream obj("commentatory.bak", ios::_Nocreate);
	if(!obj)
	{ cout<<"FILE 'commentatory.bak' is missing\n"; a++; }
	obj.close();
	obj.open("instructions.bak", ios::_Nocreate);
	if(!obj)
	{ cout<<"FILE 'instructions.bak' is missing\n"; a++; }
	obj.close();
	obj.open("teams.bak", ios::_Nocreate);
	if(!obj)
	{ cout<<"FILE 'teams.bak' is missing\n"; a++;}
	obj.close();
	if(a!=0)
	{	getche(); exit(0);	}
	obj.open("load.txt",ios::nocreate);
	if(!obj)
	{
		ofstream obj1("load.txt");
		obj1.close();
	}
	obj.close();
	obj.open("records.bak",ios::nocreate);
	if(!obj)
	{
		ofstream obj1("records.bak");
		obj1.close();
	}
	obj.close();
}

void load::levelcheck(int nlevel)
{
	if(level==nlevel+1)
	{
		int gd=DETECT,gm=0;
		initgraph(&gd,&gm,"c://turboc3//bgi");
		for(int i=0;i<14;i++)
		{
			cleardevice();
			setcolor(i+1);
			settextstyle(1,0,7);
			outtextxy(150,200,"LEVEL UP");
			delay(100);
		}
		getche();
		closegraph();
		nlevel=level;
	}
}

void game::execute()
{
	loadingbar();
	textmode(2);
	textcolor(14);
	cprintf("RBK Production Presents");
	int a=0,b=1,c=81,d=25;
	for(int i=1;i<13;i++)
	{	textbackground(i+4);
		window(a+i,b+i,c-i,d-i);
		_setcursortype(0);
		for(int j=0;j<(d-b);j++)
		insline();
		delay(110);
	}
	cout<<"\t\t";  cprintf("   THE ODD YA EVE CRICKET ");
	window(1,25,80,25);
	startingsound();
	textbackground(0);
	sleep(1);
	profile();
	int nlevel;
	nlevel=level;
	while(1)
	{ system("cls"); levelcheck(nlevel); init();getdetails(); }
}

void load::profile()
{       lb:                  textcolor(11); textbackground(2);
	system("cls");  int a;
	cprintf("RBK |-");  cout<<"\t\t\t";
	cprintf("Profile");cout<<"\n\n\t\t\t";      textbackground(0);
	cprintf("1.New");cout<<"\n\t\t\t";
	cprintf("2.Load");cout<<"\n\t\t\t";
	cprintf("3.exit");cout<<"\n\t\t";
	switch(char(getche()))
	{
		case '1':a=newprofile();
		break;
		case '2':a=show();
		break;
		case '3':exit(0);
		break;
		default:a=0;
	}
	if(a==0) goto lb;
}
void sounds::winsound()
{
	sound(400); delay(100);
	sound(300); delay(100);
	sound(200); delay(100);
	sound(500); delay(200);
	nosound();
}

void sounds::loosesound()
{
	sound(100); delay(200);
	sound(90);  delay(300);
	nosound();
}

void sounds::tosswinsound()
{
	sound(300); delay(100);
	sound(200); delay(100);
	sound(400); delay(200);
	nosound();
}

void sounds::tossloosesound()
{
	sound(100); delay(100);
	sound(200); delay(100);
	sound(100); delay(100);
	sound(90); delay(200);
	nosound();
}

void sounds::startingsound()
{
	sound(100); delay(100);
	sound(200); delay(100);
	sound(150); delay(100);
	sound(300); delay(200);

	sound(200); delay(100);
	sound(300); delay(100);
	sound(250); delay(100);
	sound(400); delay(200);

	sound(300); delay(100);
	sound(400); delay(100);
	sound(350); delay(100);
	sound(500); delay(200);

	sound(400); delay(100);
	sound(500); delay(100);
	sound(450); delay(100);
	sound(600); delay(200);

	nosound(); delay(100);
	sound(600); delay(500);
	nosound();
}

void sounds::shotsound(int shot)
{
	switch(shot)
	{
		case 1: sound(200); delay(100);
			sound(250); delay(100);
		break;
		case 2:	sound(250); delay(100);
			sound(300); delay(100);
		break;
		case 3: sound(300); delay(100);
			sound(350); delay(100);
		break;
		case 4: sound(350); delay(100);
			sound(400); delay(100);
		break;
		case 5: sound(400); delay(100);
			sound(450); delay(100);
		break;
		case 6: sound(450); delay(100);
			sound(500); delay(100);
			sound(550); delay(100);
		break;
		default:sound(200); delay(100);
	}
	nosound();
}


void main()
{
	system("cls");
	game g;
	g.execute();
	getch();
}
