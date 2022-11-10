#include<stdio.h>

#define MAX_NUMBER 100             // number that we want to find in linked list
#define STACK_SIZE 100


/* Stack struct */
struct stack {
	char stack[STACK_SIZE];
};


/* Stack function prototypes */
void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(struct stack*, char);
char pop(struct stack*);
void stack_overflow(void);
void stack_underflow(void);
void fill_stack(struct stack*);                 // fill stack with content of queue struct
int find_stack(struct stack*, int);             // find wanted number in stack and return index


/* External variables */
int top = 0;

void make_empty(void)
{
	top = 0;
}

bool is_empty(void)
{
	return top == 0;
}

bool is_full(void)
{
	return top == STACK_SIZE;
}

void push(struct stack* s, char c)
{
	if (is_full())
		stack_overflow();
	else
		s->stack[top++] = c;
}

char pop(struct stack* s)
{
	if (is_empty())
	{
		stack_underflow();
		return 0;
	}
	else
		return s->stack[--top];
}

void stack_overflow()
{
	printf("\nStack overflow ");
	exit(1);
}
void stack_underflow()
{
	printf("\nStack underflow ");
	exit(1);
}


void fill_stack(struct stack* s)
{
	int i = 0;

	for (i; i < STACK_SIZE - 1; i++)
	{
		push(s, rand() % MAX_NUMBER);
	}
}

int find_stack(struct stack* s, int number)
{
	int i = 0;

	for (i; i <= STACK_SIZE - 1; i++)
	{
		if (s->stack[i] == number)
			return i;
	}
	return -1;
}