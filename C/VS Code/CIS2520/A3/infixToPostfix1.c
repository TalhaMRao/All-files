#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

struct node
{
	char data[10];
	struct node *left;
	struct node *right;
	struct node *next;
};

struct node *head = NULL;

char stack[100];
int top = -1;

int cPriority(char x);
void cPush(char x);
char cPop();

int main(int argc, char *argv[])
{
	struct node *left;
	struct node *right;
	struct node *root;

	char *e, x;
	e = argv[1];

	char *str2 = malloc(strlen(argv[1]) + 1);
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

	char a[10] = " ";
	char b[10] = " ";
	char c[10] = " ";

	for (int i = 0; i < strlen(str2); i++)
	{
		if (str2[i] == '-' || str2 == '+' || str2[i] == '/' || str2[i] == '*')
		{
			a[0] = str2[i];
			a[1] = '\0';
			root = newNode(a);
		}
		else if (str2[i] == 'x' || str2[i] == 'X')
		{
			b[0] = str2[i];
			b[1] = str2[i + 1];
			b[2] = '\0';
			root = newBranch(b);
			pushToTree(root);
			i++;
		}
		else
		{
			c[0] = str2[i];
			c[1] = str2[i + 1];
			c[2] = str2[i + 2];
			c[3] = str2[i + 3];
			c[4] = '\0';
			root = newBranch(c);

			i += 4;
		}
	}

	free(str2);
	return 0;
}

struct node *newBranch(char x[15])
{
	// Creating space for tree:
	struct node *tree = (struct node *)malloc(sizeof(struct node));

	// Defining node elements:
	strcpy(node->data, data);
	tree->right = NULL;
	tree->left = NULL;
	tree->next = NULL;

	return (tree);
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