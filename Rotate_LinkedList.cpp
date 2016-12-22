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



/* void addNumbers(struct node *head1, struct node *head2)
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
} */


void rotatelist(struct node **head_ref, int k)
{
	struct node *headprev = *head_ref;
	struct node *temp = *head_ref;
	struct node *last = *head_ref;
	struct node *prev = NULL;
	int i =1;
	while(i<=k)
	{
		prev = temp;
		temp = temp->next;
		i++;
	}
	
	while(last->next!=NULL)
	{
		last = last->next;
	}
	
	last->next = *head_ref;
	prev->next = NULL;
	*head_ref = temp;
	
}

int main()
{
	struct node *head = (struct node*)malloc(sizeof(struct node));
	head->data = 60;
	head->next = NULL;
	
	push(&head, 50);
	push(&head, 40);
	push(&head, 30);
	push(&head, 20);
	push(&head, 10);
//	push(&head, 3);
//	push(&head, 2);
//	push(&head, 1);
	printf("LinkedList :  ");
	printlist(head);
	
	rotatelist(&head, 4);
	printf("\n\n");
	printf("LinkedList after Rotation:  ");
	printlist(head);

	
	return 0;
}
