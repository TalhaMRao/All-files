// Name : Talha Rao
// ID: 1088904
// Assignment 4

//

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

typedef struct heaping
{
	node *nodes;
	int capacity;
	int size;
} minHeap;

int readFile(node *heap);

minHeap *heapBuilder(int capacity)
{
	minHeap *heap = malloc(sizeof(minHeap));
	heap->nodes = (node *)malloc(capacity * sizeof(node));
	heap->capacity = capacity;
	heap->size = 0;
	return heap;
}

int isFull(minHeap *heap)
{
	return heap->size == heap->capacity;
}

int isEmpty(minHeap *heap)
{
	return heap->size == 0;
}

void insert(minHeap *heap, node element)
{
	if (isFull(heap))
		return;

	heap->nodes[heap->size] = element;

	int current = heap->size;

	while (current != 0 && heap->nodes[current].sum_key > heap->nodes[(current - 1) / 2].sum_key)
	{
		node temp = heap->nodes[(current - 1) / 2];
		heap->nodes[(current - 1) / 2] = heap->nodes[current];
		heap->nodes[current] = temp;

		current = (current - 1) / 2;
	}
	heap->size++;
}

node deleteMin(minHeap *heap)
{
	node element = heap->nodes[0];
	heap->nodes[0] = heap->nodes[heap->size - 1];
	heap->size--;

	int current = 0;
	int leftChild = 1;
	int rightChild = 2;

	while (rightChild < heap->size)
	{
		if (heap->nodes[current].sum_key >= heap->nodes[leftChild].sum_key && heap->nodes[current].sum_key >= heap->nodes[rightChild].sum_key)
			break;

		if (heap->nodes[leftChild].sum_key > heap->nodes[rightChild].sum_key)
		{
			node temp = heap->nodes[current];
			heap->nodes[current] = heap->nodes[leftChild];
			heap->nodes[leftChild] = temp;
		}
		else
		{
			node temp = heap->nodes[current];
			heap->nodes[current] = heap->nodes[rightChild];
			heap->nodes[rightChild] = temp;

			current = rightChild;
			leftChild = 2 * current + 1;
			rightChild = 2 * current + 2;
		}
	}

	if (leftChild == heap->size && heap->nodes[current].sum_key < heap->nodes[leftChild].sum_key)
	{
		node temp = heap->nodes[current];
		heap->nodes[current] = heap->nodes[leftChild];
		heap->nodes[leftChild] = temp;
	}

	return element;
}

void printHeap(minHeap *heap)
{
	printf("nHeap = n\n\n");

	for (int i = 0; i < heap->size; i++)
	{
		printf("\n");

		printf("%d\t", heap->nodes[i].sum_key);

		for (int j = 0; j < 3; j++)
			printf("%d,", heap->nodes[i].key[j]);
		for (int j = 0; j < 7; j++)
			printf("%d,", heap->nodes[i].content[j]);
	}
	printf("n");
}

int main()
{
	int capacity = 20;
	minHeap *heap = heapBuilder(capacity);

	FILE *fp = fopen("f.dat", "r");

	for (int i = 0; i < 20; i++)
	{
		node element;
		int sum_key = 0;
		for (int j = 0; j < 3; j++)
		{
			fscanf(fp, "%d", &element.sum_key);
			element.key[j] = element.sum_key;
			sum_key += element.sum_key;
		}

		element.sum_key = sum_key;

		for (int j = 0; j < 7; j++)
		{
			fscanf(fp, "%d", &element.content[j]);
		}
		insert(heap, element);
	}

	printHeap(heap);
	fclose(fp);
	return 0;
}

int readFile(node *heap)
{
	FILE *file = fopen(FILE_NAME, "r");
	if (!file)
	{
		perror("Error opening file");
		return -1;
	}
}