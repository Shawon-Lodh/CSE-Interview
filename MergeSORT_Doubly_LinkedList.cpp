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

void push(struct node **head_ref, int data)
{
	struct node *newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = data;
	newnode->next = *head_ref;
	(*head_ref)->prev = newnode;
	newnode->prev = NULL;
	*head_ref = newnode;
}

struct node* split(struct node *head)
{
	struct node *slow = head;
	struct node *fast = head;
	
	while(fast->next !=NULL && fast->next->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	
	struct node *second = slow->next;
	slow->next = NULL;
	
	return second;
}

struct node* merge(struct node *first, struct node *second)
{
	if(first == NULL)
	{
		return second;
	}
	if(second == NULL)
	{
		return first;
	}
	
	if(first->data < second->data)
	{
		first->next = merge(first->next, second);
		first->next->prev = first;
		first->prev = NULL;  //As it is constructing from last to first in recurssion...IMAGINE...
		return first;
	}
	else if(second->data < first->data)
	{
		second->next = merge(first, second->next);
		second->next->prev = second;
		second->prev = NULL;  //As it is constructing from last to first in recurssion...IMAGINE...
		return second;
	}
}

struct node* mergesort(struct node *head)
{
	if (!head || !head->next)
        return head;
	
	struct node *second = split(head);
	
	head = mergesort(head);
	second = mergesort(second);
	
	return merge(head, second);
}

int main()
{
	struct node *head = (struct node*)malloc(sizeof(struct node));
	head->prev = NULL;
	head->next = NULL;
	head->data = 20;
	
	push(&head, 10); 
	push(&head, 40); 
	push(&head, 60); 
	push(&head, 50); 
	push(&head, 70); 
	push(&head, 30); 
	
	printf("LinkedList:  ");
	printlist(head);
	printf("\n\n");
	struct node *headSort = mergesort(head);
	printf("Sorted LinkedList:  ");
	printlist(headSort);
	return 0;
}
