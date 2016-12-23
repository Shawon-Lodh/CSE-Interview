#include <bits/stdc++.h>
using namespace std;

struct Stack
{
	unsigned capacity;
	int top;
	int *array;
};

struct Stack *createstack(unsigned capacity)
{
	struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
	if(!stack) // This if statement is required because when if malloc won't return pointer...then in that case....
	{
		return NULL;
	}
    stack->capacity = capacity;
	stack->top = -1;
	stack->array = (int*)malloc(stack->capacity * sizeof(int)); // This if statement is required because when if malloc won't return pointer...then in that case....
//	printf("%d %d %d %d", stack, &stack->capacity, &stack->top, &stack->array[0]);
	if(!stack->array)
	{
		return NULL;
	}
	
	return stack;
}

int isEmpty(struct Stack *stack)
{
	if(!stack->top)
	{
		printf("Stack is Empty");
		return 1; // signalling the stack is empty...
	}
	
	//printf("Stack is not Empty");
	return 0; // signalling the stack is not empty...
}

int isFull(struct Stack *stack)
{
	if(stack->top == (stack->capacity)-1)
	{
		printf("Stack is Full");
		return 1; // signalling the stack is full...
	}
	
//	printf("Stack is not Full");
	return 0; // signalling the stack is not full...
}

char peek(struct Stack *stack)
{
	if(isEmpty(stack))
	{
		printf("Empty stack...");
		return -1;
	}
	
//	printf("Top Element:  %d\n", stack->array[stack->top]);
	return stack->array[stack->top];
}

void push(struct Stack *stack, char data) // chat data because infixToPostfix program...so, char would be inserted
{
	if(isFull(stack))
	{
		printf("Stack Full..");
		return;
	}
	
	else
	{
		stack->array[++stack->top] = data;
		printf("The element inserted:  %c\n", stack->array[stack->top]);
	}
}

char pop(struct Stack *stack)
{
	if(isEmpty(stack))
	{
		printf("Stack empty...");
		return '$';
	}
	
	else
	{
		printf("element popped:  %c\n", stack->array[stack->top]);
		return (stack->array[stack->top--]);
	}
}

int isOperand(char ch)
{
	if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
	{
		return 1; // ch is operand...
	}
	
	else
	{
		return 0; // not operand...
	}
}

int prec(char ch)
{
	switch(ch)
	{
		case '+':
		case '-':
			return 1;
		
		case '*':
		case '/':
			return 2;
			
		case '^':
			return 3;
			
	}
	
	return -1;
}

void infixToPostfix(char *exp)
{
	int len = strlen(exp);
	struct Stack *stack = createstack(len);
	
	int i;
	int k = -1;
	for(i=0; exp[i]; i++)
	{
		
		if(isOperand(exp[i]))
		{
			exp[++k] = exp[i];
			//i++;
		}
		else if(exp[i] == '(')
		{
			push(stack, exp[i]);
		}
		else if(exp[i] == ')')
		{
			while(!isEmpty(stack) && peek(stack) != '(')
			{
				exp[++k] = pop(stack);
				if(isEmpty(stack) && peek(stack) != '(')
				{
					printf("Invalid Expression\n");
					return;
				}
					
			}
			pop(stack);
		}
		
		else // if exp[i] is an operator...
		{
			while(!isEmpty(stack) && prec(exp[i]) <= prec(peek(stack)))
			{
				exp[++k] = pop(stack);
			}
			push(stack, exp[i]);
		}
	}
	
	while(!isEmpty(stack))
	{
		exp[++k] = pop(stack);
	}
	
	exp[++k] = '\0';  // adding NULL or \0 to make itt string and print it...
	printf("\n\nPostFix:  %s", exp);
}

int main()
{
//	struct Stack* stack = createstack(10);
	char exp[] = "a+b*(c^d-e)^(f+g*h)-i";
    infixToPostfix(exp);
	return 0;
}
