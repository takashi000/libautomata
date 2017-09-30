#ifndef _AUTOMATA_H_
#define _AUTOMATA_H_

#ifndef __AUTOMATA_H_
struct struct_automata{long dummy;};
#endif

typedef struct struct_automata* AUTOMATA;

void init_fa(AUTOMATA *);
int *define_stat(AUTOMATA, char *);
int *define_input(AUTOMATA, char *);
int *define_init(AUTOMATA, int *);
int *define_accept(AUTOMATA, int *);
void define_move_function(AUTOMATA, int *, int *, int *);
void set_tape(AUTOMATA, char *);
int *set_current(AUTOMATA, int *);
int *run_automata(AUTOMATA);
void clr_automata(AUTOMATA);
void clean_automata(AUTOMATA *);
#endif
