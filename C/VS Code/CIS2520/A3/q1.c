// C program for different tree traversals
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* A binary tree node has data, pointer to left child
and a pointer to right child */
struct node
{
	char data[4];
	struct node *left, *right;
};

void savingToBinaryTree(char dict1[40][40], int dict2[40], struct node *binaryTree, int totTerms);
struct node *newNode(char *data);
struct node *insertLeft(struct node *root, char *data);
struct node *insertRight(struct node *root, char *data);
int expressionSep(char *argv[], char dict1[40][40], int dict2[40]);
void findIndexes(int *openIndex, int *closeIndex, char *argv[]);
void printPreorder(struct node *node);
void printPostorder(struct node *node);

/* Driver code*/
int main(int argc, char *argv[])
{
	struct node *binaryTree = malloc(sizeof(*binaryTree));
	//  root->left = newNode(2);
	//  root->right = newNode(3);
	//  root->left->left = newNode(4);
	//  root->left->right = newNode(5);

	// // Function call
	// printf("\nPostorder traversal of binary tree is \n");
	// printPreorder(root);
	// printf("\n");
	// printPostorder(root);

	// getchar();
	// return 0;

	int openIndex[50] = {0};
	int closeIndex[50] = {0};
	int dict2[40] = {0};
	char dict1[40][40] = {""};
	int totTerms = expressionSep(argv, dict1, dict2);

	savingToBinaryTree(dict1, dict2, binaryTree, totTerms);

	findIndexes(openIndex, closeIndex, argv);

	printf("%s\t", binaryTree->data);
	printf("%s\t", binaryTree->left);
	printf("%s\t", binaryTree->right);

	return 0;
}

void savingToBinaryTree(char dict1[40][40], int dict2[40], struct node *binaryTree, int totTerms)
{
	// order for operand equals dict2 - 1;
	// order for terms is equal to dict2
	// push them into the binary tree based on these orders and you should have a binary tree that works

	// printf(sizeof(dict2) / sizeof(dict2[0]));

	for (int i = 0; i < 40; i++)
	{
		if (strlen(dict1[i]) == 0)
		{
			break;
		}
		else
		{
			for (int j = 0; j < strlen(dict1[i]); j++)
			{
			}
			printf("%d  ", dict2[i]);
			printf("%s\n", dict1[i]);
		}
	}

	for (int j = 0; j < totTerms; j++)
	{
		for (int i = 0; i < totTerms; i++)
		{
			if (dict2[i] == j)
			{
				for (int k = 0; k < 40; k++)
				{
					if (dict1[i][k] == '/')
					{
						binaryTree = newNode("/");
						printf("%s\n", binaryTree->data);
						break;
					}
					else if (dict1[i][k] == '*')
					{
						binaryTree = newNode("*");
						printf("%s\n", binaryTree->data);
						break;
					}
					else if (dict1[i][k] == '+')
					{
						binaryTree = newNode("+");
						printf("%s\n", binaryTree->data);
						break;
					}
					else if (dict1[i][k] == '-')
					{
						binaryTree = newNode("-");
						printf("%s\n", binaryTree->data);
						break;
					}
				}
				// newNode();
			}
		}
	}
}

/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
struct node *newNode(char *data)
{
	struct node *node = (struct node *)malloc(sizeof(struct node));
	strcpy(node->data, data);
	node->left = node->right = NULL;

	return (node);
}
// Insert on the left of the node
struct node *insertLeft(struct node *root, char *data)
{
	root->left = newNode(data);
	return root->left;
}
// Insert on the right of the node
struct node *insertRight(struct node *root, char *data)
{
	root->right = newNode(data);
	return root->right;
}

int expressionSep(char *argv[], char dict1[40][40], int dict2[40])
{
	// Gets the order of each operator; allows us to know their presendeance
	int n = 0;
	// Counts number of expressions present
	int terms = 0;

	char temp[100];
	strcpy(temp, argv[1]);

	int counter = 1;

	char *token;

	for (int i = 0; i < strlen(argv[1]) - 1; i++)
	{
		if (argv[1][i] == '(')
		{
			n++;
		}
		else if (argv[1][i] == ')')
		{
			n--;
		}
		else
		{
			if (counter == 1)
			{
				token = strtok(temp, "()");
				strcpy(dict1[terms], token);
			}
			else
			{
				token = strtok(NULL, "()");
				strcpy(dict1[terms], token);
			}

			dict2[terms] = n;

			i += strlen(token) - 1;
			counter++;
			terms++;
		}
	}
	return terms;
}

void findIndexes(int *openIndex, int *closeIndex, char *argv[])
{
	int j = 0;
	int k = 0;

	for (int i = 0; i < strlen(argv[1]); i++)
	{
		if (argv[1][i] == '(')
		{
			openIndex[j] = i;
			j++;
		}
		else if (argv[1][i] == ')')
		{
			closeIndex[k] = i;
			k++;
		}
	}
}

/* Given a binary tree, print its nodes in preorder*/
void printPreorder(struct node *node)
{
	if (node == NULL)
		return;

	/* first print data of node */
	printf("%d ", node->data);

	/* then recur on left subtree */
	printPreorder(node->left);

	/* now recur on right subtree */
	printPreorder(node->right);
}

/* Given a binary tree, print its nodes according to the
"bottom-up" postorder traversal. */
void printPostorder(struct node *node)
{
	if (node == NULL)
		return;

	// first recur on left subtree
	printPostorder(node->left);

	// then recur on right subtree
	printPostorder(node->right);

	// now deal with the node
	printf("%d ", node->data);
}
