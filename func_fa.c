#include "_automata.h"
#include "func_common.h"
#include <stdlib.h>

static int *_func_automata(struct struct_automata *, int *);

int *func_automata(struct struct_automata *p)
{
	if(p->tape.func_is_endm_tape(p)
			&& p->status.func_is_accept_current(p))
		return p->symbol.func_empty_input(p);
	return _func_automata(p, p->move_function.func_move(p));
}

static int *_func_automata(struct struct_automata *p, int *stat_p)
{
	if(!stat_p){
		p->move_function.graph.node_n.func_zero_node_n(p);
		if(!p->move_function.graph.func_back_graph(p))
			return NULL;
	}
	else
		if(!p->move_function.graph.func_progress_graph(p,stat_p))
		   return NULL;	
	return func_automata(p);
}
