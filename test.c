#include <stdio.h>
#include "automata.h"

int main(void)
{
	int ad;
	int move[6][3]={
		{1, 2, -1},
		{2, -1},
		{1, -1},
		{1, -1},
		{0, -1},
		{1, -1}
	};
	int accept[]={2};

	ad	= create_automata();
	define_move_function(ad, 0, 'a', move[0]);
	define_move_function(ad, 0, 'b', move[1]);
	define_move_function(ad, 1, 'a', move[2]);
	define_move_function(ad, 1, 'b', move[3]);
	define_move_function(ad, 2, 'a', move[4]);
	define_move_function(ad, 2, 'b', move[5]);
	define_init(ad, 0);
	define_accept(ad, accept, 1);
	if(automata(ad, "aab"))
		puts("OK");
	else
		puts("NG");
	clean_automata(ad);
	return 0;
}
