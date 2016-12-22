#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	struct node *next;	
};

void printlist(struct node *head)
{
	struct node *temp = head;
	do
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	while(temp != head);
}

void sortedinsert(struct node **head_ref, int data)
{
	struct node *newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = data;
	
	
	struct node *head = *head_ref;
	
	struct node *last = *head_ref;
	while(last->next != (*head_ref))
	{
		last = last->next;
	}
	
	if(head->data > data)
	{		
		struct node *last = *head_ref;
		while(last->next != (*head_ref))
		{
			last = last->next;
		}
		
		newnode->next = *head_ref;
		last->next = newnode;
		*head_ref = newnode;
	}
	
	else if(last->data < data)
	{
		last->next = newnode;
		newnode->next = *head_ref;
	}
	
	else
	{
		struct node *temp = *head_ref;
		struct node *prev = NULL;
		
		while(temp->data <= data)
		{
			prev = temp;
			temp = temp->next;
		}
		
		prev->next = newnode;
		newnode->next = temp;
	}
}

int main()
{
	struct node *head = (struct node*)malloc(sizeof(struct node));
	head->data = 10;
	head->next = head;
	
	sortedinsert(&head, 20);
	sortedinsert(&head, 40);
	sortedinsert(&head, 30);
	sortedinsert(&head, 5);
	sortedinsert(&head, 100);

	printlist(head);
	
	return 0;
}
