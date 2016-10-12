/* Following is the program demonstrating how to create a circular linked list and traverse it */

#include <stdio.h>
#include <stdlib.h>

/* First step is creation of a structure (struct node) which would contain the data types for a cell of linked list*/

struct node
{
	int data;
	struct node *next; // "next" is a pointer which will point to an address of type struct node, i.e:- pointing to another node
};

struct node* createNode(int data)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	
	temp->data = data;
	
	temp->next = NULL;
	
	return temp;
}

void push(struct node **head_ref, int data)
{
	
	struct node *newnode = (struct node*)malloc(sizeof(struct node));
		newnode->data = data;
		
	if((*head_ref)->next==NULL)
	{
		
		(*head_ref)->next = newnode;
		newnode->next = (*head_ref);
		
		return ;
	}
	
	struct node *temp = (*head_ref)->next;
	
	while(temp->next!=(*head_ref))
	{
		temp = temp->next;
		
	}
	
	temp->next = newnode;
	newnode->next = (*head_ref);
	
	
	
}


int main()
{
	struct node *head = createNode(10);
	
	
	
	push(&head, 12);
    push(&head, 56);
    push(&head, 2);
    push(&head, 11);
    
    struct node* curr = head;
    
    	struct node *prev;
	do
	{
		prev = curr;
		printf("%d ", prev->data); // printing all the node data using loop
		
		curr = curr->next;
	}while(curr!=head);
	
	
	struct node *check = prev->next; //checking if the last node is connected to head or not
	printf("%d", (check)->data);
	
	return 0;
}
