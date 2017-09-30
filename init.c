#include "_automata.h"
#include "func_common.h"
#include <stdlib.h>

void init_fa(struct struct_automata **p)
{
	*p = malloc(sizeof(struct struct_automata));

	(*p)->func_init	= func_init;

	(*p)->tape.func_progress_tape	= func_progress_tape;
	(*p)->tape.func_set_tape		= func_set_tape;
	(*p)->tape.func_is_endm_tape	= func_is_endm_tape;
	(*p)->tape.func_set_endm		= func_set_endm;
	(*p)->tape.func_alloc_tape		= func_alloc_tape;
	(*p)->tape.func_free_tape		= func_free_tape;

	(*p)->symbol.func_in_stat		= func_in_stat;
	(*p)->symbol.func_in_input		= func_in_input;
	(*p)->symbol.func_card_stat		= func_card_stat;
	(*p)->symbol.func_card_input	= func_card_input;
	(*p)->symbol.func_empty_input	= func_empty_input;
	(*p)->symbol.func_alloc_stat	= func_alloc_stat;
	(*p)->symbol.func_alloc_input	= func_alloc_input;
	(*p)->symbol.func_free_stat		= func_free_stat;
	(*p)->symbol.func_free_input	= func_free_input;

	(*p)->move_function.condition.func_in_cond_stat		= func_in_cond_stat;
	(*p)->move_function.condition.func_in_cond_input	= func_in_cond_input;
	(*p)->move_function.condition.func_in_move_stat		= func_in_move_stat;
	(*p)->move_function.condition.func_alloc_condition	= func_alloc_condition;
	(*p)->move_function.condition.func_alloc_domain		= func_alloc_domain;
	(*p)->move_function.condition.func_alloc_move_stat	= func_alloc_move_stat;
	(*p)->move_function.condition.func_free_condition	= func_free_condition;
	(*p)->move_function.condition.func_free_domain		= func_free_domain;
	(*p)->move_function.condition.func_free_move_stat	= func_free_move_stat;

	(*p)->move_function.graph.stack.func_clr_stack		= func_clr_stack;
	(*p)->move_function.graph.stack.func_init_stack		= func_init_stack;
	(*p)->move_function.graph.stack.func_push_stack		= func_push_stack;
	(*p)->move_function.graph.stack.func_pop_stack		= func_pop_stack;
	(*p)->move_function.graph.stack.func_alloc_stack	= func_alloc_stack;
	(*p)->move_function.graph.stack.func_free_stack		= func_free_stack;

	(*p)->move_function.graph.node_n.func_get_node_n	= func_get_node_n;
	(*p)->move_function.graph.node_n.func_inc_node_n	= func_inc_node_n;
	(*p)->move_function.graph.node_n.func_zero_node_n	= func_zero_node_n;
	(*p)->move_function.graph.node_n.func_clr_node_n	= func_clr_node_n;
	(*p)->move_function.graph.node_n.func_init_node_n	= func_init_node_n;
	(*p)->move_function.graph.node_n.func_alloc_node_n	= func_alloc_node_n;
	(*p)->move_function.graph.node_n.func_free_node_n	= func_free_node_n;	

	(*p)->move_function.graph.func_progress_graph	= func_progress_graph;
	(*p)->move_function.graph.func_back_graph		= func_back_graph;
	
	(*p)->move_function.move_status.func_set_stat	= func_set_stat;
	(*p)->move_function.move_status.func_set_input	= func_set_input;
	(*p)->move_function.move_status.func_set_move	= func_set_move;

	(*p)->move_function.func_move	= func_move;

	(*p)->status.func_set_init				= func_set_init;
	(*p)->status.func_set_accept			= func_set_accept;
	(*p)->status.func_set_current			= func_set_current;
	(*p)->status.func_is_accept_current		= func_is_accept_current;
	(*p)->status.func_alloc_accept			= func_alloc_accept;
	(*p)->status.func_free_accept			= func_free_accept;

	(*p)->move_function.func_in_move_function	= func_in_move_function;
	(*p)->func_automata	= func_automata;

	(*p)->func_init(*p);
	(*p)->move_function.graph.stack.func_init_stack(*p);
	(*p)->move_function.graph.node_n.func_init_node_n(*p);
	(*p)->tape.func_set_endm(*p, AUTOMATA_ENDM_DEF);
}
