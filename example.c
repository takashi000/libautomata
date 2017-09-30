#include <stdio.h>
#include <string.h>
#include "automata.h"

int main(void)
{
	int ad;
	int move[24][3]={
		{1, -1}, {1, -1}, {-1}, {-1},
		{-1}, {-1}, {1, 4, -1}, {2, -1}, 
		{-1}, {-1}, {3, -1}, {-1},
		{5, -1}, {-1}, {3, -1}, {-1},
		{-1}, {-1}, {-1}, {3, -1},
		{-1}, {-1}, {-1}, {-1},
	};
	int accept[]={5};
	char str[32];

	ad	= create_automata();
	define_move_function(ad, 0, -1 , move[0]);
	define_move_function(ad, 0, '+', move[1]);
	define_move_function(ad, 0, '-', move[1]);
	define_move_function(ad, 0, '0', move[2]);
	define_move_function(ad, 0, '1', move[2]);
	define_move_function(ad, 0, '2', move[2]);
	define_move_function(ad, 0, '3', move[2]);
	define_move_function(ad, 0, '4', move[2]);
	define_move_function(ad, 0, '5', move[2]);
	define_move_function(ad, 0, '6', move[2]);
	define_move_function(ad, 0, '7', move[2]);
	define_move_function(ad, 0, '8', move[2]);
	define_move_function(ad, 0, '9', move[2]);
	define_move_function(ad, 0, '.', move[3]);
	define_move_function(ad, 1, -1 , move[4]);
	define_move_function(ad, 1, '+', move[5]);
	define_move_function(ad, 1, '-', move[5]);
	define_move_function(ad, 1, '0', move[6]);
	define_move_function(ad, 1, '1', move[6]);
	define_move_function(ad, 1, '2', move[6]);
	define_move_function(ad, 1, '3', move[6]);
	define_move_function(ad, 1, '4', move[6]);
	define_move_function(ad, 1, '5', move[6]);
	define_move_function(ad, 1, '6', move[6]);
	define_move_function(ad, 1, '7', move[6]);
	define_move_function(ad, 1, '8', move[6]);
	define_move_function(ad, 1, '9', move[6]);
	define_move_function(ad, 1, '.', move[7]);
	define_move_function(ad, 2, -1 , move[8]);
	define_move_function(ad, 2, '+', move[9]);
	define_move_function(ad, 2, '-', move[9]);
	define_move_function(ad, 2, '0', move[10]);
	define_move_function(ad, 2, '1', move[10]);
	define_move_function(ad, 2, '2', move[10]);
	define_move_function(ad, 2, '3', move[10]);
	define_move_function(ad, 2, '4', move[10]);
	define_move_function(ad, 2, '5', move[10]);
	define_move_function(ad, 2, '6', move[10]);
	define_move_function(ad, 2, '7', move[10]);
	define_move_function(ad, 2, '8', move[10]);
	define_move_function(ad, 2, '9', move[10]);
	define_move_function(ad, 2, '.', move[11]);
	define_move_function(ad, 3, -1 , move[12]);
	define_move_function(ad, 3, '+', move[13]);
	define_move_function(ad, 3, '-', move[13]);
	define_move_function(ad, 3, '0', move[14]);
	define_move_function(ad, 3, '1', move[14]);
	define_move_function(ad, 3, '2', move[14]);
	define_move_function(ad, 3, '3', move[14]);
	define_move_function(ad, 3, '4', move[14]);
	define_move_function(ad, 3, '5', move[14]);
	define_move_function(ad, 3, '6', move[14]);
	define_move_function(ad, 3, '7', move[14]);
	define_move_function(ad, 3, '8', move[14]);
	define_move_function(ad, 3, '9', move[14]);
	define_move_function(ad, 3, '.', move[15]);
	define_move_function(ad, 4, -1 , move[16]);
	define_move_function(ad, 4, '+', move[17]);
	define_move_function(ad, 4, '-', move[17]);
	define_move_function(ad, 4, '0', move[18]);
	define_move_function(ad, 4, '1', move[18]);
	define_move_function(ad, 4, '2', move[18]);
	define_move_function(ad, 4, '3', move[18]);
	define_move_function(ad, 4, '4', move[18]);
	define_move_function(ad, 4, '5', move[18]);
	define_move_function(ad, 4, '6', move[18]);
	define_move_function(ad, 4, '7', move[18]);
	define_move_function(ad, 4, '8', move[18]);
	define_move_function(ad, 4, '9', move[18]);
	define_move_function(ad, 4, '.', move[19]);
	define_move_function(ad, 5, -1 , move[20]);
	define_move_function(ad, 5, '+', move[21]);
	define_move_function(ad, 5, '-', move[21]);
	define_move_function(ad, 5, '0', move[22]);
	define_move_function(ad, 5, '1', move[22]);
	define_move_function(ad, 5, '2', move[22]);
	define_move_function(ad, 5, '3', move[22]);
	define_move_function(ad, 5, '4', move[22]);
	define_move_function(ad, 5, '5', move[22]);
	define_move_function(ad, 5, '6', move[22]);
	define_move_function(ad, 5, '7', move[22]);
	define_move_function(ad, 5, '8', move[22]);
	define_move_function(ad, 5, '9', move[22]);
	define_move_function(ad, 5, '.', move[23]);
	define_init(ad, 0);
	define_accept(ad, accept, 1);

	while(scanf("%s", str) != EOF){
		if(automata(ad, str))
			puts("OK");
		else
			puts("NG");
		memset(str,0, sizeof(str) - 1);
	}
	clean_automata(ad);
	return 0;
}
