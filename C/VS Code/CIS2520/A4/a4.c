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

#define FILE_MAX 20
#define FILE_NAME "f.dat"

// typedef struct node // creating node
// {
//     char data[15];
//     struct node *right;
//     struct node *left;
//     struct node *next;
// } node;
typedef struct node // creating node
{
    int sum_key;
    int key[3];
    int content[7];

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

    free(stringBuilder);
    return 0;
}

void readingFromFile()
{
    FILE *fp;
    fp_fopen(FILE_NAME, "r");
    if (!fp)
    {
        perror("Error opening file");
    }
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