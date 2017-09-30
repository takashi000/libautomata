#include "_automata.h"
#define DEBUG 1
#define DFA 0

#if DFA
int func_automata(struct struct_automata *p)
{
	int i;
	char c1, c2;
	int n1, n2;

	p->automata.func_set_current(p, p->symbol.func_get_init_n(p));
	while(!p->automata.func_is_end(p)){
		c1 = p->automata.func_get_tape(p);
		for(i = 0; (c2 = p->move_function.func_get_dinput(p, i)) != '\0'; i++){
			n1	= p->automata.func_get_current(p);
			n2	= p->move_function.func_get_dstat_n(p, i);
			if(c1 == c2 && n1 == n2){
				p->automata.func_set_current(p, p->move_function.func_get_dmove_n(p, i, 0));
				break;
			}
		}
		p->automata.func_progress_tape(p);
	}
	return p->automata.func_is_accept(p);
}
#endif

#if !DFA
static int _func_automata(struct struct_automata *);
static int search_move_function(struct struct_automata* , int , char , int*);
int func_automata(struct struct_automata *p)
{
	p->automata.func_set_current(p, p->symbol.func_get_init_n(p));
	return _func_automata(p);
}
#if DEBUG
#include <stdio.h>
#endif
#define STACK_MAX	512
#undef graph_progress
#define graph_progress(p, stack, sp, n1, n2)\
	p->automata.func_set_current(p, n2);\
	p->automata.func_progress_tape(p);\
	if(sp < STACK_MAX){\
		stack[sp++][0]	= n1;\
	}\
	else return 0
#undef graph_back
#define graph_back(p, stack, sp, n) \
	if(sp >= 0){\
		stack[sp][1]	= 0;\
		n	= stack[--sp][0];\
		stack[sp][1]++;\
		p->automata.func_set_current(p, n);\
		p->automata.func_back_tape(p);\
	}\
	else return 0
#undef graph_empty_progress
#define graph_empty_progress(p, stack, sp, n1, n2, i)\
	if(search_move_function(p, n1, AUTOMATA_EMPTY, &i)){\
		n2  =  p->move_function.func_get_dmove_n(p, i, stack[sp][1]);\
		if(n2 >= 0){\
			p->automata.func_set_current(p, n2);\
			if(sp < STACK_MAX){\
				stack[sp++][0]	= n1;\
			}\
			else return 0;\
		}\
		else graph_back(p, stack, sp, n2);\
	}\
	else graph_back(p, stack, sp, n2)

static int search_move_function(struct struct_automata *p, int n, char c, int *i)
{
	char t1;
	int t2;

	for(*i = 0; (t1 = p->move_function.func_get_dinput(p, *i)) != '\0'; (*i)++){
		t2	= p->move_function.func_get_dstat_n(p, *i);
		if(c == t1 && n == t2) return 1;
	}
	return 0;
}
static int _func_automata(struct struct_automata *p)
{
	int i;
	char c1, c2;
	int n1, n2, n3;
	int stack[STACK_MAX][2];
	int sp=0;

	for(i = 0; i < STACK_MAX; i++)
		stack[i][1]	= 0;
	do{
#if DEBUG
		int j;
		printf("[%d]:(%d)(%d, %s)\n", sp, stack[sp][1], p->automata.func_get_current(p), p->automata.tape_p);
		printf("[ ");
		for(j = 0; j < sp; j++) printf("%d ", stack[j][0]);
		printf("]\n");
		getchar();
#endif
		c1 	= p->automata.func_get_tape(p);
		n1	= p->automata.func_get_current(p);
		if(p->automata.func_is_end(p)){
			if(p->automata.func_is_accept(p)) return 1;
			graph_empty_progress(p, stack, sp, n1, n3, i);
		}else{
			if(search_move_function(p, n1, c1, &i)){
				n3	= p->move_function.func_get_dmove_n(p, i, stack[sp][1]);
				if(n3 >= 0){
					graph_progress(p, stack, sp, n1, n3);
				}
				else{
					graph_empty_progress(p, stack, sp, n1, n3, i);
				}
			}
		}
	}while(sp > 0);

	return 0;
}
#endif
