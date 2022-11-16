// Name : Talha Rao
// ID: 1088904
// Assignment 3

// This program takes in an arithematic  expression
// for example ./q1 "(((x1+5.12)*(x2-7.28))/x3)"
// The output of the program the strings in preorder and postorder depending on what the user decided
// for example POSTORDER: x1 5.12 + x2 7.28 - * x3 /

// IMPORTS
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef struct node // creating node
{
	char data[15];
	struct node *right;
	struct node *left;
	struct node *next;
} node;

// Initialize global stack
char stack[100];
int top = -1;

// Initializing Struct:
struct node *head = NULL;

// Function declarations
struct node *newBranch(char data[15]);
void sPushToNode(struct node *node);
struct node *sPopNode();
void cPush(char data);
char cPop();
int cPrio(char data);
void printNode(struct node *node);
void printPreorder(struct node *node);
void printPostorder(struct node *node);

int main(int argc, char *argv[])
{
	struct node *root, *right, *left;
	char *inputStringPointer = argv[1], temp, *stringBuilder = malloc(strlen(inputStringPointer) + 1);
	int len = 0;

	while (*inputStringPointer != '\0') // Changes the infix input to postorder
	{
		if (isdigit(*inputStringPointer))
		{
			stringBuilder[len] = *inputStringPointer;
			len++;
			inputStringPointer++;
			stringBuilder[len] = *inputStringPointer;
			len++;
			inputStringPointer++;
			stringBuilder[len] = *inputStringPointer;
			len++;
			inputStringPointer++;
			stringBuilder[len] = *inputStringPointer;
			len++;
		}
		else if (isalpha(*inputStringPointer))
		{
			stringBuilder[len] = *inputStringPointer;
			len++;
			inputStringPointer++;
			stringBuilder[len] = *inputStringPointer;
			len++;
		}
		else if (*inputStringPointer == '(')
			cPush(*inputStringPointer);
		else if (*inputStringPointer == ')')
		{
			while ((temp = cPop()) != '(')
			{
				stringBuilder[len] = temp;
				len++;
			}
		}
		else
		{
			while (cPrio(stack[top]) >= cPrio(*inputStringPointer))
			{
				stringBuilder[len] = *inputStringPointer;
				len++;
			}
			cPush(*inputStringPointer);
		}
		inputStringPointer++;
	}
	while (top != -1)
	{
		stringBuilder[len] = cPop();
		len++;
	}

	stringBuilder[len] = '\0';

	int i = 0;

	char a[15] = " ", b[15] = " ", c[15] = " ";

	while (i < strlen(stringBuilder))
	{
		// If sign = character -> start a root string:
		if (stringBuilder[i] == '-' || stringBuilder[i] == '+' || stringBuilder[i] == '/' || stringBuilder[i] == '*')
		{
			a[0] = stringBuilder[i];
			a[1] = '\0';
			root = newBranch(a);
			right = sPopNode();
			left = sPopNode();
			root->left = left;
			root->right = right;
			sPushToNode(root);
			i++;
		}
		// If its therefore a variable (x1,x2,x3) then get number in front of it and create root node:
		else if (stringBuilder[i] == 'x')
		{
			b[0] = stringBuilder[i];
			b[1] = stringBuilder[i + 1];
			b[2] = '\0';
			root = newBranch(b);
			sPushToNode(root);
			i += 2;
		}
		else if (isdigit(stringBuilder[i]) && stringBuilder[i + 1] == '.')
		{
			c[0] = stringBuilder[i];
			c[1] = stringBuilder[i + 1];
			c[2] = stringBuilder[i + 2];
			c[3] = stringBuilder[i + 3];
			c[4] = '\0';
			root = newBranch(c);
			sPushToNode(root);
			i += 4;
		}
	}
	int selection = 1;

	while (selection)
	{
		printf("In what form would you like to see your expression.\n");
		printf("1 - Preorder.\n");
		printf("2 - Postorder. \n");
		printf("0 - Exit. \n");

		scanf("%d", &selection);
		if (selection == 1)
		{
			printf("PREORDER: ");
			printPreorder(root);
			printf("\n");
		}
		else if (selection == 2)
		{
			printf("POSTORDER: ");
			printPostorder(root);
			printf("\n");
		}
		else
			printf("POSTORDER: ");
	}
	free(stringBuilder);
	return 0;
}

// Creating Helper Fcn:
struct node *newBranch(char data[15])
{
	// Creating space for node:
	struct node *node = (struct node *)malloc(sizeof(struct node));

	// Defining node elements:
	strcpy(node->data, data);
	node->right = NULL;
	node->left = NULL;
	node->next = NULL;

	return (node);
}

void sPushToNode(struct node *top)
{
	// setting current node pushed as head if empty:
	if (head == NULL)
	{
		head = top;
	}
	else
	{
		(top)->next = head;
		head = top;
	}
}

node *sPopNode()
{
	node *test = head;
	head = head->next;
	return test;
}

void cPush(char data)
{
	stack[++top] = data;
}

char cPop()
{
	if (top == -1)
		return -1;
	else
		return stack[top--];
}

int cPrio(char data)
{
	if (data == '(')
		return 0;
	if (data == '+' || data == '-')
		return 1;
	if (data == '*' || data == '/')
		return 2;
	return 0;
}

void printNode(struct node *node)
{
	// checking if NULL then exiting if true (void cannot return anything):
	if (node == NULL)
	{
		return;
	}
	else
	{
		// Going to the left branch (recursion #1):
		printNode(node->left);

		// Printing Data of Node:
		printf("%s", node->data);

		// Going to the right branch (recursion #2):
		printNode(node->right);
	}
}

void printPreorder(struct node *node)
{
	// Checking to see if node is NULL
	if (node == NULL)
	{
		return;
	}

	// Print node data
	printf("%s ", node->data);
	// Left branch recursion
	printPreorder(node->left);
	// Right branch recursion
	printPreorder(node->right);
}

void printPostorder(struct node *node)
{
	// Checking to see if node is NULL
	if (node == NULL)
	{
		return;
	}
	// Left branch recursion
	printPostorder(node->left);
	// Right branch recursion
	printPostorder(node->right);
	// Print node data
	printf("%s ", node->data);
}