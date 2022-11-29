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

void heapSort(node heap[]);
void heapify(node heap[], int x, int y);
void swap(node *x, node *y);
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
	fclose(fp);

	heapSort(heap);
	printHeap(heap);

	return 0;
}

void heapSort(node heap[])
{
	for (int i = FILE_MAX; i >= 0; i--)
		heapify(heap, i, FILE_MAX);
	// for (int i = FILE_MAX - 1; i >= 0; i--)
	// {
	// 	swap(&heap[0], &heap[i]);
	// 	heapify(heap, 0, i);
	// }
	// for (int i = FILE_MAX / 2 - 1; i >= 0; i--)
	// 	heapify(heap, i, FILE_MAX);
	// for (int i = FILE_MAX - 1; i >= 0; i--)
	// {
	// 	swap(&heap[0], &heap[i]);
	// 	heapify(heap, 0, i);
	// }
}

void heapify(node heap[], int i, int x)
{
	int smallest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if ((heap[left].sum_key < heap[smallest].sum_key) && (left < x))
		smallest = left;

	if ((heap[right].sum_key < heap[smallest].sum_key) && (right < x))
		smallest = right;

	if (smallest != i)
	{
		swap(&heap[i], &heap[smallest]);
		heapify(heap, smallest, x);
	}
}

void swap(node *x, node *y)
{
	node temp = *x;
	*x = *y;
	*y = temp;
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