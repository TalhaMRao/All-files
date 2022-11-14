// Name : Talha Rao
// ID: 1088904
// Assignment 2

// to run this program you will need to put rpn in the command line when you try to run it.
// for example ./q2 12+53-*
// The output of the program will be a double number with 2 decimal points
// for example

// C program for array implementation of stack and using it to perform simples arthemetic
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A structure to represent a stack
struct Stack
{
	int top;
	unsigned capacity;
	double *array;
};

// function to create a stack of given capacity. It initializes size of
// stack as 0
struct Stack *createStack(unsigned capacity)
{
	struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
	stack->capacity = capacity;
	stack->top = -1;
	stack->array = (double *)malloc(stack->capacity * sizeof(double));
	return stack;
}

// Stack is full when top is equal to the last index
double isFull(struct Stack *stack)
{
	return stack->top == stack->capacity - 1;
}

// Stack is empty when top is equal to -1
double isEmpty(struct Stack *stack)
{
	return stack->top == -1;
}

// Function to add an item to stack. It increases top by 1
void push(struct Stack *stack, double item)
{
	if (isFull(stack))
		return;
	stack->array[++stack->top] = item;
	// printf("%d pushed to stack\n", item);
}

// Function to remove an item from stack. It decreases top by 1
double pop(struct Stack *stack)
{
	if (isEmpty(stack))
		return INT_MIN;
	return stack->array[stack->top--];
}

// Function to return the top from stack without removing it
double peek(struct Stack *stack)
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

	int zC = 0;
	// checks each element in the array
	for (int i = 0; i < strlen(argv[1]); i++)
	{
		if (argv[1][i] - 48 >= 0 && argv[1][i] - 48 <= 9)
		{
			push(stack, argv[1][i] - 48);
			push(stack, argv[1][i + 1] - 48);
			push(stack, argv[1][i + 2] - 48);
			push(stack, argv[1][i + 3] - 48);
			i += 4;
		}
		else if (argv[1][i] == 'x')
		{
			push(stack, argv[1][i] - 48);
			push(stack, argv[1][i + 1] - 48);
			i += 2;
		}
		else
		{
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
			if (argv[1][i] - 47 == 0) // pops numbers and performs the divide function
			{
			}
			else if (argv[1][i] - 42 == 0) // pops numbers and performs the multiply function
			{
			}
			else if (argv[1][i] - 45 == 0) // pops numbers and performs the subtract function
			{
			}
			else // pops numbers and performs the addition function
			{
			}
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
	}

	z[strlen(argv[1])] = '\0';

	printf("The final number is %s\n", z); // prints information

	return 0;
}