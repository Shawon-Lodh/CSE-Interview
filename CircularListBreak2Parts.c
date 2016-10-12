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


void breakList(struct node **head_ref, int len)
{
	if(*head_ref==NULL || (*head_ref)->next == NULL)
	{
		printf("Insufficient Nodes in the list");
		return ;
	}
	
	int lenhf = (len-1)/2;
	
	int count1 =0;
	int count2 = 0;
	
	
	struct node *last1 = *head_ref;
	struct node *first2 = NULL;
	
	struct node *last2 = *head_ref;
	
	while(count1<lenhf-1)
	{
		last1 = last1->next;
		count1++;
	}
	
	first2 = last1->next;
	
	while(count2<len-1)
	{
		last2 = last2->next;
		count2++;
	}
	
	last1->next = (*head_ref);
	
	last2->next = first2;
	struct node *head2 = first2;
	
	
	struct node* curr = *head_ref;
    
    	struct node *prev;
//	int count11 = 0;
	do
	{
		prev = curr;
		printf("%d ", prev->data); // printing all the node data using loop
		
		curr = curr->next;
//		count++;
	}while(curr!=*head_ref);
	
	
	printf("\n");
	
	
	struct node* curr2 = head2;
    
    	struct node *prev2;
//	int count11 = 0;
	do
	{
		prev2 = curr2;
		printf("%d ", prev2->data); // printing all the node data using loop
		
		curr2 = curr2->next;
//		count++;
	}while(curr2!=head2);
	
	
}



int main()
{
	struct node *head = createNode(10);
	
	
	
	push(&head, 12);
    push(&head, 56);
    push(&head, 2);
    push(&head, 11);
    push(&head, 20);
    push(&head, 25);
    push(&head, 30);
    push(&head, 40); 
    
    struct node* curr = head;
    
    	struct node *prev;
    	
    	int count = 0;
	do
	{
		prev = curr;
		printf("%d ", prev->data); // printing all the node data using loop
		
		curr = curr->next;
		count++;
	}while(curr!=head);
	
	printf("\n");
	
	
	breakList(&head, count);
	
////	struct node *check = prev->next; //checking if the last node is connected to head or not
//	printf("%d", (check)->data);
//	printf("\n%d", count);
	
	return 0;
}
