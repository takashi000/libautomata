#include "_automata.h"
#include "automata.h"
#include <stdlib.h>

int *define_stat(AUTOMATA p, char *s)
{
	return p->symbol.func_in_stat(p, s);
}
int *define_input(AUTOMATA p, char *s)
{
	return p->symbol.func_in_input(p, s);
}
int *define_init(AUTOMATA p, int *init_p)
{
	return p->status.func_set_init(p, init_p);
}
int *define_accept(AUTOMATA p, int *accept_p)
{
	return p->status.func_set_accept(p, accept_p);
}
void define_move_function(AUTOMATA p, int *stat_p, int *input_p, int *move_p)
{
	p->move_function.func_in_move_function(p, stat_p, input_p, move_p, 0);
}
int *set_current(AUTOMATA p, int *current_p)
{
	return p->status.func_set_current(p, current_p);
}
void set_tape(AUTOMATA p, char *s)
{
	p->tape.func_set_tape(p, s);
}
int *run_automata(AUTOMATA p)
{
	return p->func_automata(p);
}
void clr_automata(AUTOMATA p)
{
	p->status.func_set_current(p, p->status.func_set_init(p, NULL));
	p->move_function.graph.stack.func_clr_stack(p);
	p->move_function.graph.node_n.func_clr_node_n(p);
}
void clean_automata(AUTOMATA *p)
{
	(*p)->tape.func_free_tape(*p);
	(*p)->symbol.func_free_stat(*p);
	(*p)->symbol.func_free_input(*p);
	(*p)->move_function.condition.func_free_move_stat(*p);
	(*p)->move_function.condition.func_free_domain(*p);
	(*p)->move_function.condition.func_free_condition(*p);
	(*p)->move_function.graph.stack.func_free_stack(*p);
	(*p)->move_function.graph.node_n.func_free_node_n(*p);
	(*p)->status.func_free_accept(*p);
	free(*p);
}
