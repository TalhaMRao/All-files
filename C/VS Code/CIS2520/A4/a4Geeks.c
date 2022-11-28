// IMPORTS
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define FILE_MAX 20
#define FILE_NAME "f.dat"

typedef struct Node // creating node
{
	int sum_key;
	int key[3];
	int content[7];
} node;

void printHeap(node *heap);

int main()
{
	node heap[FILE_MAX];

	FILE *fp = fopen(FILE_NAME, "r");

	for (int i = 0; i < FILE_MAX; i++)
	{
		node element;
		int sum_key = 0;
		for (int j = 0; j < 3; j++)
		{
			fscanf(fp, "%d", &element.key[j]);
			sum_key += element.key[j];
		}
		element.sum_key = sum_key;

		for (int j = 0; j < 7; j++)
		{
			fscanf(fp, "%d", &element.content[j]);
		}
		heap[i] = element;
	}

	printHeap(heap);
	fclose(fp);
	return 0;
}

void printHeap(node *heap)
{
	printf("nHeap = n\n");

	for (int i = 0; i < FILE_MAX; i++)
	{
		printf("\n");

		printf("%d\t", heap[i].sum_key);

		for (int j = 0; j < 3; j++)
			printf("%d ", heap[i].key[j]);
		for (int j = 0; j < 7; j++)
			printf("%d ", heap[i].content[j]);
	}
	printf("\n\n");
}