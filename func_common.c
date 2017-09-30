#include "_automata.h"
#include <stdlib.h>
#include <string.h>

static char *_func_set_tape(struct struct_automata *, char *);
static int *____func_in_stat(struct struct_automata *, char [], int );
static int *___func_in_stat(struct struct_automata *, char *, char [], int);
static int *__func_in_stat(struct struct_automata *, char *, char []);
static int *_func_in_stat(struct struct_automata *);
static int *____func_in_input(struct struct_automata *, char [], int );
static int *___func_in_input(struct struct_automata *, char *, char [], int);
static int *__func_in_input(struct struct_automata *, char *, char []);
static int *_func_in_input(struct struct_automata *);
static int *_func_empty_input(struct struct_automata *, int);
static size_t _func_card_stat(struct struct_automata *, size_t);
static size_t _func_card_input(struct struct_automata *, size_t);
static int *__func_in_cond_stat(struct struct_automata *, int *, int, int);
static int *_func_in_cond_stat(struct struct_automata *, int *, int);
static int *___func_in_cond_input(struct struct_automata *, int *, int , int, int);
static int *__func_in_cond_input(struct struct_automata *, int *, int, int);
static int *_func_in_cond_input(struct struct_automata *, int *, int *, int, int);
static int *____func_in_move_stat(struct struct_automata *, int *, int , int , int, int);
static int *___func_in_move_stat(struct struct_automata *, int *, int, int, int);
static int *__func_in_move_stat(struct struct_automata *, int *, int *, int , int, int);
static int *_func_in_move_stat(struct struct_automata *, int *, int *, int *, int, int);
static int *__func_set_accept(struct struct_automata *, int *, int *);
static int *_func_set_accept(struct struct_automata *);
static int _func_is_accept_current(struct struct_automata *, int );

void func_init(struct struct_automata *p)
{
	p->tape.tape	= NULL;
	p->tape.tape_p	= NULL;
	p->symbol.stat	= NULL;
	p->symbol.input	= NULL;
	p->move_function.condition._condition	= NULL;
	p->move_function.graph.stack._stack		= NULL;
	p->move_function.graph.node_n.node_n_array	= NULL;
	p->move_function.move_status.cond.stat	= NULL;
	p->move_function.move_status.cond.input	= NULL;
	p->move_function.move_status.cond.move	= NULL;
	p->status.init		= NULL;
	p->status.accept	= NULL;
	p->status.current	= NULL;
}
char *func_progress_tape(struct struct_automata *p)
{
	return ++p->tape.tape_p;
}
char *func_set_tape(struct struct_automata *p, char *s)
{
	return !s ? p->tape.tape_p:_func_set_tape(p, s);
}
int func_is_endm_tape(struct struct_automata *p)
{
	return *p->tape.tape_p == p->tape.end_marker ? 1:0;
}
void func_set_endm(struct struct_automata *p, char c)
{
	p->tape.end_marker = c;
}
void func_alloc_tape(struct struct_automata *p, size_t n)
{
	p->tape.tape = malloc(sizeof(char) * (n + 2));
}
void func_free_tape(struct struct_automata *p)
{
	free(p->tape.tape);
}
int *func_in_stat(struct struct_automata *p, char *s)
{
	static char stat_buf[AUTOMATA_STAT_N];

	return !s ? _func_in_stat(p):__func_in_stat(p, s, stat_buf);
}
int *func_in_input(struct struct_automata *p, char *s)
{
	static char input_buf[AUTOMATA_INSYM_N];

	return !s ? _func_in_input(p):__func_in_input(p, s, input_buf);
}
size_t func_card_stat(struct struct_automata *p)
{
	return _func_card_stat(p, 0);	
}
size_t func_card_input(struct struct_automata *p)
{
	return _func_card_input(p, 0);
}
int *func_empty_input(struct struct_automata *p)
{
	return _func_empty_input(p, 0);
}
void func_alloc_stat(struct struct_automata *p, size_t n)
{
	p->symbol.stat = malloc(sizeof(int *) * (n + 1));
}
void func_alloc_input(struct struct_automata *p, size_t n)
{
	p->symbol.input = malloc(sizeof(int *) * (n + 2));
}
void func_free_stat(struct struct_automata *p)
{
	free(p->symbol.stat);
}
void func_free_input(struct struct_automata *p)
{
	free(p->symbol.input);
}
int *func_set_init(struct struct_automata *p, int *stat_p)
{
	return !stat_p ? p->status.init:(p->status.init = stat_p);
}
int *func_set_accept(struct struct_automata *p, int *stat_p)
{
	static int n;

	if(n >= p->symbol.func_card_stat(p)) return NULL;
	return !stat_p ? _func_set_accept(p):__func_set_accept(p, stat_p, &n);
}
int *func_set_current(struct struct_automata *p, int *stat_p)
{
	return !stat_p ? p->status.current:(p->status.current = stat_p);
}
int func_is_accept_current(struct struct_automata *p)
{
	return _func_is_accept_current(p, 0);	
}
void func_alloc_accept(struct struct_automata *p)
{
	p->status.accept = malloc(sizeof(int *) * p->symbol.func_card_stat(p));
}
void func_free_accept(struct struct_automata *p)
{
	free(p->status.accept);
}
int *func_in_cond_stat(struct struct_automata *p, int *stat_p, int mode)
{
	return _func_in_cond_stat(p, stat_p, mode);
}
int *func_in_cond_input(struct struct_automata *p, int *stat_p, int *input_p, int mode)
{
	return _func_in_cond_input(p, stat_p, input_p, mode, 0);
}
int *func_in_move_stat(struct struct_automata *p, int *stat_p, int *input_p, int *move_p, int mode)
{
	return _func_in_move_stat(p, stat_p, input_p, move_p, mode, 0);
}
void func_alloc_condition(struct struct_automata *p)
{
	p->move_function.condition._condition
		= malloc(sizeof(struct struct_condition) * p->symbol.func_card_stat(p));
}
void *func_alloc_domain(struct struct_automata *p)
{
	return malloc(sizeof(struct struct_domain) * p->symbol.func_card_input(p));
}
void *func_alloc_move_stat(struct struct_automata *p)
{
	return malloc(sizeof(int *) * p->symbol.func_card_stat(p));
}
void func_free_condition(struct struct_automata *p)
{
	free(p->move_function.condition._condition);
}
void func_free_domain(struct struct_automata *p)
{
	int i;

	for(i = 0; (p->move_function.condition._condition[i].cond_stat); i++)
		free(p->move_function.condition._condition[i].domain);
}
void func_free_move_stat(struct struct_automata *p)
{
	int i, j;

	for(i = 0; (p->move_function.condition._condition[i].cond_stat); i++)
		for(j = 0; (p->move_function.condition._condition[i].domain[j].cond_input); j++)
			free(p->move_function.condition._condition[i].domain[j].move_stat);
}
int *func_in_move_function(struct struct_automata *p, int *stat_p, int *input_p, int *move_p, int mode)
{
	if(!p->move_function.condition.func_in_cond_stat(p, stat_p, mode))
		return NULL;
	if(!p->move_function.condition.func_in_cond_input(p, stat_p, input_p, mode))
		return NULL;
	return p->move_function.condition.func_in_move_stat(p, stat_p, input_p, move_p, mode);
}
void func_clr_stack(struct struct_automata *p)
{
	p->move_function.graph.stack.sp = p->move_function.graph.stack.bp;
}
void func_alloc_stack(struct struct_automata *p)
{
	p->move_function.graph.stack._stack
		= malloc(sizeof(struct struct_stack) * AUTOMATA_STACK_N);
}
void func_free_stack(struct struct_automata *p)
{
	free(p->move_function.graph.stack._stack);
}
void func_init_stack(struct struct_automata *p)
{
	p->move_function.graph.stack.bp = 0; 
	p->move_function.graph.stack.sp = p->move_function.graph.stack.bp;
	p->move_function.graph.stack.func_alloc_stack(p);
}
int func_push_stack(struct struct_automata *p)
{
	if(p->move_function.graph.stack.sp < AUTOMATA_STACK_N){
		p->move_function.graph.stack._stack[p->move_function.graph.stack.sp].stat = p->status.current;
		p->move_function.graph.stack._stack[p->move_function.graph.stack.sp].tape = p->tape.tape_p;
		p->move_function.graph.stack.sp++;
		return 0;
	}
	return -1;
}
int func_pop_stack(struct struct_automata *p)
{
	if(p->move_function.graph.stack.sp > p->move_function.graph.stack.bp){
		p->move_function.graph.stack.sp--;
		p->status.current = p->move_function.graph.stack._stack[p->move_function.graph.stack.sp].stat;
		p->tape.tape_p = p->move_function.graph.stack._stack[p->move_function.graph.stack.sp].tape;
		return 0;
	}
	return -1;
}
int func_get_node_n(struct struct_automata *p)
{
	return p->move_function.graph.node_n.node_n_array[p->move_function.graph.stack.sp];
}
void func_inc_node_n(struct struct_automata *p)
{
	p->move_function.graph.node_n.node_n_array[p->move_function.graph.stack.sp]++;
}
void func_zero_node_n(struct struct_automata *p)
{
	p->move_function.graph.node_n.node_n_array[p->move_function.graph.stack.sp] = 0;
}
void func_clr_node_n(struct struct_automata *p)
{
	int i;

	for(i = 0; i < AUTOMATA_STACK_N; i++)
		p->move_function.graph.node_n.node_n_array[i] = 0;
}
void func_alloc_node_n(struct struct_automata *p)
{
	p->move_function.graph.node_n.node_n_array = malloc(sizeof(int) * AUTOMATA_STACK_N);
}
void func_free_node_n(struct struct_automata *p)
{
	free(p->move_function.graph.node_n.node_n_array);
}
void func_init_node_n(struct struct_automata *p)
{
	p->move_function.graph.node_n.func_alloc_node_n(p);
	p->move_function.graph.node_n.func_clr_node_n(p);
}
int *func_progress_graph(struct struct_automata *p, int *move_p)
{
	if(!move_p) return NULL;	
	if(p->move_function.graph.stack.func_push_stack(p) < 0) return NULL;
	if(p->move_function.move_status.func_set_input(p, NULL) != p->symbol.func_empty_input(p))
		p->tape.func_progress_tape(p);
	return p->status.func_set_current(p, move_p);
}
int *func_back_graph(struct struct_automata *p)
{
	if(p->move_function.graph.stack.func_pop_stack(p) < 0) return NULL;
	p->move_function.graph.node_n.func_inc_node_n(p);
	return p->status.func_set_current(p, NULL);
}
int *func_set_stat(struct struct_automata *p, int *stat_p)
{
	return !stat_p ? 
		p->move_function.move_status.cond.stat:
		(p->move_function.move_status.cond.stat = stat_p);
}
int *func_set_input(struct struct_automata *p, int *input_p)
{
	return !input_p ?
		p->move_function.move_status.cond.input:
		(p->move_function.move_status.cond.input = input_p);
}
int *func_set_move(struct struct_automata *p, int *move_p)
{
	return !move_p ?
		p->move_function.move_status.cond.move:
		(p->move_function.move_status.cond.move = move_p);
}
int *func_move(struct struct_automata *p)
{
	int *stat_p, *input_p, *move_p;

	stat_p  = p->move_function.move_status.func_set_stat(p, p->status.func_set_current(p, NULL));
	if((p->move_function.condition.func_in_cond_input(p, stat_p, (int *)p->tape.func_set_tape(p, NULL), 1)))
		input_p = p->move_function.move_status.func_set_input(p, (int *)p->tape.func_set_tape(p, NULL));
	else
		input_p = p->move_function.move_status.func_set_input(p, p->symbol.func_empty_input(p));
	if((move_p = p->move_function.condition.func_in_move_stat(p, stat_p, input_p, NULL, 1)))
		move_p  = p->move_function.move_status.func_set_move(p, move_p);
	return move_p;
}

static char *_func_set_tape(struct struct_automata *p, char *s)
{
	size_t len;

	if(p->tape.tape){
		p->tape.func_free_tape(p);
		p->tape.tape = NULL;
	}
	p->tape.func_alloc_tape(p, (len = strlen(s)));
	strcpy(p->tape.tape, s);
	p->tape.tape[len] = AUTOMATA_ENDM_DEF; p->tape.tape[len + 1] = '\0';
	return (p->tape.tape_p = p->tape.tape);
}
static int *_func_in_stat(struct struct_automata *p)
{
	static int n;

	if(n >= AUTOMATA_STAT_N){
		n = 0;
		return NULL;
	}
	return p->symbol.stat[n++];
}
static int *_func_in_input(struct struct_automata *p)
{
	static int n;

	if(n >= AUTOMATA_INSYM_N){
		n = 0;
		return NULL;
	}
	return p->symbol.input[n++];
}
static int *____func_in_stat(struct struct_automata *p, char buf[], int i)
{
	if(buf[i] == '\0'){
		p->symbol.stat[i] = NULL;
		return p->symbol.stat[0];
	}
	p->symbol.stat[i] = (int *)&buf[i];
	return ____func_in_stat(p, buf, i + 1);
}
static int *___func_in_stat(struct struct_automata *p, char *s, char buf[], int i)
{
	if(i >= AUTOMATA_STAT_N && *s != '\0') return NULL;
	if(*s == '\0'){
		buf[i] = '\0';
		return ____func_in_stat(p, buf, 0);
	}
	buf[i] = *s;
	return ___func_in_stat(p, s + 1, buf, i + 1);
}
static int *__func_in_stat(struct struct_automata *p, char *s, char buf[])
{
	if(!p->symbol.stat)
		p->symbol.func_alloc_stat(p, strlen(s));
	return ___func_in_stat(p, s, buf, 0);
}
static int *____func_in_input(struct struct_automata *p, char buf[] , int i)
{
	if(buf[i] == (char )AUTOMATA_EMPTY){
		p->symbol.input[i] = (int *)&buf[i];
		p->symbol.input[i + 1] = NULL;
		return p->symbol.input[0];
	}
	p->symbol.input[i] = (int *)&buf[i];
	return ____func_in_input(p, buf, i + 1);
}
static int *___func_in_input(struct struct_automata *p, char *s, char buf[], int i)
{
	if(i >= AUTOMATA_INSYM_N && *s != '\0') return NULL;
	if(*s == '\0'){
		buf[i] = AUTOMATA_EMPTY;
		return ____func_in_input(p, buf, 0);
	}
	buf[i] = *s;
	return ___func_in_input(p, s + 1, buf, i + 1);
}
static int *__func_in_input(struct struct_automata *p, char *s, char buf[])
{
	if(!p->symbol.input)
		p->symbol.func_alloc_input(p, strlen(s));
	return ___func_in_input(p, s, buf, 0);
}
static size_t _func_card_stat(struct struct_automata *p, size_t card_n)
{
	return !p->symbol.stat[card_n] ? card_n:_func_card_stat(p, card_n + 1);
}
static size_t _func_card_input(struct struct_automata *p, size_t card_n)
{
	return !p->symbol.input[card_n] ? card_n:_func_card_input(p, card_n + 1);
}
static int *_func_empty_input(struct struct_automata *p, int i)
{
	if((char )*p->symbol.input[i] == (char )AUTOMATA_EMPTY)
		return p->symbol.input[i];
	return _func_empty_input(p, i + 1);
}
static int *__func_in_cond_stat(struct struct_automata *p, int *stat_p, int mode, int i)
{
	if(i >= p->symbol.func_card_stat(p)) return NULL;
	if(!stat_p || !p->move_function.condition._condition[i].cond_stat){
		if(!mode)
			p->move_function.condition._condition[i].cond_stat = stat_p;
		return p->move_function.condition._condition[i].cond_stat;
	}
	if(stat_p == p->move_function.condition._condition[i].cond_stat)
		return p->move_function.condition._condition[i].cond_stat;
	return __func_in_cond_stat(p, stat_p, mode, i + 1);
}
static int *_func_in_cond_stat(struct struct_automata *p, int *stat_p, int mode)
{
	if(!p->move_function.condition._condition)
		p->move_function.condition.func_alloc_condition(p);
	return __func_in_cond_stat(p, stat_p, mode, 0);
}
static int *___func_in_cond_input(struct struct_automata *p, int *input_p, int mode, int i, int j)
{
	if(j >= p->symbol.func_card_input(p)) return NULL;
	if(!input_p || !p->move_function.condition._condition[i].domain[j].cond_input){
		if(!mode)
			p->move_function.condition._condition[i].domain[j].cond_input = input_p;
		return p->move_function.condition._condition[i].domain[j].cond_input;
	}
	if((char )*input_p == (char )*p->move_function.condition._condition[i].domain[j].cond_input)
		return p->move_function.condition._condition[i].domain[j].cond_input;
	return ___func_in_cond_input(p, input_p, mode, i, j + 1);
}
static int *__func_in_cond_input(struct struct_automata *p, int *input_p, int mode, int i)
{
	if(!p->move_function.condition._condition[i].domain)
		if(!(p->move_function.condition._condition[i].domain
					= p->move_function.condition.func_alloc_domain(p)))
			return NULL;
	return ___func_in_cond_input(p, input_p, mode, i, 0);
}
static int *_func_in_cond_input(struct struct_automata *p, int *stat_p, int *input_p, int mode, int i)
{
	if(i >= p->symbol.func_card_stat(p)
			|| !p->move_function.condition._condition[i].cond_stat) return NULL;
	if(stat_p == p->move_function.condition._condition[i].cond_stat)
		return __func_in_cond_input(p, input_p, mode, i);
	return _func_in_cond_input(p, stat_p, input_p, mode, i + 1);
}
static int *____func_in_move_stat(struct struct_automata *p, int *move_p, int mode, int i, int j, int k)
{
	int node_n;

	if(k >= p->symbol.func_card_stat(p)) return NULL;
	if(!move_p || !p->move_function.condition._condition[i].domain[j].move_stat[k]){
		if(!mode){
			p->move_function.condition._condition[i].domain[j].move_stat[k] = move_p;
			return p->move_function.condition._condition[i].domain[j].move_stat[k];
		}
		node_n = p->move_function.graph.node_n.func_get_node_n(p);
		return p->move_function.condition._condition[i].domain[j].move_stat[node_n];
	}
	if(move_p == p->move_function.condition._condition[i].domain[j].move_stat[k])
		return p->move_function.condition._condition[i].domain[j].move_stat[k];
	return ____func_in_move_stat(p, move_p, mode, i, j, k + 1);
}
static int *___func_in_move_stat(struct struct_automata *p, int *move_p, int mode, int i, int j)
{
	if(!p->move_function.condition._condition[i].domain[j].move_stat)
		if(!(p->move_function.condition._condition[i].domain[j].move_stat
					= p->move_function.condition.func_alloc_move_stat(p)))
			return NULL;
	return ____func_in_move_stat(p, move_p, mode, i, j, 0);
}
static int *__func_in_move_stat(struct struct_automata *p, int *input_p, int *move_p, int mode, int i, int j)
{
	if(j >= p->symbol.func_card_input(p)
			|| !p->move_function.condition._condition[i].domain[j].cond_input) return NULL;
	if((char )*input_p == (char )*p->move_function.condition._condition[i].domain[j].cond_input)
		return ___func_in_move_stat(p, move_p, mode, i, j);
	return __func_in_move_stat(p, input_p, move_p, mode, i, j + 1);
}
static int *_func_in_move_stat(struct struct_automata *p, int *stat_p, int *input_p, int *move_p, int mode, int i)
{
	if(i >= p->symbol.func_card_stat(p)
			|| !p->move_function.condition._condition[i].cond_stat) return NULL;
	if(stat_p == p->move_function.condition._condition[i].cond_stat)
		return __func_in_move_stat(p, input_p, move_p, mode, i, 0);
	return _func_in_move_stat(p, stat_p, input_p, move_p, mode, i + 1);
}
static int *_func_set_accept(struct struct_automata *p)
{
	static int n;

	if(n >= p->symbol.func_card_stat(p) || !p->status.accept[n]){
		n = 0;
		return NULL;
	}
	return p->status.accept[n++];
}
static int *__func_set_accept(struct struct_automata *p, int *stat_p, int *n)
{
	if(!p->status.accept)
		p->status.func_alloc_accept(p);
	return (p->status.accept[*n++] = stat_p);
}
static int _func_is_accept_current(struct struct_automata *p, int i)
{
	if(i >= p->symbol.func_card_stat(p) || !p->status.accept[i])
		return 0;
	if(p->status.current == p->status.accept[i])
		return 1;
	return _func_is_accept_current(p, i + 1);
}
