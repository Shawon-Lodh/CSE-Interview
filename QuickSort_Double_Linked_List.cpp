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

struct node *lastnode(struct node *head)
{
	while(head != NULL && head->next != NULL)
	{
		head = head->next;
	}
	
	return head;
}


struct node *partition(struct node *first, struct node *last)
{
	int x = last->data;
	struct node *i = first->prev;
	struct node *j = NULL;
	
	for(j = first; j != last; j = j->next)
	{
		if(j->data <= x)
		{
			i = (i == NULL)? first : i->next;
			
			swap(&(i->data), &(j->data));
		}
	}
	
	i = (i == NULL)? first : i->next;
			
	swap(&(i->data), &(last->data));
	return i;
}

void _quicksort(struct node *head, struct node *last)
{
	if(last!=NULL && head != last && head != last->next ) // Ordering inside if is impportant.....
	{
		struct node *mid = partition(head, last);
		_quicksort(head, mid->prev);
		_quicksort(mid->next, last);
	}
}

void quickSort(struct node *head)
{
	struct node *last = lastnode(head);
	
	_quicksort(head, last);
}

int main()
{
	struct node *head = (struct node*)malloc(sizeof(struct node));
	head->data = 10;
	head->prev = head->next = NULL;
	
	push(&head, 30);
	push(&head, 50);
	push(&head, 20);
	push(&head, 40);
	push(&head, 70);
	push(&head, 60);
	printf("Un-Sorted LinkedList:  ");
	printlist(head);
	
	printf("\n\n");
	quickSort(head);
	printf("Sorted LinkedList:  ");
	printlist(head);
	return 0;
}
