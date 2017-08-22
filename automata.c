#include "_automata.h"
#include "func_common.h"
#include <stdlib.h>

static int index_fa;
static struct struct_automata *fa;

int		create_automata(void)
{
	if(!fa)
		fa = malloc(sizeof(struct struct_automata) * AUTOMATA_MEM_PAGE);
	fa[index_fa].symbol.init_n		= 0;
	fa[index_fa].symbol.accept_n	= NULL;
	fa[index_fa].move_function.defn	= NULL;
	fa[index_fa].automata.tape_head	= NULL;
	fa[index_fa].automata.tape_p	= NULL;
	fa[index_fa].automata.current	= 0;
	fa[index_fa].symbol.func_set_init_n			= func_set_init_n;
	fa[index_fa].symbol.func_set_accept_n		= func_set_accept_n;
	fa[index_fa].symbol.func_get_init_n			= func_get_init_n;
	fa[index_fa].symbol.func_get_accept_n		= func_get_accept_n;
	fa[index_fa].move_function.func_set_defn	= func_set_defn;
	fa[index_fa].move_function.func_get_dstat_n	= func_get_dstat_n;
	fa[index_fa].move_function.func_get_dinput	= func_get_dinput;
	fa[index_fa].move_function.func_get_dmove_n	= func_get_dmove_n;
	fa[index_fa].automata.func_set_tape			= func_set_tape;
	fa[index_fa].automata.func_set_current		= func_set_current;
	fa[index_fa].automata.func_get_tape			= func_get_tape;
	fa[index_fa].automata.func_get_current		= func_get_current;
	fa[index_fa].automata.func_progress_tape	= func_progress_tape;
	fa[index_fa].automata.func_back_tape		= func_back_tape;
	fa[index_fa].automata.func_is_accept		= func_is_accept;
	fa[index_fa].automata.func_is_end			= func_is_end;
	fa[index_fa].automata.func_automata			= func_automata;
	
	return index_fa++;
}
void	clean_automata(int ad)
{
	int i;

	free(fa[ad].symbol.accept_n);
	fa[ad].symbol.accept_n		= NULL;

	for(i = 0; i < fa[ad].move_function.index; i++){
		fa[ad].move_function.defn[i].stat_n	= 0;
		free(fa[ad].move_function.defn[i].move_n);
		fa[ad].move_function.defn[i].move_n	= NULL;
	}
	free(fa[ad].move_function.defn);
	fa[ad].move_function.defn	= NULL;
	fa[ad].move_function.index	= 0;
	free(fa[ad].automata.tape_head);
	fa[ad].automata.tape_head	= NULL;
	free(fa[ad].automata.tape_p);
	fa[ad].automata.tape_p		= NULL;
	fa[ad].automata.current		= 0;
	index_fa--;
}
void	define_move_function(int ad, int stat_n, char input, int *move_n)
{
	fa[ad].move_function.func_set_defn(&fa[ad], stat_n, input, move_n);
}
void	define_init(int ad, int init_n)
{
	fa[ad].symbol.func_set_init_n(&fa[ad], init_n);
}
void	define_accept(int ad, int *accept_n, int k)
{
	fa[ad].symbol.func_set_accept_n(&fa[ad], accept_n, k);
}
int		automata(int ad, char *s)
{
	fa[ad].automata.func_set_tape(&fa[ad], s);
	return fa[ad].automata.func_automata(&fa[ad]);
}
