#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

struct node
{
	char data[4];
	struct node *left;
	struct node *right;
	struct node *next;
};

struct node *head = NULL;

char stack[100];
int top = -1;

void cPush(char x);
char cPop();
int cPriority(char x);

int main(int argc, char *argv[])
{
	char exp[100];
	char *e, x;
	e = argv[1];

	// printf("Enter the expression : ");
	// scanf("%s", exp);
	// printf("\n");
	// e = exp;

	// char *str = "";
	// size_t len = strlen(str);
	char *str2 = malloc(strlen(argv[1]) + 1);
	// strcpy(str2, str);
	int len = 0;
	while (*e != '\0')
	{
		if (isalpha(*e))
		{
			printf("%c", *e);
			str2[len] = *e;
			e++;
			len++;

			printf("%c ", *e);
			str2[len] = *e;
			len++;
		}
		else if (isdigit(*e))
		{
			printf("%c", *e);
			str2[len] = *e;
			e++;
			len++;

			printf("%c", *e);
			str2[len] = *e;
			e++;
			len++;

			printf("%c", *e);
			str2[len] = *e;
			e++;
			len++;

			printf("%c ", *e);
			str2[len] = *e;
			len++;
		}
		else if (*e == '(')
			cPush(*e);
		else if (*e == ')')
		{
			while ((x = cPop()) != '(')
			{
				printf("%c ", x);
				str2[len] = x;
				len++;
			}
		}
		else
		{
			while (cPriority(stack[top]) >= cPriority(*e))
			{
				printf("%c ", x);
				str2[len] = x;
				len++;
			}
			cPush(*e);
		}
		e++;
	}
	while (top != -1)
	{
		x = cPop();
		printf("%c ", x);
		str2[len] = x;
		len++;
	}

	str2[len] = '\0';

	printf("\n\n%s\n\n", str2);

	free(str2);
	return 0;
}

struct node *newNode(char *data)
{
	struct node *node = (struct node *)malloc(sizeof(struct node));
	strcpy(node->data, data);
	node->left = NULL;
	node->right = NULL;
	node->next = NULL;

	return (node);
}

void cPush(char x)
{
	stack[++top] = x;
}

char cPop()
{
	if (top == -1)
		return -1;
	else
		return stack[top--];
}

int cPriority(char x)
{
	if (x == '(')
		return 0;
	if (x == '+' || x == '-')
		return 1;
	if (x == '*' || x == '/')
		return 2;
	return 0;
}