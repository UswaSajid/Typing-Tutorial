#include <iostream>
#include <conio.h>

#include <windows.h>
#include <time.h>

#define SCREEN_WIDTH 90
#define SCREEN_HEIGHT 26
#define WIN_WIDTH 70

using namespace std;

HANDLE b = GetStdHandle(STD_OUTPUT_HANDLE);
COORD a;

char keys[10];
int keypos[10][2];
int score =0;

void gotoxy(int x, int y){
	a.X =x;
	a.Y =y;
	SetConsoleCursorPosition(b, a);
}
void setcursor(bool visible, DWORD size){
	if(size==0)
	size=20;
	
	CONSOLE_CURSOR_INFO w;
	w.bVisible = visible;
	w.dwSize = size;
	SetConsoleCursorInfo(b, &w);
}
void drawBoarder(){
	for(int i=0;i<SCREEN_WIDTH; i++){
		gotoxy(i,SCREEN_HEIGHT); cout<<"±";
	}
	for(int i=0;i< SCREEN_HEIGHT; i++){
		gotoxy(SCREEN_WIDTH, i); cout<<"±";
	}
	for(int i=0;i<SCREEN_HEIGHT; i++){
		gotoxy(WIN_WIDTH,i); cout<<"±";
	
	}
}
void genAlphabet(int ind){
	keys[ind]= 65+rand()%25;
	keypos[ind][0] = 2 + rand()%(WIN_WIDTH-2);
	keypos[ind][1] = 1;
}
void drawAlphabet(int ind){
	if( keypos[ind][0]!= 0){
		gotoxy(keypos[ind][0], keypos[ind][1]); cout<<keys[ind];
	}
}
void eraseAlphabet(int ind){
	if(keypos[ind][0]!=0){
		gotoxy(keypos[ind][0], keypos[ind][1]); cout<<" ";
	}
}
void resetAlphabet(int ind){
	eraseAlphabet(ind);
	genAlphabet(ind);
}
void gameover(){
	system ("cls");
	cout<<endl;
	cout<<"\t\t------------------------------------------"<<endl;
	cout<<"\t\t------------------------------------------"<<endl;
	cout<<"\t\t---------------Game Over------------------"<<endl;
	cout<<"\t\t------------------------------------------"<<endl;
	cout<<"\t\tPress any key to go back to menu"<<endl;
	getch();
}
void updateScore(){
	gotoxy(WIN_WIDTH + 7, 5); cout<<"Score : "<<score<<endl;
}
void instructions(){
	system("cls");
	cout<<"Instructions";
	cout<<"-------------------";
	cout<<"\n On left side you will see falling cherecter";
	cout<<"\n you have to keep them away from touching floor";
	cout<<"\n press respective key from keyboard to keep playing";
	cout<<"\n press escape to exit";
	cout<<"\n press any key to go back to menu";
	getch();
}
void play(){
	score=0;
	for(int i=0;i<10 ;i++){
		keypos[i][1] = 1;
	}
	system ("cls");
	drawBoarder();
	updateScore(); 
	
	for(int i=0;i<10; i++)
	genAlphabet(i);
	
	gotoxy(WIN_WIDTH + 5, 2); cout<<"Typing Tutor";
	gotoxy(WIN_WIDTH + 6, 4); cout<<"------------";
	gotoxy (WIN_WIDTH + 6,6); cout<<"-------------";
	gotoxy(18,5); cout<<"press any key to start";
	getch();
	gotoxy(18,5); cout<<"                                                ";
	 
	 
	 while(1){
	 	if(kbhit()){
	 		char ch= getch();
	 		for(int i=0; i<10; i++){
	 			if( ch==keys[i] || ch-32 == keys [i]){
	 				resetAlphabet(i);
	 				score++;
	 				updateScore();
				 }
			 }
			 if(ch==27){
			 	break;
			 }
		 }
		 for(int i=0; i<10; i++)
		 drawAlphabet(i);
		 
		 Sleep(300);
		 
		 for(int i=0;i<10;i++){
		 	eraseAlphabet(i);
		 	keypos[i][1] +=1;
		if(keypos[i][1]>SCREEN_HEIGHT){
			gameover();
			return;
		}
		 }
	 }
}

	 int main()
	 {
	 	setcursor(0,0);
	 	srand( (unsigned)time(NULL));
	 	do{
	 		system("cls");
	 		gotoxy(10,5); cout<<"--------------------------------";
	 		gotoxy(10,6); cout<<" |       TYPING TUTOR          |";
	 		gotoxy(10,7); cout<<"--------------------------------";
	 		gotoxy(10,9); cout<<"1 . START GAME ";
	 		gotoxy(10,10); cout<<"2. INSTRUCTION---";
	 		gotoxy(10,11); cout<<"3. quit-----";
	 		gotoxy(10,13); cout<<"SELECT OPTIONS";
	 		char op= getche();
	 		if(op=='1') play();
	 		else if(op == '2')instructions();
	 		else if(op== '3') exit (0);
		 }
		 while(1);
		 return 0;
	 }
	

