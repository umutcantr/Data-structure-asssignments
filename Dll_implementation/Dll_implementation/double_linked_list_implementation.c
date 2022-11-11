
#include<stdlib.h>
#include<stdio.h>
#include <time.h>


#define LIST_SIZE 100
#define MAX_NUMBER 50
#define WANTED_NUMBER 2             // number that we want to find in linked list

struct DllNode {
	int data;
	struct DllNode* prev;
	struct DllNode* next;
};
typedef struct DllNode* DllNodePtr;


DllNodePtr zeroth_node;           // zeroth node
DllNodePtr last_node;             // keep track of last node

/* function prototypes */
void zero(void);
DllNodePtr get_node(void);
void list_add(int data, DllNodePtr prev_node);
void list_print(void);
void list_fill(void);




void main(void) 
{
	srand((unsigned)time(NULL));    // initialize random function

	zero();
	list_fill();
	list_print();
}


DllNodePtr get_node() {
	DllNodePtr p;
	p = malloc(sizeof(struct DllNode));

	if (p == NULL)
	{
		fprintf(stderr, "Unable to allocate memory for new node\n");
		exit(-1);
	}
	else
	{
		p->prev = NULL;                     // initialize as a NULL       
		p->next = NULL;                     // initialize as a NULL 
	}

	return p;
}

// initialize zeroth node
void zero()
{
	zeroth_node = get_node();
	zeroth_node->data = 0;
	zeroth_node->next = NULL;

	last_node = zeroth_node;
}

void list_add(int data, DllNodePtr prev_node)
{
	DllNodePtr new_node = get_node();

	new_node->data = data;                 // assign data to new node

	if (prev_node->next != NULL)
	{
		new_node->next = prev_node->next;  // insert middle
		prev_node->next->prev = new_node;
	}

	prev_node->next = new_node;
	new_node->prev = prev_node;
	last_node = new_node;                  // update last node
}

void list_print()
{
	DllNodePtr p = zeroth_node;

	printf("Double linked list(next): \n");
	while (p != NULL) {
		printf("%d --->", p->data);
		p = p->next;
	}
	printf("\n\n");

	p = last_node;
	printf("Double linked list(prev): \n");
	while (p != zeroth_node) {
		printf("%d --->", p->data);
		p = p->prev;
	}
	printf("\n\n");
}


void list_fill()
{
	int i = 0;

	for (i; i <= LIST_SIZE; i++)
	{
		list_add((rand() % MAX_NUMBER), last_node);
	}
}