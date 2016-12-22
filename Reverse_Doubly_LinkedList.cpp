#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	struct node *next;
	struct node *prev;	
};

void printlist(struct node *head)
{
	struct node *temp = head;
	while(temp!=NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void push(struct node **head_ref, int data)
{
	struct node *newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = data;
	newnode->next = *head_ref;
	(*head_ref)->prev = newnode;
	newnode->prev = NULL;
	*head_ref = newnode;
}

void reverse(struct node **head_ref)
{
	struct node *curr = *head_ref;
	struct node *temp =  NULL;
	  
	while(curr != NULL)
	{
		temp = curr->prev;
		curr->prev = curr->next;
		curr->next = temp;
		curr = curr->prev;
	}
	
	if(temp != NULL)
	{
		*head_ref = temp->prev;
	}
}

int main()
{
	struct node *head = (struct node*)malloc(sizeof(struct node));
	head->data = 10;
	head->prev = head->next = NULL;
	
	push(&head, 20);
	push(&head, 30);
	push(&head, 40);
	push(&head, 50);
	push(&head, 60);
	push(&head, 70);
	printlist(head);
	reverse(&head);
	printf("\n\n");
	printlist(head);
	return 0;
}
