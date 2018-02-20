#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#define SIZE 10

void addQueue(int);
void removeQueue();
void display();
void removeSelection();

using namespace std;

int queue[SIZE], front = -1, rear = -1,temp,todelete;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

void gotoXY(int,int);

int main()
{
	int menu_item=0, x=0,test;
	bool running = true;
	
	gotoXY(0,0); cout << "Menu:";
	gotoXY(0,0); cout << "->";
	
	while(running)
	{
		gotoXY(2,0); cout << "1. Insert";
		gotoXY(2,1);  cout << "2. Delete the first element";
		gotoXY(2,2);  cout << "3. Remove a selected element";
		gotoXY(2,3);  cout << "4. Display the queue";
		gotoXY(2,4); cout << "5. Quit Program";

		system("pause>nil");
		
		if(GetAsyncKeyState(VK_DOWN) && x != 11)
			{
				if(menu_item ==4){
					continue;
				}else
				{
					gotoXY(0,x); cout << "  ";
				x++;
				gotoXY(0,x); cout << "->";
				menu_item++;
				continue;	
				}
			}
			
		if(GetAsyncKeyState(VK_UP) && x != 0) 
			{
				if(menu_item ==0){
					continue;
				}else
				{
				gotoXY(0,x); cout << "  ";
				x--;
				gotoXY(0,x); cout << "->";
				menu_item--;
				continue;	
				}
				
			}
			
		if(GetAsyncKeyState(VK_RETURN)){ 
			    system("cls");
			switch(menu_item){
				
				case 0: {
					cout<< "Give me the number to add: ";
					scanf("%d", &test);
					gotoXY(0,10);
					addQueue(test);
					system("cls");
					break;
				}
					
					
				case 1: {
					gotoXY(0,10);
					removeQueue();
					break;
				}
				case 2: {
					gotoXY(0,10);
					removeSelection();
					break;
				}
					
				case 3: {
					gotoXY(0,10);
					display();
					break;
				}
				
				case 4: {
					gotoXY(0,10);
					cout << "Terminated Successfully";
					running = false;
				}
			}
				
		}		
		
	}
	
	gotoXY(2,21);
	return 0;
}

void gotoXY(int x, int y) 
{ 
	CursorPosition.X = x; 
	CursorPosition.Y = y; 
	SetConsoleCursorPosition(console,CursorPosition); 
}
void addQueue(int value){
   if(rear == SIZE-1){
      printf("\nQueue is Full! Insertion is not possible\n");
}
   else{
      if(front == -1)
	  front = 0;
      rear++;
      queue[rear] = value;
      printf("\nSuccesfully inserted the value");
   }
}
void removeQueue(){
      printf("\nDeleted the first element");
      front++;
      if(front == rear)
	  front = rear;
}
void removeSelection() {
	printf("I didnt made this part yet, code is commented");
	/*
	printf("Enter the queue number of the element in the queue: ");
	scanf("%d", &todelete);
	queue[todelete] =0;
	*/
}
void display(){
      int i;
      printf("\nQueue elements are:\n");
      for(i=front; i<=rear; i++)
	 printf("%d\t",queue[i]);
   }