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

void push(struct node **head_ref, int data)
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




void deletenode(struct node **head_ref, int data)
{
	if(*head_ref == NULL)
	{
		printf("the list is already empty");
		return ;
	}
	
	if((*head_ref)->next == NULL && (*head_ref)->data == data)
	{
		*head_ref == NULL;
		return;
	}
	
	struct node *temp = *head_ref;
	struct node *prev = NULL;
	
	while(temp->data != data)
	{
		prev = temp;
		temp = temp->next;
	}
	
	if(temp == NULL)
	{
		printf("Node not found");
		return ;
	}
	
	if(temp->next == NULL)
	{
		prev->next = NULL;
		free(temp);
		return ;
	}
	
	temp->next->prev = prev;
	prev->next = temp->next;
	
	free(temp);
	
}









int main()
{
	struct node *head = createNode(10);
	
	
	

    push(&head, 56);
    push(&head, 2);
    push(&head, 11);
    push(&head, 20);
    push(&head, 25);
    push(&head, 30);
    push(&head, 40); 
    
    struct node* curr = head;
    
    	struct node *prev;
    	

	while(curr!=NULL)
	{
		prev = curr;
		printf("%d ", prev->data); // printing all the node data using loop
		
		curr = curr->next;
//		count++;
	}
	
//	deletenode(&head, 10);
/*	deletenode(&head, 56);
    deletenode(&head, 2);
    deletenode(&head, 11);
    deletenode(&head, 20);
    deletenode(&head, 25);
    deletenode(&head, 30);
    deletenode(&head, 40); */
 //   deletenode(&head, 40);
 
 
	
	printf("\n");
 struct node* curr1 = head;
    
    	struct node *prev1;
    	

	while(curr1!=NULL)
	{
		prev1 = curr1;
		printf("%d ", prev1->data); // printing all the node data using loop
		
		curr1 = curr1->next;
//		count++;
	}
	
	return 0;
}
