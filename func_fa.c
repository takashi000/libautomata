#include "_automata.h"
#define DEBUG 0
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
static int _func_automata(struct struct_automata *, char, int, int);

int func_automata(struct struct_automata *p)
{
	p->automata.func_set_current(p, p->symbol.func_get_init_n(p));
	return _func_automata(p, p->automata.func_get_tape(p), p->automata.func_get_current(p), 0);
}
#if DEBUG
#include <stdio.h>
#endif
static int _func_automata(struct struct_automata *p, char c1, int n1, int k)
{
	int i;
	char c2;
	int n2;
#if DEBUG
	printf("k1:%d(%d, %c)\n", k, p->automata.func_get_current(p), p->automata.func_get_tape(p));
	getchar();
#endif
	if(!p->automata.func_is_end(p)){
		for(i = 0; (c2 = p->move_function.func_get_dinput(p, i)) != '\0'; i++){
			n2	= p->move_function.func_get_dstat_n(p, i);
			if(c1 == c2 && n1 == n2){
				if((p->move_function.func_get_dmove_n(p, i, k)) < 0) k--;
				p->automata.func_set_current(p, p->move_function.func_get_dmove_n(p, i, k));
				p->automata.func_progress_tape(p);
				_func_automata(p, p->automata.func_get_tape(p), p->automata.func_get_current(p), k);
				if(p->automata.func_is_accept(p) && p->automata.func_is_end(p)) return 1;
				p->automata.func_set_current(p, p->move_function.func_get_dmove_n(p, i, k - 1));
				p->automata.func_back_tape(p);
				_func_automata(p, p->automata.func_get_tape(p), p->automata.func_get_current(p), k + 1);
			}
		}
	}
	return p->automata.func_is_accept(p);
}
#endif
