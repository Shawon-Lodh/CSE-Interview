#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

struct node *newNode(int data)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;
	return temp;
}

void printlist(struct node *head)
{
	struct node *temp = head;
	while(temp!=NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}

void detectloop(struct node *head)
{
	struct node *fast = head->next;
	struct node *slow = head;
	
	while(fast && fast->next)
	{
		if(slow == fast)
		{
			printf("LOOP is Detected....");
			break;
		}
		slow = slow->next;
		fast = fast->next->next;
	}
	
	if(slow == fast)   // if loop is detected...
	{
		slow = head;
		
		while(slow != fast->next)
		{
			slow = slow->next;
			fast = fast->next;
		}
		
		fast->next = NULL;
	}
}

int main()
{
	// SEE THE LAST METHOD OF http://www.geeksforgeeks.org/detect-and-remove-loop-in-a-linked-list/   V.IMPORTANT...
	
	struct node *head = newNode(50);
    head->next = newNode(20);
    head->next->next = newNode(15);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(10);
 
    /* Create a loop for testing */
    head->next->next->next->next->next = head->next->next;
    
    detectloop(head);
    printf("\n\n");
    printf("List after removal of loop:   ");
    printlist(head);
	return 0;
}
