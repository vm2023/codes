#include <stdio.h>
#include <stdint.h>
#include <malloc.h>
#include <stdlib.h>

/* Numbers list */
typedef struct list
{
	uint32_t number;
	struct list *next;
}NODE;


NODE *head = NULL;


/* insert node in the end */
void insert_node(NODE *node)
{
	if (!head)
	{
		head = node;
		return;
	}

	NODE *temp = head;

	while (temp->next)
	{
		temp = temp->next;
	}

	temp->next = node;
}

/* delete the last node from the list */
void delete_node(void)
{
	/* empty list check */
	if (!head)
	{
		printf("List is already empty");
		return;
	}

	/* list contains only one node */
	if (head->next == NULL)
	{
		free(head);
		head = NULL;
		return;
	}

	/*find second last node */
        NODE *temp = head;

	while (temp->next->next)
	{
	    temp = temp->next;    	
        }

	free(temp->next);
	temp->next = NULL;
}


/* Display list contents to the user */
void print_list()
{
	NODE *temp = head;
	if (!head)
	{
		printf("\nVM: list is empty\n");
		return;
	}
	while (temp)
	{
		printf("%d\t", temp->number);
		temp = temp->next;
	}
}

int main(void)
{
    NODE *nodeptr = NULL;
    uint8_t user_input = 0;
    uint8_t num = 0;

    while(1)
    {
    	printf ("\n1. insert node in a list\n2. delete node from the list\n3. display list\n4. exit\n=");
	scanf("%hhd", &user_input);
	switch (user_input)
	{
	    case 1: 
                nodeptr = (NODE*)malloc(sizeof(NODE));
		if (!nodeptr)
		{
			printf("\nmemory allocation failed !\n");
			return 0;
		}
		printf ("\nEnter value to be inserted = ");
		scanf("%hhd", &num);
		nodeptr->number  = num;
		nodeptr->next = NULL;
		insert_node(nodeptr);
		break;
	
	    case 2:
		delete_node();
		break;

	    case 3:
                print_list();
	        break;
	    case 4:
	        exit(EXIT_SUCCESS);

	    default:
		printf("\nInvalid input\n");
		break;
        }
    }
}
