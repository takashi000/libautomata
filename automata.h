#ifndef _AUTOMATA_H_
#define _AUTOMATA_H_

int		create_automata(void);
void	clean_automata(int);
void	define_move_function(int, int, char, int*);
void	define_init(int, int);
void	define_accept(int, int*, int);
int		automata(int, char *);

#endif

