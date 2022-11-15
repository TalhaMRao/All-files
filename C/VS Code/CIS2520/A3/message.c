#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

char stack[100];
int top = -1;

typedef struct tree
{
    char x[15];
    struct tree *right;
    struct tree *left;
    struct tree *next;
} tree;

// Initializing Struct:
struct tree *head = NULL;

void push(char x);
char pop();
int priority(char x);
char *seperateString(char *String);
struct tree *newBranch(char x[15]);
struct tree *popTree();
void pushToTree(struct tree *tree);
void printTree(struct tree *tree);
void printPreorder(struct tree *tree);
void printPostorder(struct tree *tree);

int main(int argc, char *argv[])
{
    struct tree *L;
    struct tree *R;
    struct tree *new;
    char *e, x;
    e = argv[1];
    int length = 0;
    char *str2 = malloc(strlen(e) + 1);
    char tempString_One[15] = " ";
    char tempString_Two[15] = " ";
    char tempString_Three[15] = " ";

    while (*e != '\0')
    {
        if (isalpha(*e))
        {
            printf("%c", *e);
            str2[length] = *e;
            length++;
            e++;
            printf("%c ", *e);
            str2[length] = *e;
            length++;
        }
        else if (isdigit(*e))
        {
            printf("%c", *e);
            str2[length] = *e;
            length++;
            e++;
            printf("%c", *e);
            str2[length] = *e;
            length++;
            e++;
            printf("%c", *e);
            str2[length] = *e;
            length++;
            e++;
            printf("%c ", *e);
            str2[length] = *e;
            length++;
        }
        else if (*e == '(')
            push(*e);
        else if (*e == ')')
        {
            while ((x = pop()) != '(')
            {
                printf("%c ", x);
                str2[length] = x;
                length++;
            }
        }
        else
        {
            while (priority(stack[top]) >= priority(*e))
            {
                printf("%c ", pop());
                str2[length] = *e;
                length++;
            }
            push(*e);
        }
        e++;
    }
    while (top != -1)
    {
        x = pop();
        printf("%c ", x);
        str2[length] = x;
        length++;
    }

    str2[length] = '\0';

    printf("\n\n%s\n\n", str2);
    int i = 0;

    while (i < strlen(str2))
    {
        // If sign = character -> start a new string:
        if (str2[i] == '-' || str2[i] == '+' || str2[i] == '/' || str2[i] == '*')
        {
            tempString_One[0] = str2[i];
            tempString_One[1] = '\0';
            new = newBranch(tempString_One);

            R = popTree();
            L = popTree();

            new->left = L;
            new->right = R;

            pushToTree(new);
            i++;
        }
        // If its therefore a variable (x1,x2,x3) then get number in front of it and create new node:
        else if (str2[i] == 'x' || str2[i] == 'X')
        {
            tempString_Two[0] = str2[i];
            tempString_Two[1] = str2[i + 1];

            tempString_Two[2] = '\0';
            new = newBranch(tempString_Two);
            pushToTree(new);
            i += 2;
        }
        else if (isdigit(str2[i]) && str2[i + 1] == '.')
        {
            tempString_Three[0] = str2[i];
            tempString_Three[1] = str2[i + 1];
            tempString_Three[2] = str2[i + 2];
            tempString_Three[3] = str2[i + 3];

            tempString_Three[4] = '\0';

            new = newBranch(tempString_Three);
            pushToTree(new);

            i += 4;
        }
    }

    printf("PREORDER: ");
    printPreorder(new);
    printf("\n\n");

    printf("POSTORDER: ");
    printPostorder(new);
    printf("\n\n");

    free(str2);
    return 0;
}

// Creating Helper Fcn:
struct tree *newBranch(char x[15])
{
    // Creating space for tree:
    struct tree *tree = (struct tree *)malloc(sizeof(struct tree));

    // Defining node elements:
    strcpy(tree->x, x);
    tree->right = NULL;
    tree->left = NULL;
    tree->next = NULL;

    return (tree);
}

void pushToTree(struct tree *top)
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

tree *popTree()
{
    tree *test = head;
    head = head->next;
    return test;
}

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    if (top == -1)
        return -1;
    else
        return stack[top--];
}

int priority(char x)
{
    if (x == '(')
        return 0;
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    return 0;
}

void printTree(struct tree *tree)
{
    // checking if NULL then exiting if true (void cannot return anything):
    if (tree == NULL)
    {
        return;
    }
    else
    {
        // Going to the left branch (recursion #1):
        printTree(tree->left);

        // Printing Data of Node:
        printf("%s", tree->x);

        // Going to the right branch (recursion #2):
        printTree(tree->right);
    }
}

void printPreorder(struct tree *tree)
{
    // Checking to see if tree is NULL
    if (tree == NULL)
    {
        return;
    }

    // Print node data
    printf("%s ", tree->x);
    // Left branch recursion
    printPreorder(tree->left);
    // Right branch recursion
    printPreorder(tree->right);
}

void printPostorder(struct tree *tree)
{
    // Checking to see if tree is NULL
    if (tree == NULL)
    {
        return;
    }
    // Left branch recursion
    printPostorder(tree->left);
    // Right branch recursion
    printPostorder(tree->right);
    // Print node data
    printf("%s ", tree->x);
}