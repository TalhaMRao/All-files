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
		if (heap->nodes[current].key >= heap->nodes[leftChild].key && heap->nodes[current].key >= heap->nodes[rightChild].key)
			break;

		if (heap->nodes[leftChild].key > heap->nodes[rightChild].key)
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

	if (leftChild == heap->size && heap->nodes[current].key < heap->nodes[leftChild].key)
	{
		node temp = heap->nodes[current];
		heap->nodes[current] = heap->nodes[leftChild];
		heap->nodes[leftChild] = temp;
	}
}

int main()
{
	node heap[20];
	int error;
	error = readFile(heap);
	if (error)
	{
		perror("Error opening file");
		return -1;
	}

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