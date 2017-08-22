#ifndef __AUTOMATA_H_
#define __AUTOMATA_H_

#define AUTOMATA_MEM_PAGE	4096
#define AUTOMATA_ENDM	'$'

typedef int 	sym_stat;
typedef char	sym_input;

struct struct_move_function{
	sym_stat	stat_n;	/*状態遷移*/
	sym_input	input;	/*入力記号*/
	sym_stat	*move_n;	/*遷移先*/
};
struct struct_automata{
	struct{
		sym_stat	init_n;	/*初期状態*/
		sym_stat	*accept_n;	/*受理状態*/
		sym_stat	(*func_set_init_n)(struct struct_automata *, sym_stat);
		sym_stat	*(*func_set_accept_n)(struct struct_automata *, sym_stat[], int);
		sym_stat	(*func_get_init_n)(struct struct_automata *);
		sym_stat	(*func_get_accept_n)(struct struct_automata *, int);
	}symbol;
	struct{
		struct struct_move_function	*defn;	/*動作関数の定義*/
		struct struct_move_function	*(*func_set_defn)(struct struct_automata *, sym_stat, sym_input, sym_stat*);
		int index;	/*参照用インデックス*/
		sym_stat	(*func_get_dstat_n)(struct struct_automata*, int);
		sym_input	(*func_get_dinput)(struct struct_automata*, int);
		sym_stat	(*func_get_dmove_n)(struct struct_automata *, int, int);
	}move_function;
	struct{
		char		*tape_head;	/*テープの先頭*/
		char		*tape_p;
		sym_stat	current;	/*現在の状態*/
		char		*(*func_set_tape)(struct struct_automata *, char *);
		sym_stat	(*func_set_current)(struct struct_automata *, sym_stat);
		char		(*func_get_tape)(struct struct_automata *); 
		sym_stat	(*func_get_current)(struct struct_automata *);
		char		(*func_progress_tape)(struct struct_automata *);
		char		(*func_back_tape)(struct struct_automata *);
		int			(*func_is_accept)(struct struct_automata *);
		int			(*func_is_end)(struct struct_automata *);
		int 		(*func_automata)(struct struct_automata *);
	}automata;
};
#endif

