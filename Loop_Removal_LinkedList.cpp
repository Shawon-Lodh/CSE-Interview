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
	unordered_set<struct node*> container; // here inside  <>, there should be pointer as temp contains address
	
	struct node *temp = head;
	struct node *prev = NULL;
	while(temp!=NULL)
	{
		if(container.find(temp)!=container.end())
		{
			printf("Yes, Loop Exists....");
			prev->next = NULL; // REMOVING LOOP....
			return ;
		}
		container.insert(temp); // As temp is actually the address of the node
		prev = temp;
		temp = temp->next;
	}
	
	printf("No Loop..."); // If no loop Exists...
}

int main()
{
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
