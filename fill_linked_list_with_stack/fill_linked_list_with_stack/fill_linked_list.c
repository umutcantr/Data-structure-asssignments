 
#include<stdlib.h>
#include<stdio.h>
#include <time.h>
#include <stdbool.h>

#include "stack.h"
#include "linked_list.h"


#define WANTED_NUMBER 2         // number that we want to find in linked list


void main()
{
	srand((unsigned)time(NULL));    // initialize random function

	struct stack s;

	fill_stack(&s);

	zero();
	list_fill(&s);                  // fill list with stack
	list_print();

	int index_of_wanted_number = list_find(WANTED_NUMBER);

	if (index_of_wanted_number != - 1)
	{
		printf("Value of %dth index is %d\n", index_of_wanted_number, WANTED_NUMBER);
	}
	else
	{
		printf("Cannot find number in list.");
	}
}


