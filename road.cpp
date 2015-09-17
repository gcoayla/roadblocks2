#include <iostream>
#include <stdlib.h>
#include<conio.h>
#include <time.h>
#include <string>
#include <ctype.h>
#include "lib.h"
using namespace std;
void delay(int secs) {
  for(int i = (time(NULL) + secs); time(NULL) != i; time(NULL));
}
struct result{
    int a[2];
    char matriztuto[20][20];
    char won='a';
};
void paso(int level){
    if (level==7)
		ganaste();
	else{
        ganador();
		int AVICII=7;
		system("cls");
		cout<<"You wanna go on to the next level?: "<<endl;
		string n;
		cin>>n;
		for(int i = 0; n[i]; i++)
        n[i] = tolower(n[i]);
		if (n== "si" or n=="yes"){
            if (level==0)
				nivel1();
			else if (level==1)
				nivel2();
			else if (level==2)
				nivel3();
			else if (level==3)
				nivel4();
			else if (level==4)
				nivel5();
			else if (level==5)
				nivel6();
			else if (level==6)
				nivel7();
		}

		else if (n=="no")
			levels(AVICII);
		else{
            cout<<"that is not a valid option"<<endl;
			delay(2);
			paso(level);
		}
	}
}
void over(int level){
    system("cls");
	perdedor();
	cout<<" "<<endl;
	cout<<" CONTINUE?: "<<endl;
	string n;
    cin>>n;
    for(int i = 0; n[i]; i++)
        n[i] = tolower(n[i]);
	if (n== "si" or n=="yes"){
        if (level==0)
			tutorial();
		else if (level==1)
			nivel1();
		else if (level==2)
			nivel2();
		else if (level==3)
			nivel3();
		else if (level==4)
			nivel4();
		else if (level==5)
			nivel5();
		else if (level==6)
			nivel6();
		else if (level==7)
			nivel7();
	}
	else if (n=="no")
		menu();
	else{
        cout<<" That is not a valid option"<<endl;
		delay(2);
		over(level);
	}
}

struct result left(int a[2],char matriztuto[][20],int lon[2]){
    system("cls");
    result l;
	logo();
	for(int i=0;i<lon[0];i++){
        for(int j=0;j<lon[1];j++){
            cout<<matriztuto[i][j];
        }
		cout<<" "<<endl;
	}
	delay(1);
	if (matriztuto[a[0]][a[1]-1]==char(219)){
        l.a[0]=a[0];
        l.a[1]=a[1];
        for(int i=0;i<20;i++)
            for(int j=0;j<20;j++)
		l.matriztuto[i][j]=matriztuto[i][j];
		return l;
	}
	else if (matriztuto[a[0]][a[1]-1]==char(88)){
        l.won='w';
		return l;
	}
	else if (matriztuto[a[0]][a[1]-1]==char(254)){
        for(int i=0;i<lon[0]-1;i++){
            for(int j=0;j<lon[0]-1;j++){
                if (matriztuto[i][j]==char(254) and i!=a[0] and j!=a[1]-1){
                    matriztuto[i][j-1]=char(2);
					matriztuto[a[0]][a[1]]=' ';
					a[0]=i;
					a[1]=j-1;
					return left(a,matriztuto,lon);
                }
            }
        }
	}
	else if (matriztuto[a[0]][a[1]-1]==char(220)){
        for(int i=0;i<lon[0]-1;i++){
            for(int j=0;j<lon[0]-1;j++){
                if (matriztuto[i][j]==char(220) and i!=a[0] and j!=a[1]-1){
                    matriztuto[i][j-1]=char(2);
					matriztuto[a[0]][a[1]]=' ';
					a[0]=i;
					a[1]=j-1;
					return left(a,matriztuto,lon);
                }
            }
        }
	}
	else if (matriztuto[a[0]][a[1]-1]==char(176)){
        l.won='l';
		return l;
	}

	else{
        matriztuto[a[0]][a[1]-1]=char(2);
		matriztuto[a[0]][a[1]]=' ';
		a[0]=a[0];
		a[1]=a[1]-1;
		return left(a,matriztuto,lon);
	}

}

struct result right(int a[2],char matriztuto[][20],int lon[2]){
    system("cls");
    result l;
	logo();
	for(int i=0;i<lon[0];i++){
        for(int j=0;j<lon[1];j++){
            cout<<matriztuto[i][j];
        }
        cout<<" "<<endl;
	}
	delay(1);
	if (matriztuto[a[0]][a[1]+1]==char(219)){
        l.a[0]=a[0];
        l.a[1]=a[1];
		for(int i=0;i<20;i++)
            for(int j=0;j<20;j++)
		l.matriztuto[i][j]=matriztuto[i][j];
		return l;
	}

	else if (matriztuto[a[0]][a[1]+1]==char(88)){
        l.won='w';
		return l;
	}
	else if (matriztuto[a[0]][a[1]+1]==char(254)){
        for(int i=0;i<lon[0]-1;i++){
            for(int j=0;j<lon[0]-1;j++){
                if (matriztuto[i][j]==char(254) and i!=a[0] and j!=a[1]+1){
                    matriztuto[i][j+1]=char(2);
					matriztuto[a[0]][a[1]]=' ';
					a[0]=i;
					a[1]=j+1;
					return right(a,matriztuto,lon);
                }
            }
        }
	}
	else if (matriztuto[a[0]][a[1]+1]==char(220)){
        for(int i=0;i<lon[0]-1;i++){
            for(int j=0;j<lon[0]-1;j++){
                if (matriztuto[i][j]==char(220) and i!=a[0] and j!=a[1]+1){
                    matriztuto[i][j+1]=char(2);
					matriztuto[a[0]][a[1]]=' ';
					a[0]=i;
					a[1]=j+1;
					return right(a,matriztuto,lon);
                }
            }
        }
	}
	else if (matriztuto[a[0]][a[1]+1]==char(176)){
        l.won='l';
		return l;
	}
	else{
        matriztuto[a[0]][a[1]+1]=char(2);
		matriztuto[a[0]][a[1]]=' ';
		a[0]=a[0];
		a[1]=a[1]+1;
		return right(a,matriztuto,lon);
	}
}

struct result down(int a[2],char matriztuto[][20],int lon[2]){
    system("cls");
    result l;
	logo();
	for(int i=0;i<lon[0];i++){
        for(int j=0;j<lon[0];j++){
            cout<<matriztuto[i][j];
        }
		cout<<" "<<endl;
	}
	delay(1);
	if (matriztuto[a[0]+1][a[1]]==char(219)){
        l.a[0]=a[0];
        l.a[1]=a[1];
		for(int i=0;i<20;i++)
            for(int j=0;j<20;j++)
		l.matriztuto[i][j]=matriztuto[i][j];
		return l;
	}
	else if (matriztuto[a[0]+1][a[1]]==char(88)){
        l.won='w';
        return l;
	}
	else if (matriztuto[a[0]+1][a[1]]==char(254)){
        for(int i=0;i<lon[0]-1;i++){
            for(int j=0;j<lon[0]-1;j++){
                if (matriztuto[i][j]==char(254) and i!=a[0]+1 and j!=a[1]){
                    matriztuto[i+1][j]=char(2);
					matriztuto[a[0]][a[1]]=' ';
					a[0]=i+1;
					a[1]=j;
					return down(a,matriztuto,lon);
                }
            }
        }
	}
	else if (matriztuto[a[0]+1][a[1]]==char(220)){
        for(int i=0;i<lon[0]-1;i++){
            for(int j=0;j<lon[0]-1;j++){
                if (matriztuto[i][j]==char(220) and i!=a[0]+1 and j!=a[1]){
                    matriztuto[i+1][j]=char(2);
					matriztuto[a[0]][a[1]]=' ';
					a[0]=i+1;
					a[1]=j;
					return down(a,matriztuto,lon);
                }
            }
        }
	}
	else if (matriztuto[a[0]+1][a[1]]==char(176)){
        l.won='l';
		return l;
	}
	else{
        matriztuto[a[0]+1][a[1]]=char(2);
		matriztuto[a[0]][a[1]]=' ';
		a[0]=a[0]+1;
		a[1]=a[1];
		return down(a,matriztuto,lon);
	}
}

struct result up(int a[2],char matriztuto[][20],int lon[2]){
    system("cls");
    result l;
	logo();
	for(int i=0;i<lon[0];i++){
        for(int j=0;j<lon[0];j++){
            cout<<matriztuto[i][j];
        }
		cout<<" "<<endl;
	}
	delay(1);
	if (matriztuto[a[0]-1][a[1]]==char(219)){
        l.a[0]=a[0];
        l.a[1]=a[1];
		for(int i=0;i<20;i++)
            for(int j=0;j<20;j++)
		l.matriztuto[i][j]=matriztuto[i][j];
		return l;
	}
	else if (matriztuto[a[0]-1][a[1]]==char(88)){
        l.won='w';
        return l;
	}
	else if (matriztuto[a[0]-1][a[1]]==char(254)){
        for(int i=0;i<lon[0]-1;i++){
            for(int j=0;j<lon[0]-1;j++){
                if (matriztuto[i][j]==char(254) and i!=a[0]-1 and j!=a[1]){
                    matriztuto[i-1][j]=char(2);
					matriztuto[a[0]][a[1]]=' ';
					a[0]=i-1;
					a[1]=j;
					return up(a,matriztuto,lon);
                }
            }
        }
	}
	else if (matriztuto[a[0]-1][a[1]]==char(220)){
        for(int i=0;i<lon[0]-1;i++){
            for(int j=0;j<lon[0]-1;j++){
                if (matriztuto[i][j]==char(220) and i!=a[0]-1 and j!=a[1]){
                    matriztuto[i-1][j]=char(2);
					matriztuto[a[0]][a[1]]=' ';
					a[0]=i-1;
					a[1]=j;
					return up(a,matriztuto,lon);
                }
            }
        }
	}
	else if (matriztuto[a[0]-1][a[1]]==char(176)){
        l.won='l';
        return l;
	}
	else{
        matriztuto[a[0]-1][a[1]]=char(2);
		matriztuto[a[0]][a[1]]=' ';
		a[0]=a[0]-1;
		a[1]=a[1];
		return up(a,matriztuto,lon);
	}
}

int move(){
    cout<<" "<<endl;
	cout<<" 1.-LEFT"<<endl;
	cout<<" 2.-DOWN"<<endl;
	cout<<" 3.-RIGHT"<<endl;
	cout<<" 5.-UP"<<endl;
	cout<<" "<<endl;
	cout<<" Enter the direction you wanna move: "<<endl;
	int mov;
	cin>>mov;
	return mov;
}
void comp(int a[2],char matriztuto[][20],int level,int lon[2]){
    int mov;
    mov=move();
	result l;
	if (mov==1){
        l=left(a,matriztuto,lon);
		if (l.won=='w')
			paso(level);
		else if (l.won=='l')
			over(level);
		else{
            a[0]=l.a[0];
            a[1]=l.a[1];
			for(int i=0;i<20;i++){
                for(int j=0;j<20;j++){
                    matriztuto[i][j]=l.matriztuto[i][j];
                }
			}
			comp(a,matriztuto,level,lon);
		}
	}

	else if (mov==2){
        l=down(a,matriztuto,lon);
		if (l.won=='w')
			paso(level);
		else if (l.won=='l')
			over(level);
		else{
            a[0]=l.a[0];
            a[1]=l.a[1];
			for(int i=0;i<20;i++)
                for(int j=0;j<20;j++)
                    matriztuto[i][j]=l.matriztuto[i][j];
			comp(a,matriztuto,level,lon);
		}
	}

	else if (mov==3){
        l=right(a,matriztuto,lon);
		if (l.won=='w')
			paso(level);
		else if (l.won=='l')
			over(level);
		else{
            a[0]=l.a[0];
            a[1]=l.a[1];
			for(int i=0;i<20;i++)
                for(int j=0;j<20;j++)
                    matriztuto[i][j]=l.matriztuto[i][j];
			comp(a,matriztuto,level,lon);
		}
	}

	else if (mov==5){
        l=up(a,matriztuto,lon);
		if (l.won=='w')
			paso(level);
		else if (l.won=='l')
			over(level);
		else{
            a[0]=l.a[0];
            a[1]=l.a[1];
			for(int i=0;i<20;i++)
                for(int j=0;j<20;j++)
                    matriztuto[i][j]=l.matriztuto[i][j];
			comp(a,matriztuto,level,lon);
		}
	}

	else{
        cout<<" That is not a valid option"<<endl;
		delay(2);
		comp(a,matriztuto,level,lon);
	}
}

void tutorial(){
	int level=0;
	char matriztuto[11][20]={{char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219)},
				{char(219),' ',' ',' ',' ',' ',' ',char(2),' ',char(176)},
				{char(219),' ',' ',' ',' ',' ',' ',' ',' ',char(219)},
				{char(219),char(219),char(219),char(219),char(219),' ',' ',char(254),' ',char(219)},
				{char(219),' ',' ',' ',char(88),' ',' ',' ',char(219),char(219)},
				{char(219),' ',' ',' ',char(219),' ',' ',' ',' ',char(219)},
				{char(219),' ',char(254),' ',char(219),' ',char(219),char(219),char(219),char(219)},
				{char(219),' ',' ',' ',' ',' ',' ',' ',' ',char(219)},
				{char(219),' ',' ',' ',' ',' ',' ',' ',' ',char(219)},
				{char(219),' ',' ',' ',char(219),' ',' ',' ',' ',char(219)},
				{char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219)}};
	int a[]={1,7};
	int lon[]={11,20};
	system("cls");
	logo();
	for(int i=0;i<lon[0];i++){
        for(int j=0;j<lon[1];j++){
            cout<<matriztuto[i][j];
        }
        cout<<" "<<endl;
	}

	comp(a,matriztuto,level,lon);
}
void nivel1(){
	int level=1;
	char matriztuto[20][20]={{char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176)},
		{char(176),' ',' ',' ',char(219),' ',' ',char(2),' ',' ',char(219),' ',' ',' ',' ',' ',' ',' ',' ',char(176)},
		{char(219),' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',char(176)},
		{char(219),' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',char(176)},
		{char(219),' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',char(176)},
		{char(219),' ',' ',' ',' ',' ',' ',' ',' ',' ',char(219),' ',' ',' ',' ',' ',' ',' ',' ',char(176)},
		{char(219),' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',char(219),' ',' ',' ',char(176)},
		{char(176),' ',' ',' ',' ',' ',char(219),char(219),char(219),' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',char(219)},
		{char(176),' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',char(219)},
		{char(176),' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',char(219)},
		{char(176),' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',char(219)},
		{char(176),' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',char(176)},
		{char(176),' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',char(176)},
		{char(176),' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',char(88),char(219),' ',' ',' ',char(176)},
		{char(176),' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',char(219),' ',' ',char(219),char(219),' ',' ',' ',char(176)},
		{char(176),' ',' ',' ',char(219),' ',' ',' ',' ',' ',' ',char(219),' ',' ',' ',' ',' ',' ',' ',char(176)},
		{char(176),' ',' ',' ',char(219),char(219),' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',char(176)},
		{char(176),' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',char(176)},
		{char(176),' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',char(176)},
        {char(176),char(176),char(176),char(219),char(219),char(219),char(176),char(176),char(219),char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176)}};
	int a[]={1,7};
	int lon[]={20,20};
	system("cls");
	logo();
	for(int i=0;i<lon[0];i++){
        for(int j=0;j<lon[1];j++){
            cout<<matriztuto[i][j];
        }
        cout<<" "<<endl;
	}

	comp(a,matriztuto,level,lon);
}
void nivel2(){
	int level=2;
	char matriztuto[20][20]={{char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219)},
        {char(219),' ',char(219),' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',char(219),' ',' ',' ',' ',char(219)},
        {char(219),' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',char(88),char(219)},
        {char(219),char(219),char(219),' ',char(219),' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',char(219)},
        {char(219),' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',char(219),' ',' ',' ',' ',char(219)},
        {char(219),' ',char(219),' ',char(219),' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',char(219)},
        {char(219),' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',char(219)},
        {char(219),' ',' ',char(219),' ',' ',' ',char(2),char(219),char(88),' ',char(219),' ',' ',' ',' ',' ',' ',' ',char(219)},
        {char(219),' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',char(219)},
        {char(219),' ',' ',' ',char(219),' ',' ',' ',char(219),' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {char(219),' ',' ',' ',' ',char(219),' ',' ',' ',' ',' ',' ',' ',' ',' ',char(219),' ',' ',' ',char(219)},
        {char(219),' ',char(219),' ',' ',' ',' ',' ',char(219),' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',char(219)},
        {char(219),' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',char(254),' ',char(219),' ',' ',' ',' ',char(219)},
        {char(219),' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',char(219)},
        {char(219),' ',' ',' ',char(219),' ',' ',' ',' ',char(219),' ',' ',' ',' ',' ',' ',' ',char(254),' ',char(219)},
        {char(219),' ',char(219),' ',' ',char(219),' ',' ',' ',' ',' ',' ',' ',' ',char(219),' ',' ',' ',' ',char(219)},
        {char(219),' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',char(219)},
        {char(219),' ',char(219),' ',char(219),' ',' ',' ',' ',' ',' ',char(219),' ',' ',' ',' ',char(219),' ',' ',char(219)},
        {char(219),' ',' ',' ',' ',' ',' ',char(219),' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',char(219)},
        {char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219)}};
	int a[]={7,7};
	int lon[]={20,20};
	system("cls");
	logo();
	for(int i=0;i<lon[0];i++){
        for(int j=0;j<lon[1];j++){
            cout<<matriztuto[i][j];
        }
        cout<<" "<<endl;
	}

	comp(a,matriztuto,level,lon);
}
void nivel3(){
	int level=3;
	char matriztuto[20][20]={{char(176),char(176),char(176),char(219),char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176)},
		{char(176),' ',' ',char(219),char(2),' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',char(176)},
		{char(176),' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',char(219),' ',' ',char(176)},
		{char(176),' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',char(254),' ',' ',' ',' ',char(176)},
		{char(176),' ',' ',' ',' ',' ',' ',' ',char(219),' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',char(176)},
		{char(176),' ',' ',' ',char(219),' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',char(219),' ',char(176)},
		{char(176),char(219),' ',' ',' ',' ',' ',char(254),' ',' ',' ',' ',' ',' ',' ',' ',' ',char(219),' ',char(176)},
		{char(176),' ',' ',' ',' ',' ',' ',char(219),' ',' ',' ',' ',' ',' ',char(219),' ',' ',' ',' ',char(176)},
		{char(176),' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',char(219),' ',' ',' ',' ',' ',char(176)},
		{char(176),' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',char(88),' ',' ',' ',' ',' ',' ',' ',char(176)},
		{char(176),' ',' ',' ',' ',' ',' ',' ',' ',char(219),char(219),char(219),char(219),' ',' ',' ',' ',' ',' ',char(176)},
		{char(176),' ',' ',' ',' ',' ',char(219),' ',' ',' ',' ',' ',' ',' ',' ',' ',char(219),' ',' ',char(176)},
		{char(176),' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',char(176)},
		{char(176),' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',char(219),' ',' ',' ',' ',' ',char(176)},
		{char(176),' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',char(219),' ',' ',' ',' ',' ',char(176)},
		{char(176),' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',char(219),' ',' ',' ',' ',' ',char(176)},
		{char(176),' ',' ',' ',' ',' ',' ',' ',' ',' ',char(219),' ',' ',' ',' ',' ',' ',' ',' ',char(176)},
		{char(176),' ',char(219),' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',char(176)},
		{char(176),' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',char(176)},
		{char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176)}};
	int a[]={1,4};
	int lon[]={20,20};
	system("cls");
	logo();
	for(int i=0;i<lon[0];i++){
        for(int j=0;j<lon[1];j++){
            cout<<matriztuto[i][j];
        }
        cout<<" "<<endl;
	}

	comp(a,matriztuto,level,lon);
}
void nivel4(){
	int level=4;
	char matriztuto[20][20]={{char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219)},
		{char(219),char(219),' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',char(219),' ',' ',' ',' ',' ',' ',char(219)},
		{char(219),' ',' ',' ',' ',' ',char(219),' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',char(219)},
		{char(219),' ',char(219),char(219),char(219),char(254),char(219),char(219),char(219),' ',char(219),char(219),char(219),' ',char(219),' ',char(219),' ',' ',char(219)},
		{char(219),' ',char(219),' ',char(219),' ',char(219),' ',' ',' ',char(219),' ',char(219),' ',char(219),' ',char(219),' ',' ',char(219)},
		{char(219),' ',char(219),char(219),char(219),' ',char(219),char(219),' ',' ',char(219),char(219),' ',' ',char(219),' ',char(219),' ',' ',char(219)},
		{char(219),' ',char(219),' ',' ',' ',char(219),' ',' ',' ',char(219),' ',char(219),' ',char(219),' ',char(219),' ',' ',char(219)},
		{char(219),' ',char(219),' ',' ',' ',char(219),char(219),char(219),' ',char(219),' ',char(219),' ',char(219),char(254),char(219),' ',' ',char(219)},
		{char(219),' ',' ',' ',' ',' ',char(219),' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',char(219)},
		{char(219),' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',char(219)},
		{char(219),' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',char(219)},
		{char(219),' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',char(219)},
		{char(219),' ',' ',' ',char(219),' ',' ',' ',char(219),' ',char(219),char(219),char(219),' ',' ',' ',' ',' ',' ',char(219)},
		{char(219),' ',' ',' ',char(219),' ',' ',' ',char(219),' ',' ',char(219),' ',' ',char(219),' ',' ',' ',' ',char(219)},
		{char(219),' ',' ',' ',' ',char(219),char(219),char(219),' ',' ',' ',char(219),' ',' ',' ',' ',char(219),char(219),' ',char(219)},
		{char(219),' ',' ',' ',' ',char(219),' ',char(219),' ',' ',' ',char(219),' ',' ',' ',' ',char(219),char(219),' ',char(219)},
		{char(219),' ',' ',' ',' ',' ',' ',' ',' ',' ',char(219),char(219),char(219),' ',' ',char(219),char(219),' ',char(219),char(219)},
		{char(219),' ',char(2),' ',' ',' ',' ',' ',' ',' ',' ',' ',char(219),' ',' ',' ',char(219),' ',char(219),char(219)},
		{char(219),' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',char(219),' ',char(219),char(219)},
		{char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(88),char(219),char(219),char(219),char(219),char(219),char(219)}};
	int a[]={18,2};
	int lon[]={20,20};
	system("cls");
	logo();
	for(int i=0;i<lon[0];i++){
        for(int j=0;j<lon[1];j++){
            cout<<matriztuto[i][j];
        }
        cout<<" "<<endl;
	}

	comp(a,matriztuto,level,lon);
}
void nivel5(){
	int level=5;
	char matriztuto[20][20]={{char(219),char(2),' ',' ',char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219)},
		{char(219),' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',char(219)},
		{char(219),' ',' ',' ',' ',' ',' ',' ',' ',char(219),char(219),char(219),' ',' ',' ',' ',char(88),' ',' ',char(219)},
		{char(219),' ',' ',' ',' ',' ',' ',' ',' ',' ',char(219),' ',' ',' ',' ',' ',' ',char(219),' ',char(219)},
		{char(219),' ',char(219),' ',' ',char(219),' ',' ',' ',' ',char(219),' ',' ',' ',' ',char(219),' ',' ',' ',char(219)},
		{char(219),' ',' ',char(219),' ',' ',char(219),' ',' ',' ',char(219),' ',' ',' ',' ',' ',char(219),' ',' ',char(219)},
		{char(219),' ',' ',' ',char(219),' ',' ',char(219),' ',char(219),char(219),char(219),' ',' ',' ',' ',' ',' ',char(219),char(219)},
		{char(219),' ',' ',' ',' ',char(219),' ',' ',' ',char(219),' ',' ',' ',' ',' ',' ',' ',char(219),' ',char(219)},
		{char(219),' ',char(219),' ',' ',' ',char(219),' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',char(219)},
		{char(219),' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',char(219)},
		{char(219),' ',' ',' ',' ',' ',char(219),' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',char(219)},
		{char(219),char(219),' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',char(219),' ',' ',' ',' ',' ',' ',char(219)},
		{char(219),' ',' ',char(219),char(219),char(219),' ',' ',' ',' ',' ',' ',' ',' ',char(219),' ',' ',char(219),' ',char(219)},
		{char(219),' ',' ',char(219),' ',' ',char(88),' ',' ',' ',' ',' ',' ',' ',char(219),char(219),' ',char(219),' ',char(219)},
		{char(219),' ',' ',char(219),char(219),' ',' ',' ',' ',' ',' ',' ',' ',' ',char(219),char(219),' ',char(219),' ',char(219)},
		{char(219),' ',' ',char(219),' ',' ',' ',' ',' ',' ',' ',char(219),' ',' ',char(219),' ',char(219),char(219),' ',char(219)},
		{char(219),' ',' ',char(219),' ',' ',' ',' ',' ',' ',' ',char(88),' ',' ',char(219),' ',char(219),char(219),' ',char(219)},
		{char(219),' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',char(219)},
		{char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219),char(219)}};
	int a[]={0,1};
	int lon[]={19,20};
	system("cls");
	logo();
	for(int i=0;i<lon[0];i++){
        for(int j=0;j<lon[1];j++){
            cout<<matriztuto[i][j];
        }
        cout<<" "<<endl;
	}

	comp(a,matriztuto,level,lon);
}
void nivel6(){
	int level=6;
	char matriztuto[20][20]={{char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176)},
		{char(176),char(2),' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',char(219),' ',' ',char(176)},
		{char(176),' ',' ',' ',' ',' ',char(219),char(219),char(219),' ',' ',char(219),char(219),' ',' ',' ',char(219),char(219),' ',char(176)},
		{char(176),' ',' ',' ',' ',' ',char(219),' ',' ',' ',char(219),char(219),' ',' ',' ',' ',' ',' ',char(220),char(176)},
		{char(176),' ',char(219),' ',' ',' ',' ',' ',' ',' ',char(219),' ',' ',' ',char(219),' ',' ',' ',' ',char(176)},
		{char(176),' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',char(219),' ',' ',char(176)},
		{char(176),' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',char(219),' ',' ',char(176)},
		{char(176),' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',char(254),' ',' ',' ',char(219),' ',' ',char(176)},
		{char(176),' ',' ',' ',' ',char(219),' ',' ',char(219),char(219),' ',' ',' ',' ',' ',' ',' ',' ',' ',char(176)},
		{char(176),' ',' ',' ',' ',char(219),' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',char(176)},
		{char(176),' ',' ',' ',' ',char(219),' ',' ',' ',' ',' ',' ',' ',' ',' ',char(219),' ',' ',' ',char(176)},
		{char(176),' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',char(219),' ',' ',char(219),char(176)},
		{char(176),' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',char(219),char(219),char(176)},
		{char(176),' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',char(219),char(219),' ',char(176)},
		{char(176),char(219),' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',char(219),char(254),' ',' ',char(219)},
		{char(176),char(219),char(219),' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',char(219),char(219),char(219),' ',' ',' ',char(176)},
		{char(176),' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',char(219),' ',char(219),' ',' ',' ',' ',char(176)},
		{char(176),' ',' ',char(219),char(219),' ',' ',' ',' ',' ',' ',' ',char(219),char(220),' ',' ',' ',' ',' ',char(176)},
		{char(176),' ',' ',' ',' ',' ',' ',char(219),char(219),char(219),' ',char(219),char(219),' ',' ',' ',' ',' ',char(88),char(176)},
{char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176)}};
	int a[]={1,1};
	int lon[]={20,20};
	system("cls");
	logo();
	for(int i=0;i<lon[0];i++){
        for(int j=0;j<lon[1];j++){
            cout<<matriztuto[i][j];
        }
        cout<<" "<<endl;
	}

	comp(a,matriztuto,level,lon);
}
void nivel7(){
	int level=7;
	char matriztuto[20][20]={{char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176)},
		{char(176),' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',char(176)},
		{char(176),' ',' ',' ',' ',char(219),char(219),' ',' ',' ',char(219),' ',char(219),' ',' ',' ',' ',' ',' ',char(176)},
		{char(176),' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',char(219),' ',' ',' ',char(219),char(219),' ',char(176)},
		{char(176),' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',char(254),' ',' ',' ',' ',' ',char(219),' ',char(176)},
		{char(176),' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',char(176)},
		{char(176),' ',' ',' ',' ',' ',char(2),' ',char(219),' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',char(176)},
		{char(176),' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',char(176)},
		{char(176),' ',' ',char(219),char(219),char(219),' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',char(176)},
		{char(176),' ',' ',char(219),char(219),char(219),' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',char(219),' ',char(176)},
		{char(176),' ',' ',' ',char(219),' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',char(88),char(176)},
		{char(176),' ',' ',' ',' ',' ',' ',char(220),' ',' ',' ',' ',' ',' ',' ',char(254),' ',char(219),' ',char(176)},
		{char(176),' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',char(219),char(219),' ',' ',' ',' ',' ',' ',char(176)},
		{char(176),' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',char(219),' ',' ',' ',' ',' ',' ',' ',char(176)},
		{char(176),' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',char(219),' ',' ',' ',' ',char(220),' ',' ',char(176)},
		{char(176),' ',' ',char(219),' ',' ',' ',' ',' ',' ',' ',char(219),' ',' ',' ',' ',' ',' ',char(219),char(176)},
		{char(176),' ',' ',' ',' ',' ',char(219),char(219),char(219),' ',' ',char(219),char(219),' ',' ',' ',' ',' ',' ',char(176)},
		{char(176),' ',' ',' ',char(219),' ',' ',' ',' ',' ',' ',char(219),' ',' ',' ',' ',' ',char(219),' ',char(176)},
		{char(176),' ',' ',' ',' ',' ',' ',' ',' ',' ',char(219),char(219),' ',' ',' ',char(219),' ',' ',' ',char(176)},
{char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(219),char(176),char(176),char(176),char(176),char(176),char(176),char(176),char(176)}};
	int a[]={6,6};
	int lon[]={20,20};
	system("cls");
	logo();
	for(int i=0;i<lon[0];i++){
        for(int j=0;j<lon[1];j++){
            cout<<matriztuto[i][j];
        }
        cout<<" "<<endl;
	}

	comp(a,matriztuto,level,lon);
}
void logo(){
	system("cls");
	cout<<"     "<<endl;
	cout<<"          ______        ______        ___       _______  "<<endl;
	cout<<"         |   _  \\      /  __  \\      /   \\     |       \\ "<<endl;
	cout<<"         |  |_)  |    |  |  |  |    /  ^  \\    |  .--.  |"<<endl;
	cout<<"         |      /     |  |  |  |   /  /_\\  \\   |  |  |  |"<<endl;
	cout<<"         |  |\\  \\----.|  `--'  |  /  _____  \\  |  '--'  |"<<endl;
	cout<<"         | _| `._____| \\______/  /__/     \\__\\ |_______/ "<<endl;
	cout<<"     "												<<endl;
	cout<<"          ______    __        ______     ______  __  ___      _______."<<endl;
	cout<<"         |   _  \\  |  |      /  __  \\   /      ||  |/  /     /       |"<<endl;
	cout<<"         |  |_)  | |  |     |  |  |  | |  ,----'|  '  /     |   (----`"<<endl;
	cout<<"         |   _  <  |  |     |  |  |  | |  |     |    <       \\   \\    "<<endl;
	cout<<"         |  |_)  | |  `----.|  `--'  | |  `----.|  .  \\  .----)   |   "<<endl;
	cout<<"         |______/  |_______| \\______/   \\______||__|\\__\\ |_______/    "<<endl;
	for(int j=0;j<4;j++){
		cout<<" "<<endl;
	}
}

void tuto(){
	logo();
    string a23;
	cout<<" You wanna play the tutorial: "<<endl;
	cin>>a23;
	for(int i = 0; a23[i]; i++)
        a23[i] = tolower(a23[i]);
	if (a23=="si" or a23=="yes")
		tutorial();
	else if (a23=="no")
		nivel1();
	else{
		cout<<" That is not a valid option"<<endl;
		delay(2);
		tuto();}
}

void levels(int AVICCI){
	logo();
	cout<<"Choose a level: "<<endl;
	cout<<" "<<endl;
	cout<<"0.-TUTORIAL"<<endl;
	cout<<"1.-Level 1: "<<endl;
	cout<<"2.-Level 2: "<<endl;
	cout<<"3.-Level 3: "<<endl;
	cout<<"4.-Level 4: "<<endl;
	cout<<"5.-Level 5: "<<endl;
	cout<<"6.-Level 6: "<<endl;
	cout<<"7.-Level 7: "<<endl;
	cout<<"8.-BACK TO MENU"<<endl;
	cout<<" "<<endl;
	int n;
	cout<<"Choose a level: "<<endl;
	cin>>n;
	if (n==0){
		tutorial();}
	else if (n==1){
		nivel1();}
	else if (n==2){
		nivel2();}
	else if (n==3){
		nivel3();}
	else if (n==4){
		nivel4();}
	else if (n==5){
		nivel5();}
	else if (n==6){
		nivel6();}
	else if (n==7){
		nivel7();}
	else if (n==8){
		menu();}
}

void creditos(){
	system("cls");
	for(int i=0;i<30;i++){

		cout<<" "<<endl;
		cout<<"          ______        ______        ___       _______  "<<endl;
		cout<<"         |   _  \\      /  __  \\      /   \\     |       \\ "<<endl;
		cout<<"         |  |_)  |    |  |  |  |    /  ^  \\    |  .--.  |"<<endl;
		cout<<"         |      /     |  |  |  |   /  /_\\  \\   |  |  |  |"<<endl;
		cout<<"         |  |\\  \\----.|  `--'  |  /  _____  \\  |  '--'  |"<<endl;
		cout<<"         | _| `._____| \\______/  /__/     \\__\\ |_______/ "<<endl;
		cout<<"     "												<<endl;
		cout<<"          ______    __        ______     ______  __  ___      _______."<<endl;
		cout<<"         |   _  \\  |  |      /  __  \\   /      ||  |/  /     /       |"<<endl;
		cout<<"         |  |_)  | |  |     |  |  |  | |  ,----'|  '  /     |   (----`"<<endl;
		cout<<"         |   _  <  |  |     |  |  |  | |  |     |    <       \\   \\    "<<endl;
		cout<<"         |  |_)  | |  `----.|  `--'  | |  `----.|  .  \\  .----)   |   "<<endl;
		cout<<"         |______/  |_______| \\______/   \\______||__|\\__\\ |_______/    "<<endl;
		cout<<" "<<endl;
		for(int j=0;j<i;j++){
			cout<<" "<<endl;
		}

		cout<<" Created by :"<<endl;
		cout<<"				Gonzalo Coayla Zuniga"<<endl;
		cout<<"				Vanessa Macedo"<<endl;
		cout<<" Company :"<<endl;
		cout<<"				"<<endl;
		delay(1);
		system("cls");
	}
	menu();

}
void menu(){
	logo();
	cout<<" 1_NEW GAME"<<endl;
	cout<<" 2_LEVELS"<<endl;
	cout<<" 3_EXIT"<<endl;
	cout<<" 4_CREDITS"<<endl;
	cout<<" "<<endl;
	cout<<"							"<<endl;
	cout<<" "<<endl;
	int n;
	cout<<" Welcome, Enter the option you wanna get in to: "<<endl;
	cin>>n;

	if (n==1){
		tuto();
	}
	else if (n==2){
		int AVICII=7;
		system("cls");
		levels(AVICII);
	}
	else if (n==3){
		system("cls");
		cout<<"BYE"<<endl;
	}
	else if (n==4){
		system("cls");
		creditos();
	}
	else{
		cout<<" "<<endl;
		cout<<" This not a valid option"<<endl;
		delay(2);
		menu();
	}
}
void ganador(){
    system("cls");
	cout<<"--------------------------------------------------------------------------"<<endl;
	cout<<"--------------------------------XXXX--------------------------------------"<<endl;
	cout<<"-------------------------------XXXXX--------------------------------------"<<endl;
	cout<<"------------------------------XXXXXXX-------------------------------------"<<endl;
	cout<<"-----------------------------XXXXXXXX-------------------------------------"<<endl;
	cout<<"----------------------------XXXXXXXXX-------------------------------------"<<endl;
	cout<<"----------------------------XXX::XXXX-------------------------------------"<<endl;
	cout<<"---------------------------XXXX:::XXX-------------------------------------"<<endl;
	cout<<"---------------------------XXX:::::XX-------------------------------------"<<endl;
	cout<<"--------------------------XXX::::::XX-------------------------------------"<<endl;
	cout<<"-----XXXXXXXX-------------XX:::::::XX-------------------------------------"<<endl;
	cout<<"----XXXXXXXXXXX-----------XX:::::::XX-------------------------------------"<<endl;
	cout<<"--XXXXXXXXXXXXXX----------X::::::::XX-------------------------------------"<<endl;
	cout<<"XXXXXXXXXXX::::XX---------X::::::::XX-------------------------------------"<<endl;
	cout<<"XXXXXXXX::::::::XX--------X::::::::XX-------------------------------------"<<endl;
	cout<<"XXXXXX:::::::::::X--XXXX--XX:::::::XX-------------------------------------"<<endl;
	cout<<"XXXXXXX::::::::::XXXXXXXXXXX:::::::XX-------------------------------------"<<endl;
	cout<<"XXXXXXX::::::::::XX:::::::XX:::::::XX----------------------------XX-------"<<endl;
	cout<<"-XXXXX::::::::::::::::::::::::::::XX---------------------------XXX--------"<<endl;
	cout<<"--XXXXX::::::::::::::::::::::::::XX----------------------------X----------"<<endl;
	cout<<"---XXXXX::::::::::::::::::::::::XX----------------------------------------"<<endl;
	cout<<"----XXXXXX:::::::::::::::::::::XX---------XXXX--XXX--XX--X--XXXX--XX-XX-XX"<<endl;
	cout<<"-----XXXXXX::::::XX:::::::::XX:XX---------X-----X-X--X-X-X--X--X--XX-XX-XX"<<endl;
	cout<<"------XXXXXXXX::X  X:::::::X  X:X---------X-XX--XXX--X-XXX--X--X--XX-XX-XX"<<endl;
	cout<<"--------XXXXX:::X  X:::::::X  X:X---------X--X--X-X--X--XX--X--X----------"<<endl;
	cout<<"------------X:::XXXX:::::::XXXX:XX--------XXXX--X-X--X---X--XXXX--XX-XX-XX"<<endl;
	cout<<"-------------:::XXXX::::X::XXXX:XX----------------------------------------"<<endl;
	cout<<"-----------XX:::XXX:::::::::XXX::X----------------------------------------"<<endl;
	cout<<"-----------XX::::::::XXXXXX::::::X----------------------------------------"<<endl;
	cout<<"-----------XX:XXX::::XXXXXX:::XXXX----------------------------------------"<<endl;
	cout<<"-----------XXXX:XX:::XXXXXX::X::XX-------------------------------XX-------"<<endl;
	cout<<"------------XX:::X:::XXXXXX::X::XX-----------------------------XXX--------"<<endl;
	cout<<"------------XX:::X:::XXXXXX::X::X------------------------------X----------"<<endl;
	cout<<"------------XX:::X:::XXXXXX::X::X-----------------------------------------"<<endl;
	cout<<"-------------XX:XX::::XXXX:::X:X----------XXXX--XXX--XX--X--XXXX--XX-XX-XX"<<endl;
	cout<<"------------XXXX::::::::::::::XX----------X-----X-X--X-X-X--X--X--XX-XX-XX"<<endl;
	cout<<"----------XXXXXX:::::::::::::XX-----------X-XX--XXX--X-XXX--X--X--XX-XX-XX"<<endl;
	cout<<"----------XX::::X:::::::::::XXXXX---------X--X--X-X--X--XX--X--X----------"<<endl;
	cout<<"---------XXX:::::XX:::::::XX:::XXX--------XXXX--X-X--X---X--XXXX--XX-XX-XX"<<endl;
	cout<<"----------X::::::XXXXXXXXXX:::::XX----------------------------------------"<<endl;
	cout<<"----------XX::::::XXXXXXXXX:::::XX----------------------------------------"<<endl;
	cout<<"---------XXXX:::::XXXXXXXXX:::::XX----------------------------------------"<<endl;
	cout<<"--------XXXXXXX:::XXX:XXXX:::::XX-----------------------------------------"<<endl;
	cout<<"------XXXXXXXXXXX::XX:::X:::XXX-------------------------------------------"<<endl;
	cout<<"-----XXXXXXXXXX::::X::::X:XXX---------------------------------------------"<<endl;
	cout<<"----XXXXXXXXXXX:::::::::::XX----------------------------------------------"<<endl;
	cout<<"----XXXXXXXX--XX::::::::::X-----------------------------------------------"<<endl;
	cout<<"-----XXXXXX--XXX::::::::::X-----------------------------------------------"<<endl;
	cout<<"------XXXX--XX::X:::::::::X-----------------------------------------------"<<endl;
	cout<<"------XXX--XX::::X:::::::XX-----------------------------------------------"<<endl;
	cout<<"-----------XX::::XXXX:::X:X-----------------------------------------------"<<endl;
	cout<<"-----------X:::::X--XXXX::XX----------------------------------------------"<<endl;
	cout<<"-----------X:X:X:X----X::::X----------------------------------------------"<<endl;
	cout<<"------------XXXXX-----X::::X----------------------------------------------"<<endl;
	cout<<"----------------------X::::X----------------------------------------------"<<endl;
	cout<<"-----------------------X:::X----------------------------------------------"<<endl;
	cout<<"-----------------------X:X:X----------------------------------------------"<<endl;
	cout<<"------------------------XXX-----------------------------------------------"<<endl;
	delay(2);
	system("cls");
}

void perdedor(){
    system("cls");
	cout<<"-------:::----::xxxxxxxxxx----:::-----------------------------------------"<<endl;
	cout<<"------:-------::--------::-------:----------------------------------------"<<endl;
	cout<<"-----X-XXXXXXXXX:------:XXXXXXXXX-X---------------------------------------"<<endl;
	cout<<"-----X-XXXXXXX------------:XXXXXX-X---------------------------------------"<<endl;
	cout<<"-----::XX-XX----------------:X-XX::---------------------------------------"<<endl;
	cout<<"------:X------------------------X:----------------------------------------"<<endl;
	cout<<"-------X------------------------X:-----------XXX--XXX--XXX--XXX---XXX--XXX"<<endl;
	cout<<"------:X----------------::::::--::-----------X-X--X----X-X--X-XX---X---X-X"<<endl;
	cout<<"-------X----XXX:::----:X::::::::X:--::::-----XXX--XX---XXX--X--X---X---X-X"<<endl;
	cout<<":::----:X::XXXX:::XX:X:---------::::---------X----X----XX---X-XX---X---X-X"<<endl;
	cout<<"------::X::--------:XX------------:::XXX-----X----XXX--X-X--XXX---XXX--XXX"<<endl;
	cout<<"-----:::------------XX------X-------::------------------------------------"<<endl;
	cout<<"---:::------:-------:X:-:::XXX-------::----------XX------------XX---------"<<endl;
	cout<<"---X--:----:XX:----:X::XX:::-:X-------:----------XX------------XX---------"<<endl;
	cout<<"--X:--:---XX:::X::::--:--:----X:------::---------XX------------XX---------"<<endl;
	cout<<"-:X---:--::----XX:::::::::---::-------::---------XX------------XX---------"<<endl;
	cout<<"-::---:---------::-::--:--------------::---------XX------------XX---------"<<endl;
	cout<<"-:X---:----::------------------------::-----------------------------------"<<endl;
	cout<<"--:::-:-::X:----------:-------:::--:::----------X-------------------------"<<endl;
	cout<<"---:::::XX:--------------------::::XX----------XX-------------------------"<<endl;
	cout<<"--------X::::::-------------:::::::::--:------XX--------------------------"<<endl;
	cout<<"-------:::::-::::---------:::------:::------------------------------------"<<endl;
	cout<<"------X:----::::X:-------:::::::----:X----------------XXXXXXX-------------"<<endl;
	cout<<"-----:X---XXXX::XX:-----:X::::::XX---X:-------------XXX-----XXX-----------"<<endl;
	cout<<"-----:X--XX::XXX::XX---XX:XXXXX:XXX--X------------XXX---------XXX---------"<<endl;
	cout<<"------X::X:XXXXXXX:XX-XX:XXXXXXX::X-X:----------XXX-------------XXX-------"<<endl;
	cout<<"-------XXX:XXXXXXXX:XXX:XXXXXXXX:XX::-------------------------------------"<<endl;
	cout<<"--------:XX:XXXXXXX::XX:XXXXXXXX:X:---------------------------------------"<<endl;
	cout<<"----------XXXXXXXXX:XXXXXXXXXXXXX-----------------------------------------"<<endl;
	cout<<"-----------:XXXXXXXXX--XXXXXXX:-------------------------------------------"<<endl;
	delay(2);
	system("cls");
}

void ganaste(){
    system("cls");
	cout<<" "<<endl;
	cout<<" "<<endl;
	cout<<" "<<endl;
	cout<<" "<<endl;
	cout<<"        Congratulations, you are the WINNER"<<endl;
	cout<<" "<<endl;
	cout<<" "<<endl;
	cout<<"  ________    _____      _____  ___________"<<endl;
	cout<<"/  _____/   /  _  \\    /     \\ \\_   _____/"<<endl;
	cout<<"/   \\  ___  /  /_\\  \\  /  \\ /  \\ |    __)_ "<<endl;
	cout<<"\\    \\_\\  \\/    |    \\/    Y    \\|        \\ "<<endl;
	cout<<" \\______  /\\____|__  /\\____|__  /_______  /"<<endl;
	cout<<"		\\/         \\/         \\/        \\/ "<<endl;
	cout<<"____________   _________________________ "<<endl;
	cout<<"\\_____  \\   \\ /   /\\_   _____/\\______   \\ "<<endl;
	cout<<" /   |   \\   Y   /  |    __)_  |       _/"<<endl;
	cout<<"/    |    \\     /   |        \\ |    |   \\ "<<endl;
	cout<<"\\_______  /\\___/   /_______  / |____|_  /"<<endl;
	cout<<"		\\/                 \\/         \\/ "<<endl;
	delay(3);
	menu();
}




int main (){
	menu();
}
