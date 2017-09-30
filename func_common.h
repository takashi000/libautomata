#ifndef _FUNC_COMMON_H_
#define _FUNC_COMMON_H_

#include "_automata.h"

sym_stat	func_set_init_n(struct struct_automata *, sym_stat);
sym_stat	*func_set_accept_n(struct struct_automata *, sym_stat[], int);
sym_stat	func_get_init_n(struct struct_automata *);
sym_stat	func_get_accept_n(struct struct_automata *, int);
struct struct_move_function	*func_set_defn(struct struct_automata *, sym_stat, sym_input, sym_stat*);
sym_stat	func_get_dstat_n(struct struct_automata*, int);
sym_input	func_get_dinput(struct struct_automata*, int);
sym_stat	func_get_dmove_n(struct struct_automata *, int, int);
char		*func_set_tape(struct struct_automata *, char *);
sym_stat	func_set_current(struct struct_automata *, sym_stat);
char		func_get_tape(struct struct_automata *); 
sym_stat	func_get_current(struct struct_automata *);
char		func_progress_tape(struct struct_automata *);
char		func_back_tape(struct struct_automata *);
int			func_is_accept(struct struct_automata *);
int			func_is_end(struct struct_automata *);
int 		func_automata(struct struct_automata *);
#endif

