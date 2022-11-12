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

	double x = 0;
	double y = 0;

	double tally = 0;

	//checks each element in the array
	for (int i = 0; i < strlen(argv[1]); i++)
	{
		if (argv[1][i] - 48 >= 0 && argv[1][i] - 48 <= 9)// pushes normal numbers to the stack
		{
			push(stack, argv[1][i] - 48);
		}
		else if (argv[1][i] - 45 == 0) // pops numbers and performs the subtract function
		{
			y = pop(stack);
			x = pop(stack);

			tally = x - y;

			push(stack, tally);
		}
		else if (argv[1][i] - 42 == 0) // pops numbers and performs the multiply function
		{
			y = pop(stack);
			x = pop(stack);

			tally = x * y;

			push(stack, tally);
		}
		else if (argv[1][i] - 47 == 0) // pops numbers and performs the divide function
		{
			y = pop(stack);
			x = pop(stack);

			tally = x / y;

			push(stack, tally);
		}
		else // pops numbers and performs the addition function
		{
			y = pop(stack);
			x = pop(stack);

			tally = x + y;

			push(stack, tally);
		}
	}

	// push(stack, 10);
	// push(stack, 20);
	// push(stack, 30);

	printf("The final number is %.02lf\n", pop(stack)); // prints information

	return 0;
}
