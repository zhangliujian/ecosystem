#include<bits/stdc++.h>
#include "listtiger.h"
#include "listcow.h"
#include "initworld.h"
#include "cow.h"

using namespace std;
int grassNum = 0;
int	cowherdNum = 0;
int	sheepherdNum = 0;
int	tigerNum = 0; 
const int tigerView = 3;//initial range of view of tiger
const int herdView = 3;//initial range of view of herd of cow and sheep
grass grassList[100];
extern int grassa[100][100];
extern int specie[100][100];
Listtiger listtiger();
Listcow cowlist[100];
Listsheep sheeplist[100];
void initGrass(int GrassNumber)
{
	/*
	randomly initialize the grass, the size of the map can be changed
	*/
	for(int i = 0;i < GrassNumber;i++)
	{
		srand(time(NULL));
		int a = rand % 100 + 1;
		int b = rand % 100 + 1;
		grassa[a][b] = 1;
		grassList[i] = grass(a,b,10);
	}
}

void initTiger(int tigerNumber)
{
	/*
	randomly initialize the tiger, and check whether there are not other tigers in its vision
	*/
	Listtiger.setSize(tigerNumber);
	int temp = tigerNumber;
	while(temp)
	{
		srand(time(NULL));
		int a = rand % 100 + 1;
		int b = rand % 100 + 1;
		int c = rand % 2;
		for(int i = {(a - tigerView >= 1)?(a - tigerView):1};i < (a + tigerView <= 100)?(a + tigerView):100};i++)
		{
			for(int j = {(b - tigerView >= 1)?(b - tigerView):1};j < (b + tigerView <= 100)?(b + tigerView):100};j++)
			{
				if(specie[i][j] == 7 || specie[i][j] == 8) continue;
				else
				{
					Listtiger.append(a,b,50);
					temp--;
				}
			}
		}
	}
}

void initCow(int CowherdNumber)
{
	/*
	randomly initialize the cow, and check whether there are not other tigers in its vision
	*/
	int temp = CowherdNumber;
	int cnt = 0;
	while(temp)
	{
		srand(time(NULL));
		int a = rand % 100 + 1;
		int b = rand % 100 + 1;
		int check = 0;
		for(int i = {(a - HerdView >= 1)?(a - HerdView):1};i < (a + HerdView <= 100)?(a + HerdView):100};i++)
		{
			for(int j = {(b - HerdView >= 1)?(b - HerdView):1};j < (b + HerdView <= 100)?(b + HerdView):100};j++)
			{
				if(specie[i][j] == 7 || specie[i][j] == 8) 
				{
					check = 1;
					break;
				}
				else
				{
					Listcow A(a,b);
					cowList[cnt++] = A;
					temp--;
				}
			}
			if(check == 1) break;
		}
	}
} 

void initsheep(int SheepherdNumber)
{
	/*
	randomly initialize the sheep, and check whether there are not other tigers in its vision
	*/
	int temp = SheepherdNumber;
	int cnt = 0;
	while(temp)
	{
		srand(time(NULL));
		int a = rand % 100 + 1;
		int b = rand % 100 + 1;
		int check = 0; 
		for(int i = {(a - HerdView >= 1)?(a - HerdView):1};i < (a + HerdView <= 100)?(a + HerdView):100};i++)
		{
			for(int j = {(b - HerdView >= 1)?(b - HerdView):1};j < (b + HerdView <= 100)?(b + HerdView):100};j++)
			{
				if(specie[i][j] == 7 || specie[i][j] == 8)
				{
					check = 1;
					break;
				}
				else
				{
					Listsheep A(a,b);
					sheepList[cnt++] = A;
					temp--;
				}
			}
			if(check == 1) break;
		}
	}
}

void init(int GrassNumber,int CowherdNumber,int SheepHerdNumber,int TigerNumber)
{
	grassNum = GrassNumber;
	cowherdNum = CowherdNumber;
	sheepherdNum = SheepHerdNumber;
	tigerNum = TigerNumber;
	initGrass(GrassNumber);
	initTiger(TigerNumber);
	initCow(CowherdNumber);
	initsheep(SheepHerdNumber);
}

void nextTurn()
{
	for(int i = 0;i < grassNum;i++)
	{
		grassList[i].live();
	}
	listtiger.traverse();
	for(int i = 0;i < cowherdNum;i++) cowlist[i].traverse();
	for(int i = 0;i < sheepherdNum;i++) sheeplist[i].traverse();
}

int main()
{
	//	for()
}
