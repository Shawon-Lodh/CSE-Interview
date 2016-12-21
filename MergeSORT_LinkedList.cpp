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

void frontBackSplit(struct node *source, struct node **front_ref, struct node **back_ref)
{
	if(source == NULL || source->next == NULL)
	{
		*front_ref = source;;
		*back_ref = NULL;
	}
	
	else
	{
		struct node *slow;
		struct node *fast;
		
		slow = source;
		fast = source->next;
		
		while(fast!=NULL)
		{
			fast = fast->next;
			if(fast!=NULL)
			{
				slow = slow->next;
				fast = fast->next;
			}
		}
		
		*front_ref = source;
		*back_ref = slow->next;
		slow->next = NULL; // to deattach the linkedlist in 2 parts
	}
}

struct node* sortedMerge(struct node *a, struct node *b)
{
	struct node *head = NULL;
	if(a == NULL)
	{
		return b;
	}
	else if(b == NULL)
	{
		return a;
	}
	

		if(a->data <= b->data)
		{
			head = a;
			head->next = sortedMerge(a->next, b);
		}
		else
		{
			head = b;
			head->next = sortedMerge(a, b->next);
		}
	
	return head;
}

void mergesort(struct node **head_ref)
{
	struct node *head = *head_ref;
	struct node *a;
	struct node *b;
	
	if(head ==  NULL || head->next == NULL)
	{
		return;
	}
	
	frontBackSplit(head, &a, &b);
	
	mergesort(&a);
	mergesort(&b);
	
	*head_ref = sortedMerge(a, b);
	
	

}

int main()
{
	struct node *head = (struct node*)malloc(sizeof(struct node));
	head->data = 10;
	head->next = NULL;
	
	push(&head, 12);
	push(&head, 4);
	push(&head, 1);
	push(&head, 6);
	printf("LinkedList:  ");
	printlist(head);
	printf("\n\n");
	mergesort(&head);
	printf("Sorted LinkedList:  ");
	printlist(head);
	return 0;
}
