#define LIST_SIZE 100


/* Single linked list struct */
struct node {
	int data;
	struct node* next;
};
typedef struct node* SllNodePtr;   // Pointer to single linked list node

/* Linked list function prototypes */
SllNodePtr get_node(void);
void list_add(int data, SllNodePtr prev_node);
void list_fill(struct stack* s);
int list_find(int number);
void zero(void);
void list_print(void);


struct node* zeroth_node;           // İnitialize zeroth node of linked list
struct node* last_node;             // İnitialize keep track last node of linked list


SllNodePtr get_node()
{
	struct node* p;
	p = malloc(sizeof(struct node));

	if (p == NULL)
	{
		fprintf(stderr, "Unable to allocate memory for new node\n");
		exit(-1);
	}
	else
	{
		p->next = NULL;                     // initialize as a NULL            
	}

	return p;
}

void list_add(int data, SllNodePtr prev_node)
{
	struct node* new_node = get_node();

	new_node->data = data;                 // initialize heap memory 
	new_node->next = NULL;                 // initialize heap memory 

	if (prev_node->next != NULL)
	{
		new_node->next = prev_node->next;  // insert middle
	}

	prev_node->next = new_node;
	last_node = new_node;                  // update last node
}

void list_fill(struct stack* s)
{
	int i = 0;

	for (i; i < LIST_SIZE - 1; i++)
	{
		list_add(s->stack[i], last_node);
	}
}

int list_find(int number)
{
	struct node* p = zeroth_node;
	int counter = 0;

	while (p)
	{
		if (p->data == number)
		{
			return counter;
		}
		else
		{
			p = p->next;
			counter++;
		}
	}
	return -1;
}

// initialize zeroth node
void zero(void)
{
	zeroth_node = get_node();
	zeroth_node->data = 0;
	zeroth_node->next = NULL;

	last_node = zeroth_node;
}

void list_print(void)
{
	SllNodePtr p = zeroth_node;

	printf("Single linked list: \n");
	while (p != NULL) {
		printf("%d --->", p->data);
		p = p->next;
	}
	printf("\n\n");
}

