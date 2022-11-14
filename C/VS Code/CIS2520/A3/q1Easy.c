#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max 100
int push(char stack[max][80], int *top, char data[80])
{
	if (*top == max - 1)
		return (-1);
	else
	{
		*top = *top + 1;
		strcpy(stack[*top], data);
		return (1);
	}
}
int pop(char stack[max][80], int *top, char data[80])
{
	if (*top == -1)
		return (-1);
	else
	{
		strcpy(data, stack[*top]);
		*top = *top - 1;
		return (1);
	}
}
int main(int argc, char *argv[])
{
	char stack[max][80], nm[80];
	int top, reply;
	top = -1; // Initialize Stack

	for (int i = 1; i < argc - 1; i++)
	{
		if (strlen(argv[i]) > 1)
		{
			reply = push(stack, &top, argv[i]);
		}
		else
		{
			if (strlen(argv[i + 1]) > 1)
			{
				reply = pop(stack, &top, nm);

				printf("(%s ", nm);
				printf("%s ", argv[i]);
				reply = pop(stack, &top, nm);
				printf("%s) ", nm);
			}
			else
			{
				reply = pop(stack, &top, nm);
				printf("(%s ", nm);
				printf("%s ", argv[i]);
				reply = pop(stack, &top, nm);
				printf("%s) ", nm);
				printf("%s ", argv[i + 1]);
				reply = pop(stack, &top, nm);
			}
		}
	}
	return 0;
}