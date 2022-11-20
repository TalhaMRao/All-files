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

typedef struct MinHeap
{
    int *arr;
    // Current Size of the Heap
    int size;
    // Maximum capacity of the heap
    int capacity;
} MinHeap;

MinHeap *init_minheap(int capacity);
void free_minheap(MinHeap *heap);
int parent(int i);
int left_child(int i);
int right_child(int i);
int get_min(MinHeap *heap);

int main()
{

    return 0;
}

MinHeap *init_minheap(int capacity)
{
    MinHeap *minheap = (MinHeap *)calloc(1, sizeof(MinHeap));
    minheap->arr = (int *)calloc(capacity, sizeof(int));
    minheap->capacity = capacity;
    minheap->size = 0;
    return minheap;
}

void free_minheap(MinHeap *heap)
{
    if (!heap)
        return;
    free(heap->arr);
    free(heap);
}

int parent(int i)
{
    // Get the index of the parent
    return (i - 1) / 2;
}

int left_child(int i)
{
    return (2 * i + 1);
}

int right_child(int i)
{
    return (2 * i + 2);
}

int get_min(MinHeap *heap)
{
    // Return the root node element,
    // since that's the minimum, by the min-heap
    // property
    return heap->arr[0];
}
