#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	struct node *next;	
};

void push(struct node **head_ref, int data)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	
	temp->next = *head_ref;
	*head_ref = temp;
}

void  printlist(struct node *head)
{
	struct node *temp = head;
	
	while(temp!=NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}

void reverselist(struct node **head_ref)
{
	struct node *prev = NULL;
	struct node *curr = *head_ref;
	struct node *next;
	
	while(curr!=NULL)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr=next;
	}
	
	*head_ref = prev;
}

int main()
{
	struct node *head = (struct node*)malloc(sizeof(struct node));
	head->data = 10;
	head->next = NULL;
	
	push(&head, 11);
	push(&head, 12);
	push(&head, 13);
	push(&head, 14);
	push(&head, 15);
	printf("LinkedList:  ");
	printlist(head);
	
	reverselist(&head);
	printf("\n");
	printf("Reversed LinkedList:  ");
	printlist(head);
	return 0;
}
