// Name : Talha Rao
// ID: 1088904
// Assignment 2

// to run this program you will need to put rpn in the command line when you try to run it.
// for example ./q2 12+53-*
// The output of the program will be a char number with 2 decimal points
// for example

// C program for array implementation of stack and using it to perform simples arthemetic
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A structure to represent a stack
struct Stack
{
	char *top;
	unsigned capacity;
	char *array;
};

// function to create a stack of given capacity. It initializes size of
// stack as 0
struct Stack *createStack(unsigned capacity)
{
	struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
	stack->capacity = capacity;
	stack->top = "-1";
	stack->array = (char *)malloc(stack->capacity * sizeof(char));
	return stack;
}

// Stack is full when top is equal to the last index
char isFull(struct Stack *stack)
{
	return stack->top == stack->capacity - 1;
}

// Stack is empty when top is equal to -1
char isEmpty(struct Stack *stack)
{
	return stack->top == -1;
}

// Function to add an item to stack. It increases top by 1
void push(struct Stack *stack, char *item)
{
	if (isFull(stack))
		return;
	strcpy(item, stack->array[++stack->top]);
	printf("%c pushed to stack\n", item);
}

// Function to remove an item from stack. It decreases top by 1
char *pop(struct Stack *stack)
{
	if (isEmpty(stack))
		return "";
	return stack->array[stack->top--];
}

// Function to return the top from stack without removing it
int peek(struct Stack *stack)
{
	if (isEmpty(stack))
		return INT_MIN;
	return stack->array[stack->top];
}

// Driver program to test above functions
int main(int argc, char *argv[])
{
	struct Stack *stack = createStack(100);
	char v;
	char w;
	char x;
	char y;
	char z[strlen(argv[1])];
	char z[0] = '\n';
	int zC = 0;

	for (int i = 1; i < argc; i++)
	{
		if (sizeof(argv[i] > 1))
			push(stack, argv[i]);
		else
		{
			printf(pop(stack));
			z[zC] = v;
			zC++;
			if (v - 48 >= 0 && v - 48 <= 9)
			{
				w = pop(stack);
				x = pop(stack);
				y = pop(stack);
				z[zC] = w;
				zC++;
				z[zC] = x;
				zC++;
				z[zC] = y;
				zC++;
			}
			else
			{
				w = pop(stack);
				z[zC] = w;
				zC++;
			}

			if (argv[1][i] - 47 == 0) // pops numbers and performs the divide function
			{
				z[zC] = '/';
				zC++;
			}
			else if (argv[1][i] - 42 == 0) // pops numbers and performs the multiply function
			{
				z[zC] = '*';
				zC++;
			}
			else if (argv[1][i] - 45 == 0) // pops numbers and performs the subtract function
			{
				z[zC] = '-';
				zC++;
			}
			else // pops numbers and performs the addition function
			{
				z[zC] = '+';
				zC++;
			}

			v = pop(stack);
			z[zC] = v;
			zC++;
			if (v - 48 >= 0 && v - 48 <= 9)
			{
				w = pop(stack);
				x = pop(stack);
				y = pop(stack);
				z[zC] = w;
				zC++;
				z[zC] = x;
				zC++;
				z[zC] = y;
				zC++;
			}
			else
			{
				w = pop(stack);
				z[zC] = w;
				zC++;
			}
		}
	}
	z[strlen(argv[1])] = '\0';

	printf("The final number is %s\n", z); // prints information

	return 0;
}

// if (argv[1][i] - 48 >= 0 && argv[1][i] - 48 <= 9) // pushes normal numbers to the stack
// {
// 	push(stack, argv[1][i] - 48);
// }
// else if (argv[1][i] - 45 == 0) // pops numbers and performs the subtract function
// {
// 	y = pop(stack);
// 	x = pop(stack);

// 	tally = x - y;

// 	push(stack, tally);
// }
// else if (argv[1][i] - 42 == 0) // pops numbers and performs the multiply function
// {
// 	y = pop(stack);
// 	x = pop(stack);

// 	tally = x * y;

// 	push(stack, tally);
// }
// else if (argv[1][i] - 47 == 0) // pops numbers and performs the divide function
// {
// 	y = pop(stack);
// 	x = pop(stack);

// 	tally = x / y;

// 	push(stack, tally);
// }
// else // pops numbers and performs the addition function
// {
// 	y = pop(stack);
// 	x = pop(stack);

// 	tally = x + y;

// 	push(stack, tally);
// }