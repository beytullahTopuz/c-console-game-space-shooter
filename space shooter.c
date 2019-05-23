/*
	Name:SPACE SHOOTER
	Copyright:Open Source
	Author:Beytullah Topuz
	Date: 05.05.19 13:53
	Description:SPACE SHOOTER WITH C ALGORITHM
*/
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include <time.h>
#include<windows.h>
#include<unistd.h>
#include<stdlib.h>
#include <malloc.h>
#include<stdbool.h>

int mermix,mermiy,kayax,kayay,gemix,gemiy,kaya2x,kaya2y,kaya3x,kaya3y;
int kayasilx,kayasily;
int kayakontrol=0;
int kaya2kontrol=0;
int kaya3kontrol=0;
int can =10;
int timer=60;
int ates=0;
int kontrol=1;
int kontrol2=0;
int level=1;
int k=0;

void gotoxy(short x, short y) {
	HANDLE hConsoleOutput;
	COORD Cursor_Pos = {x-1, y-1};

	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_Pos);
}

//---------------------------------VERÝ YAPILARI-------------------------------------------------------------------------------------------
struct ship{


    char name[20];


    struct ship *next;

}uzay;

struct ship * head;

void insertShip(char i[20])
{
    struct ship *newship = (struct ship*)malloc(sizeof(struct ship));
    strcpy(newship->name, i);

    newship->next= head;

    head=newship;

}

void printName()
{
    struct ship *p = head;


    while(p != NULL)
    {
        printf("%s\n",p->name);
        p=p->next;
    }
}

int sure(int x, int y)
{
	Sleep(1000);
	timer--;
	gotoxy(x,y);
	printf("%d ", timer);
    sure(x,y);
	return timer;
}
//----------------------------------------------kuyruk yapýlarý---------------------------------------------------------------------------------------
int MAXSIZE = 6;

int front = 0;

int rear = -1;

int count = 0;

int arr[6];

int peek()
{
    return arr[front];
}

bool isEmpty()
{
    return count == 0;
}

bool isFull()
{
    return count == MAXSIZE;
}

int size()
{
    return count;
}

int enqueue(int data)
{
    if(!isFull())
    {
        if(rear == MAXSIZE-1)
        {
            rear = -1;
        }

        arr[++rear] = data;
        count++;
    }
    else
    {
      printf("%c ",enqueue);
      return 1;
    }

}
int dequeue()
{
    if(!isEmpty())
    {
        int data = arr[front++];

        if(front == MAXSIZE)
        {
            front = 0;
        }

        count--;

        return data;
    }
    else
    {
        printf("queue bos\n");
        return -1;
    }
}

//------------------------------------------------------------------------------------------------------------------------------------------

void loading()
{
    printf("  ___           __________      ____________    ______      ____   _        _    ___________                \n");
    printf("  | |          /  _______ \\   /  __________ \\  | ____ \\     |  |  | \\      | |  |  _________|     \n");
    printf("  | |         |  /       \\ |  | /         \\ |  | |   \\ \\    |  |  | \\\\     | |  | |                  \n");
    printf("  | |         | |        | |  | |         | |  | |    \\ \\ \  |  |  | |\\\\    | |  | |                       \n");
    printf("  | |         | |        | |  | |_________| |  | |     \\ \\ \ |  |  | | \\\\   | |  | |    ____                \n");
    printf("  | |         | |        | |  | |_________| |  | |     / /  |  |  | |  \\\\  | |  | |   |___ \\                 \n");
    printf("  | |         | |        | |  | |         | |  | |    / /   |  |  | |   \\\\ | |  | |       \\ \\\               \n");
    printf("  \\  \\_____   |  \\______/  |  | |         | |  | |___/ /    |  |  | |    \\\\| |  | |_______/ /                      \n");
    printf("   \\________|  \\__________/   |_|         |_|  |______/     |__|  |_|     \\\__|   \\_________/                            \n");
}

void yukleme(int x,int y)
{

  	gotoxy(x,y);
  	printf("%c",176);
}

void box(int x,int y)
{
	gotoxy(x,y);
	printf("%c",176);
}
void cerceve()
{
	int i=0;
	int j=0;
	for (i;i<90;i++)
	{
		box(i,j);
	}
	for(j;j<30;j++)
	{
		box(i+1,j);
	}
	for(i;i>0;i--)
	{
		box(i,j);
	}
}

void gemi(int x,int y)
{
	gemix=x; gemiy=y;
	gotoxy(gemix-2,gemiy); printf("_");
	gotoxy(gemix-1,gemiy); printf("_");
	gotoxy(gemix,gemiy);   printf("I");
	gotoxy(gemix+1,gemiy); printf("_");
	gotoxy(gemix+2,gemiy); printf("_");
}

void kaya1(int x,int y)
{
	kayax=x; kayay=y;
    gotoxy(kayax,kayay); printf("/-\\");
    gotoxy(kayax,kayay+1); printf("\\_/");
}
void kaya2(int x,int y)
{
	kaya2x=x; kaya2y=y;
    gotoxy(kaya2x,kaya2y); printf("/-\\");
    gotoxy(kaya2x,kaya2y+1); printf("\\_/");
}
void kaya3(int x,int y)
{
	kaya3x=x; kaya3y=y;
    gotoxy(kaya3x,kaya3y); printf("/-\\");
    gotoxy(kaya3x,kaya3y+1); printf("\\_/");
}
void yukselmek()
{
	if(mermiy==2)
	{
		ates=0;
	}
}

void mermi(int x,int y)
{
	mermix=x; mermiy=y;
	gotoxy(mermix,mermiy);
	printf("|");
	mermiy--;
}


void dusmek()
{
	if(	kayay==30)
	{
		kayay=2;
	}
}
int randomkayaat()
{
			if(kayakontrol==1)
			{
				return 1;
			}
		else
		{
			srand(time(NULL));
			kayax = rand()%80;
			kayasilx=kayax;
			kayasily=kayay;
			kaya1(kayax,kayay);
			kayay++;
			dusmek();
			return 0;
		}

}
void dusmek2()
{
	if(kaya2y>=30)
	{
		kaya2y=2;
	}
}
int randomkayaat2()
{
			if(kaya2kontrol==1)
			{
				return 1;
			}
			else
			{
				srand(time(NULL));
				kaya2x = rand()%40;
				kaya2(kaya2x,kaya2y);
				kaya2y+=3;
				dusmek2();
				return 0;
			}
}
void dusmek3()
{
		if(kaya3y==30)
	{
		kaya3y=2;
	}
}
int randomkayaat3()
{
			if(kaya3kontrol==1)
			{
				return 1;
			}
			else{
				srand(time(NULL));
				kaya3x = rand()%77;
				kaya3(kaya3x,kaya3y);
				kaya3y+=2;
				dusmek3();
				return 0;
			}

}

void kayalariat()
{
	randomkayaat();
	randomkayaat2();
	randomkayaat3();
}

int main(void)
{
		system("color 0D");
		unsigned char tus;
		int dx=0;
		int dy=0;
		int tempmermix;
		char isimGir[20];
		int isimGir2;
		int bekle;

//----------------------------------------------------------------------------------------------------------------------------
		while(1)
	{
		int secim;
		printf("space shooter oyununa hosgeldiniz\n");
		printf("(1) oyna \n");
		printf("(2) nasil oynanir\n");
		printf("(3) gemine isim sec\n");
		printf("(4) oynayanlar listesi\n");
		printf("(5) exit\n");
		beytullah:
		scanf("%d",&secim);
		if(secim==1)//------------------OYUNU OYNAMA BÖLÜMÜ---------------------------------------------------------------------------------
		{
			int k=0;

			for(bekle=0;bekle<20;bekle++)
			{	cerceve();
			gotoxy(1,10);
				loading();
				Sleep(10);
				system("CLS");
				

			}

					while(1)
		{
			cerceve();
			gotoxy(97,2);
			printf("kalan can : %d",can);
			gotoxy(97,4);
			printf("gamer:");
			gotoxy(104,4);
			printName();
			gotoxy(97,6);
			printf("level :%d",level);
			gotoxy(97,5);
			//printf("kayax :%d  kayay(%d)",kayax,kayay);
			gotoxy(97,6);
			//printf("kontrol (%d)",kontrol);
				gotoxy(97,8);
			printf("Score :%d ",k);
			 if(kbhit())
	 		 {
	
			 tus=getch();
			 if(tus==224)
			 {
				tus=getch();
	
				switch(tus)
				{
					case 72: //yukarý yön tuþu
	
					mermiy=gemiy;
					tempmermix=gemix;
	
						break;
					case 80: //aþaðý yön tuþu
	
	
						break;
					case 77: dx=3; dy=0;//sað yön tuþu
						break;
					case 75: dx=-3; dy=0;//sol yön tuþu
						break;
				 }
			 }
	
			 if(tus==113)
			 {
			     system("CLS");
			 	break;
			 }
	
	 	    }
	 		gemix=gemix+dx;
	 		dx=0;
			gemiy=gemiy+dy;
	
	 		if(gemix>86)
	            gemix=2;
	        if(gemix<2)
	            gemix=86;
	        if(gemiy>20)
	            gemiy=2;
	        if(gemiy<28)
	            gemiy=28;
	
			gemi(gemix,gemiy);
	
		kayalariat();
	
	if(mermiy>2)
	{
		mermi(tempmermix,mermiy);
		mermiy--;
	}
	
		if(gemiy==kayay )
		{
			if(gemix-2==kayax || gemix-1==kayax || gemix==kayax || gemix+1==kayax || gemix+2==kayax||gemix+3==kayax||gemix+3==kayax||gemix-2==kayax+1||gemix-1==kayax+1||gemix==kayax+1||gemix+1==kayax+1||gemix+2==kayax+1||gemix+3==kayax+1)
			{
				can--;
				if(can==0)
				{
				    gotoxy(25,25);
				    printf("GAME OVER");
				    gotoxy(gemix,gemiy);
					printf("\\ |  / \n");
					gotoxy(gemix,gemiy+1);
					printf("-  O  -\n");
					gotoxy(gemix,gemiy+2);
					printf("/  |  \\ \n");
					can=10;
					break;
				}
			}
		}
	
		if(gemiy==kaya2y)
		{
			if(gemix-2==kaya2x || gemix-1==kaya2x || gemix==kaya2x || gemix+1==kaya2x || gemix+2==kaya2x)
			{
				can--;
				if(can==0)
				{
					gotoxy(10,20);
				    printf("GAME OVER");
				    gotoxy(gemix,gemiy);
					printf("\\ |  / \n");
					gotoxy(gemix,gemiy+1);
					printf("-  O  -\n");
					gotoxy(gemix,gemiy+2);
					printf("/  |  \\ \n");
					can=10;
					break;
				}
			}
		}
	
		if(gemiy==kaya3y)
		{
			if(gemix-2==kaya3x || gemix-1==kaya3x || gemix==kaya3x || gemix+1==kaya3x || gemix+2==kaya3x)
			{
				can--;
				if(can==0)
				{
					gotoxy(10,20);
				    printf("GAME OVER");
				    gotoxy(gemix,gemiy);
					printf("\\ |  / \n");
					gotoxy(gemix,gemiy+1);
					printf("-  O  -\n");
					gotoxy(gemix,gemiy+2);
					printf("/  |  \\ \n");
					can=10;
					break;
				}
			}
		}
	
		if(mermix==kayax && mermiy==kayay || mermix==kayax+1 && mermiy==kayay)
		{
			kayakontrol=1;
	
	enqueue(1);
	k+=10;
		}
		if(mermix==kaya2x && mermiy==kaya2y || mermix==kaya2x+1 && mermiy==kaya2y)
		{
			kaya2kontrol=1;
	
	enqueue(1);
	k+=10;
		}
		if(mermix==kaya3x && mermiy==kaya3y || mermix==kaya3x+1 && mermiy==kaya3y)
		{
			kaya3kontrol=1;
	
	enqueue(1);
	k+=10;
		}	
	
		if(kayakontrol==1 && kaya2kontrol==1 && kaya3kontrol==1)
		{
			kayakontrol=0;
			kaya2kontrol=0;
			kaya3kontrol=0;
			level++;
			}
	
	Sleep(100);
	system("CLS");
//	cerceve();

	}
			}
	//----------------------------NASIL OYNANIR BÖLÜMÜ-----------------------------------------------------------------------------------------------------

	else if(secim==2)
	{
		        system("CLS");
		        printf("Bilgisayarinizin \n");
				printf("Yukari tusu ile ates edebilirsiniz.\n\n");
			//	printf("Asagi tusu ile kayalari dusurebilirsiniz. \n\n");
				printf("Sag tusa basarak sag tarafa gidebilirsiniz \n\n");
				printf("Sol tusa basarak sol tarafa gidebilirsiniz \n\n");
				printf("Q tusu ile oyundan cikabilirsiniz\n");
		}

if(secim==3)
	{
	    system("CLS");

	    gets(isimGir);

		insertShip(isimGir);

printf("\n");

    }
	else if(secim==4)
	{
	    system("CLS");
	    printf("OYNAYANLAR LISTESI\n");
	    printName();
    }
    else if(secim==5)
    {
        break;
    }
}

	return 0;
}
