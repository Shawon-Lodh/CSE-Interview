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

/*void reverselist(struct node **head_ref)
{
	struct node *prev = NULL;
	struct node *curr = *head_ref;
	struct node *next;
	
	struct node *newhead = *head_ref;
	int i=1;
	while(i<k)
	{
		newhead = newhead->next;
		i++;
	}
//	printf("%d", newhead->data);
	i = 1; 
	while(curr!=NULL)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr=next;
	//	i++;
	}
	
	*head_ref = prev;
}  */



void addNumbers(struct node *head1, struct node *head2)
{
	struct node *temp1 = head1;
	struct node *temp2 = head2;
	int sum1 =0;
	int sum2 =0;
	
	while(temp1 != NULL)
	{
		sum1 = 10*sum1 + temp1->data;
		temp1 = temp1->next;
	}
	
	while(temp2 != NULL)
	{
		sum2 = 10*sum2 + temp2->data;
		temp2 = temp2->next;
	}
	
	int finalsum = sum1 + sum2;
	
	printf("\n\nSum is :  %d", finalsum);
}

int main()
{
	struct node *head = (struct node*)malloc(sizeof(struct node));
	head->data = 6;
	head->next = NULL;
	
	push(&head, 4);
	push(&head, 9);
	push(&head, 5);
	push(&head, 7);
//	push(&head, 4);
//	push(&head, 3);
//	push(&head, 2);
//	push(&head, 1);
	printf("LinkedList 1:  ");
	
//	int k = 3;
//	reverselist(&head);
	printlist(head);
	
	
	struct node *head2 = (struct node*)malloc(sizeof(struct node));
	head2->data = 4;
	head2->next = NULL;
	
	push(&head2, 8);
/*	push(&head2, 3);
	push(&head2, 4);
	push(&head2, 5);
	push(&head2, 6);
	push(&head2, 7);
	push(&head2, 8);
	push(&head2, 9); */
	printf("\n\nLinkedList 2:  ");
	printlist(head2);
	
	addNumbers(head, head2);
	
	return 0;
}
