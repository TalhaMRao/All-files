// IMPORTS /////////////////////////////////////////////////////
#include <stdlib.h>
#include <stdio.h>

// Global Variables ////////////////////////////////////////////
#define FILE_MAX 20		  // size of file
#define FILE_NAME "f.dat" // file name

// Defining structs ////////////////////////////////////////////
typedef struct Node
{
	int sum_key;
	int key[3];
	int content[7];
} node;

// Function declarations (4 functions) /////////////////////////
void heapify(node heap[], int x, int y);
void swap(node *x, node *y);
void fileRead(node heap[]);
void printHeap(node *heap);

// Main method /////////////////////////////////////////////////
int main()
{
	node heap[FILE_MAX]; // creating a heap of size 20

	fileRead(heap); // calls the file reader function

	for (int i = FILE_MAX; i >= 0; i--) // Iterates through the heap array backwards
		heapify(heap, i, FILE_MAX);		// Calls the heapify function and sorts the heap based on the heapify algorithm line by line
	printHeap(heap);					// Prints the sorted heap

	return 0;
}
/* This function recieves the heap that needs to be sorted, the index of the current key and the max size that needs to be sorted
 * It sorts the heap based on the heapify sorting algorithm
 * It dosent return anything but instead modifies the heap array sent to it
 */
void heapify(node heap[], int i, int x)
{
	int smallest = i;	   // saves the index i to the smallest variable
	int left = 2 * i + 1;  // saves left and right based on the formula
	int right = 2 * i + 2; // saves right

	if ((heap[left].sum_key < heap[smallest].sum_key) && (left < x)) // if the left number is less then the smallest and left is less than the new largest index
		smallest = left;											 // left is the new smallest

	if ((heap[right].sum_key < heap[smallest].sum_key) && (right < x)) // if the right  number is less then the smallest and right is less than the new largest index
		smallest = right;											   // right is the new smallest

	if (smallest != i) // if not at the end of the heap
	{
		swap(&heap[i], &heap[smallest]); // swap the smallest and current i
		heapify(heap, smallest, x);		 // recursively call this alorithm to do the process again until the entire loop is sorted
	}
}
/* It recieves 2 node pointers that need to be swapped
 * It simply swaps the position of the nodes
 * It dosent return anything
 */
void swap(node *x, node *y)
{
	node temp = *x; // temp to hold x address
	*x = *y;		// swap y address to x
	*y = temp;		// swap x address to y
}
/* It recieves the entire empty heap that need to be filled
 * It simply reads the .dat file and saves the input into the heap
 * It dosent return anything but modifies the heap sent so that it is filled now
 */
void fileRead(node heap[])
{
	FILE *fp = fopen(FILE_NAME, "r"); // opening file

	for (int i = 0; i < FILE_MAX; i++) // loop iterates through the length of the file (hard coded)
	{
		node element;				// temporary element
		int sum_key = 0;			// temp sum
		for (int j = 0; j < 3; j++) // for loop to count the first 3 digits and save them in the key
		{
			fscanf(fp, "%d", &element.key[j]); // reads the integer seperated by a space and saves it to the key with index j
			sum_key += element.key[j];		   // saves the sum into temp sum key
		}
		element.sum_key = sum_key; // save the sum into the permamenent sum key

		for (int j = 0; j < 7; j++) // for loop to count the last 7 digits and save them in the key
		{
			fscanf(fp, "%d", &element.content[j]); // reads the integer seperated by a space and saves it to the content with index j
		}
		heap[i] = element; // saves the temp element into the actual unsorted heap
	}
	fclose(fp); // close file
}
/* It recieves the entire heap that need to be printed
 * It simply prints the entire heap
 * It dosent return anything
 */
void printHeap(node *heap)
{
	for (int i = 0; i < FILE_MAX; i++) // iterates for the entire length of the heap
	{
		printf("\n"); // adds new line after each line

		for (int j = 0; j < 3; j++)
			printf("%d ", heap[i].key[j]); // prints the first 3 key
		for (int j = 0; j < 7; j++)
			printf("%d ", heap[i].content[j]); // prints the last 7 digits
	}
	printf("\n\n"); // adds 2 newlines at the end to loop pretty
}