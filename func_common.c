#include "func_common.h"
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

sym_stat	func_set_init_n(struct struct_automata *p, sym_stat n)
{
	return (p->symbol.init_n = n);
}
sym_stat	*func_set_accept_n(struct struct_automata *p, sym_stat n[], int k)
{
	int i;
	
	if(!p->symbol.accept_n)
		p->symbol.accept_n	= malloc(sizeof(sym_stat) * AUTOMATA_MEM_PAGE);
	for(i = 0; i < k; i++)
		p->symbol.accept_n[i]	= n[i];
	p->symbol.accept_n[i]		= -1;
	return p->symbol.accept_n;
}
sym_stat	func_get_init_n(struct struct_automata *p)
{
	return p->symbol.init_n;
}
sym_stat	func_get_accept_n(struct struct_automata *p, int i)
{
	return p->symbol.accept_n[i];
}
struct struct_move_function	*func_set_defn(struct struct_automata *p, sym_stat sn, sym_input c, sym_stat *mn)
{
	size_t move_len;
	sym_stat *tmp;
	int i;

	if(!p->move_function.defn)
		p->move_function.defn = malloc(sizeof(struct struct_move_function) * AUTOMATA_MEM_PAGE);
	if(p->move_function.index >= AUTOMATA_MEM_PAGE)
		p->move_function.defn = realloc(p->move_function.defn, p->move_function.index + AUTOMATA_MEM_PAGE);
	tmp	= mn;
	while(*tmp >= 0) tmp++;
	move_len	= tmp - mn + 1;
	p->move_function.defn[p->move_function.index].move_n	= malloc(sizeof(sym_stat) * move_len);
	p->move_function.defn[p->move_function.index].stat_n	= sn;
	p->move_function.defn[p->move_function.index].input		= c;
	for(i = 0; i < move_len; i++)	p->move_function.defn[p->move_function.index].move_n[i]	= mn[i];
	p->move_function.index++;
	return p->move_function.defn;
}
sym_stat	func_get_dstat_n(struct struct_automata *p, int i)
{
	return p->move_function.index < i ? -1 : p->move_function.defn[i].stat_n;
}
sym_input	func_get_dinput(struct struct_automata *p, int i)
{
	return p->move_function.index < i ? '\0' : p->move_function.defn[i].input;
}
sym_stat	func_get_dmove_n(struct struct_automata *p, int i, int j)
{
	return p->move_function.index < i ? -1 : p->move_function.defn[i].move_n[j];
}
char		*func_set_tape(struct struct_automata *p, char *s)
{
	size_t len = strlen(s);

	p->automata.tape_head		= malloc(sizeof(char) * len + 1);
	strcpy(p->automata.tape_head, s);
	p->automata.tape_head[len]	= AUTOMATA_ENDM;
	p->automata.tape_p			= p->automata.tape_head;
	return p->automata.tape_head;
}
sym_stat	func_set_current(struct struct_automata *p, sym_stat n)
{
	return (p->automata.current	= n);
}
char		func_get_tape(struct struct_automata *p)
{

	return *(p->automata.tape_p);
}
sym_stat	func_get_current(struct struct_automata *p)
{
	return p->automata.current;
}
char		func_progress_tape(struct struct_automata *p)
{
	return *(++p->automata.tape_p);
}
char		func_back_tape(struct struct_automata *p)
{
	return *(--p->automata.tape_p);
}
int			func_is_accept(struct struct_automata *p)
{
	int i;
	int accept;

	for(i = 0; (accept = p->symbol.func_get_accept_n(p, i)) > 0; i++){
		if(accept == p->automata.func_get_current(p))
			return 1;
	}
	return 0;
}
int			func_is_end(struct struct_automata *p)
{
	return p->automata.func_get_tape(p) == AUTOMATA_ENDM ? 1 : 0;
}
