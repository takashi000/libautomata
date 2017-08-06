#ifndef __AUTOMATA_H_
#define __AUTOMATA_H_

#include <stddef.h>

#define AUTOMATA_STAT_N 128
#define AUTOMATA_INSYM_N 64
#define AUTOMATA_STACK_N 256
#define AUTOMATA_ACCEPT_N AUTOMATA_STAT_N
#define AUTOMATA_EMPTY -1
#define AUTOMATA_ENDM_DEF '$'

struct struct_domain{
	int *cond_input;
	int **move_stat;
};
struct struct_condition{
	int *cond_stat;
	struct struct_domain *domain;
};
struct struct_stack{
	int *stat;
	char *tape;
};
struct struct_automata{
	struct{
		char *tape;
		char *tape_p;
		char end_marker;
		char *(*func_progress_tape)(struct struct_automata *);
		char *(*func_set_tape)(struct struct_automata *, char *);
		int (*func_is_endm_tape)(struct struct_automata *);
		void (*func_set_endm)(struct struct_automata *, char);
		void (*func_alloc_tape)(struct struct_automata *, size_t);
		void (*func_free_tape)(struct struct_automata *);
	}tape;
	struct{
		int **stat;
		int **input;
		int *(*func_in_stat)(struct struct_automata *, char *);
		int *(*func_in_input)(struct struct_automata *, char *);
		size_t (*func_card_stat)(struct struct_automata *);
		size_t (*func_card_input)(struct struct_automata *);
		int *(*func_empty_input)(struct struct_automata *);
		void (*func_alloc_stat)(struct struct_automata *, size_t);
		void (*func_alloc_input)(struct struct_automata *, size_t);
		void (*func_free_stat)(struct struct_automata *);
		void (*func_free_input)(struct struct_automata *);
	}symbol;
	struct{
		struct{
			struct struct_condition *_condition;
			int *(*func_in_cond_stat)(struct struct_automata *, int *, int);
			int *(*func_in_cond_input)(struct struct_automata *, int *, int *, int);
			int *(*func_in_move_stat)(struct struct_automata *, int *, int *, int *, int);
			void (*func_alloc_condition)(struct struct_automata *);
			void *(*func_alloc_domain)(struct struct_automata *);
			void *(*func_alloc_move_stat)(struct struct_automata *);
			void (*func_free_condition)(struct struct_automata *);
			void (*func_free_domain)(struct struct_automata *);
			void (*func_free_move_stat)(struct struct_automata *);
		}condition;
		struct{
			struct{
				int sp, bp;
				struct struct_stack *_stack;
				void (*func_clr_stack)(struct struct_automata *);
				void (*func_init_stack)(struct struct_automata *);
				int (*func_push_stack)(struct struct_automata *);
				int (*func_pop_stack)(struct struct_automata *);
				void (*func_alloc_stack)(struct struct_automata *);
				void (*func_free_stack)(struct struct_automata *);
			}stack;
			struct{
				int *node_n_array;
				void (*func_init_node_n)(struct struct_automata *);
				int (*func_get_node_n)(struct struct_automata *);
				void (*func_inc_node_n)(struct struct_automata *);
				void (*func_zero_node_n)(struct struct_automata *);
				void (*func_clr_node_n)(struct struct_automata *);
				void (*func_alloc_node_n)(struct struct_automata *);
				void (*func_free_node_n)(struct struct_automata *);
			}node_n;
			int *(*func_progress_graph)(struct struct_automata *, int *);
			int *(*func_back_graph)(struct struct_automata *);
		}graph;
		struct{
			struct{
				int *stat;
				int *input;
				int *move;
			}cond;
			int *(*func_set_stat)(struct struct_automata *, int *);
			int *(*func_set_input)(struct struct_automata *, int *);
			int *(*func_set_move)(struct struct_automata *, int *);
		}move_status;
		int *(*func_in_move_function)(struct struct_automata *, int *, int *, int *, int);
		int *(*func_move)(struct struct_automata *);
	}move_function;
	struct{
		int *init;
		int **accept;
		int *current;
		int *(*func_set_init)(struct struct_automata *, int *);
		int *(*func_set_accept)(struct struct_automata *, int *);
		int *(*func_set_current)(struct struct_automata *, int *);
		int (*func_is_accept_current)(struct struct_automata *);
		void (*func_alloc_accept)(struct struct_automata *);
		void (*func_free_accept)(struct struct_automata *);
	}status;
	void (*func_init)(struct struct_automata *);
	int *(*func_automata)(struct struct_automata *);
};
#endif
