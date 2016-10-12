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

void insertLast(struct node **head_ref, int data)
{
	if(*head_ref == NULL)
	{
		(*head_ref)->data = data;
		(*head_ref)->next = NULL;
		(*head_ref)->prev = NULL;
		
		return ;
	}
	
	struct node *temp = *head_ref;
	
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	
	struct node *newnode = (struct node*)malloc(sizeof(struct node));
	
	newnode->data = data;
	
	temp->next = newnode;
	newnode->prev = temp;
	newnode->next = NULL;
	
}




int main()
{
	struct node *head = createNode(10);
	
	
	

    insertLast(&head, 56);
    insertLast(&head, 2);
    insertLast(&head, 11);
    insertLast(&head, 20);
    insertLast(&head, 25);
    insertLast(&head, 30);
    insertLast(&head, 40); 
    
    struct node* curr = head;
    
    	struct node *prev;
    	

	while(curr!=NULL)
	{
		prev = curr;
		printf("%d ", prev->data); // printing all the node data using loop
		
		curr = curr->next;
//		count++;
	}
	
	printf("\n");
	
	
	struct node *secondlast = (prev->prev);
	printf("%d", secondlast->data);
	
;
	
	return 0;
}


