#include "automata.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	AUTOMATA fa;
	int *stat[7]; int *input[15];
	char str[64];
	int i;

	init_fa(&fa);
	
	define_stat(fa, "abcdef");
	define_input(fa, "+-.0123456789");

	for(i = 0; (stat[i] = define_stat(fa, NULL)); i++);
	for(i = 0; (input[i] = define_input(fa, NULL)); i++);

	define_move_function(fa, stat[0], input[13], stat[1]);
	define_move_function(fa, stat[0], input[0], stat[1]);
	define_move_function(fa, stat[0], input[1], stat[1]);
	define_move_function(fa, stat[1], input[2], stat[2]);
	define_move_function(fa, stat[1], input[3], stat[1]);
	define_move_function(fa, stat[1], input[3], stat[4]);
	define_move_function(fa, stat[1], input[4], stat[1]);
	define_move_function(fa, stat[1], input[4], stat[4]);
	define_move_function(fa, stat[1], input[5], stat[1]);
	define_move_function(fa, stat[1], input[5], stat[4]);
	define_move_function(fa, stat[1], input[6], stat[1]);
	define_move_function(fa, stat[1], input[6], stat[4]);
	define_move_function(fa, stat[1], input[7], stat[1]);
	define_move_function(fa, stat[1], input[7], stat[4]);
	define_move_function(fa, stat[1], input[8], stat[1]);
	define_move_function(fa, stat[1], input[8], stat[4]);
	define_move_function(fa, stat[1], input[9], stat[1]);
	define_move_function(fa, stat[1], input[9], stat[4]);
	define_move_function(fa, stat[1], input[10], stat[1]);
	define_move_function(fa, stat[1], input[10], stat[4]);
	define_move_function(fa, stat[1], input[11], stat[1]);
	define_move_function(fa, stat[1], input[11], stat[4]);
	define_move_function(fa, stat[1], input[12], stat[1]);
	define_move_function(fa, stat[1], input[12], stat[4]);
	define_move_function(fa, stat[2], input[3], stat[3]);
	define_move_function(fa, stat[2], input[4], stat[3]);
	define_move_function(fa, stat[2], input[5], stat[3]);
	define_move_function(fa, stat[2], input[6], stat[3]);
	define_move_function(fa, stat[2], input[7], stat[3]);
	define_move_function(fa, stat[2], input[8], stat[3]);
	define_move_function(fa, stat[2], input[9], stat[3]);
	define_move_function(fa, stat[2], input[10], stat[3]);
	define_move_function(fa, stat[2], input[11], stat[3]);
	define_move_function(fa, stat[2], input[12], stat[3]);
	define_move_function(fa, stat[3], input[3], stat[3]);
	define_move_function(fa, stat[3], input[4], stat[3]);
	define_move_function(fa, stat[3], input[5], stat[3]);
	define_move_function(fa, stat[3], input[6], stat[3]);
	define_move_function(fa, stat[3], input[7], stat[3]);
	define_move_function(fa, stat[3], input[8], stat[3]);
	define_move_function(fa, stat[3], input[9], stat[3]);
	define_move_function(fa, stat[3], input[10], stat[3]);
	define_move_function(fa, stat[3], input[11], stat[3]);
	define_move_function(fa, stat[3], input[12], stat[3]);
	define_move_function(fa, stat[3], input[13], stat[5]);
	define_move_function(fa, stat[4], input[2], stat[3]);

	define_init(fa, stat[0]);
	define_accept(fa, stat[5]);

	set_current(fa, stat[0]);

	printf(">");	
	while(scanf("%s", str) != EOF){
		set_tape(fa, str);
		if(!run_automata(fa)){
			puts("受理できませんでした");
		}else{
			puts("受理されました");
		}
		clr_automata(fa);
		memset(str, 0, sizeof(str) - 1);
		printf(">");	
	}
	clean_automata(&fa);
	return 0;
}
