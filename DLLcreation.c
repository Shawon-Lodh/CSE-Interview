/* Following is the program demonstrating how to create a simple doubly linked list */

#include <stdio.h>
#include <stdlib.h>

/* First step is creation of a structure (struct node) which would contain the data types for a cell of linked list*/

struct node
{
	int data;
	struct node *next; // "next" is a pointer which will point to an address of type struct node, i.e:- pointing to another node
	struct node *prev;
};

struct node* createNode(int data)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	
	temp->data = data;
	
	temp->next = NULL;
	temp->prev = NULL;
	
	return temp;
}

int main()
{
	struct node *head = (struct node*)malloc(sizeof(struct node));
	
	head->data = 10;
	
	head->prev = NULL;
	head->next = createNode(20);
	
	head->next->prev = head;
	
	head->next->next = createNode(30);
	head->next->next->prev = head->next;
	
	struct node *result = head->next->prev;
	printf("%d", result->data);
}


