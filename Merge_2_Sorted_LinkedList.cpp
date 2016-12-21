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


void mergelist(struct node **head_ref1, struct node **head_ref2)
{
	struct node *temp1 = (struct node*)malloc(sizeof(struct node));
	temp1 = *head_ref1;
	
	struct node *temp2 = (struct node*)malloc(sizeof(struct node));
	temp2 = *head_ref2;
	
	struct node *headf = (struct node*)malloc(sizeof(struct node));
	headf->next = NULL;
	if(temp1->data < temp2->data)
	{
		headf->data = temp1->data;
		temp1 = temp1->next;
	}	
	else
	{
		headf->data = temp2->data;
		temp2 = temp2->next;
	}
	
	
	while(temp1!=NULL && temp2!=NULL)
	{
		if(temp1->data < temp2->data)
		{
			push(&headf, temp1->data);
			temp1 = temp1->next;
		}
		else
		{
			push(&headf, temp2->data);
			temp2 = temp2->next;
		}
	}
	
	if(temp1 == NULL)
	{
		while(temp2!=NULL)
		{
			push(&headf, temp2->data);
			temp2 = temp2->next;
		}
	}
	
	if(temp2 == NULL)
	{
		while(temp1!=NULL)
		{
			push(&headf, temp1->data);
			temp1 = temp1->next;
		}
	}
	
	reverselist(&headf);
	printf("Merged List:  ");
	printlist(headf);
}

int main()
{
	struct node *head = (struct node*)malloc(sizeof(struct node));
	head->data = 10;
	head->next = NULL;
	
	push(&head, 12);
	push(&head, 14);
	push(&head, 16);
	push(&head, 18);
	printf("LinkedList 1:  ");
	reverselist(&head);
	printlist(head);
	
	printf("\n");
	struct node *head2 = (struct node*)malloc(sizeof(struct node));
	head2->data = 11;
	head2->next = NULL;
	
	push(&head2, 13);
	push(&head2, 15);
	push(&head2, 17);
	push(&head2, 19);
	printf("LinkedList 2:  ");
	reverselist(&head2);
	printlist(head2);
	
	
	printf("\n\n");
	mergelist(&head, &head2);
	
	return 0;
}
