/* This program implements stack data structure. Fill random  *
 * numbers to stack and find index of wanted number in stack. */

#include <stdbool.h> /* C99 only */
#include <stdio.h>
#include <time.h>


#define STACK_SIZE 100
#define MAX_NUMBER 1000
#define WANTED_NUMBER 2     // number that we want to find in stack


/* external variables */
int contents[STACK_SIZE];     // stack
int top = 0;                  // index of stack

/* function prototypes */
void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(int);
int pop(void);
void stack_overflow(void);
void stack_underflow(void);
void fill_stack(void);       // fill stack with random numbers
int find_stack(int);         // find wanted number in stack and return index



void main()
{
    srand((unsigned) time(NULL));    // initialize random function

    make_empty();
    fill_stack();

    int index_of_wanted_number = find_stack(WANTED_NUMBER);

    if(index_of_wanted_number != -1)
    {
        printf("Value of %dth index is %d\n", index_of_wanted_number, WANTED_NUMBER);
    }
    else
    {
        printf("Cannot find number in stack.");
    }
    return 0;
}

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

void push(int i)
{
    if (is_full())
        stack_overflow();
    else
        contents[top++] = i;
}

int pop(void)
{
    if (is_empty())
        stack_underflow();
    else
        return contents[--top];
}

void stack_overflow()
{
    printf("Stack overflow ");
    exit(0);
}
void stack_underflow()
{
    printf("Stack underflow ");
    exit(0);
}


void fill_stack(void)
{
    int i = 0;

    for(i; i < STACK_SIZE; i++)
    {
        push(rand() % MAX_NUMBER);
    }
}

int find_stack(int number)
{
    int i = 0;

    for(i; i <= STACK_SIZE; i++)
    {
        if(contents[i] == number)
            return i;
    }
    return -1;
}
