#pragma  once

#include <stdio.h>
#include <windows.h>
#pragma warning (disable :4996)
#include <time.h>
#define PLAY 'x'
#define COMP 'o'
#define NEXT 'N'
#define DRAW 'D'
#define COW 3
#define LINE 3


void Menu();
void Game(); 
void ShowBoard();
void Playmove();
char Judge();