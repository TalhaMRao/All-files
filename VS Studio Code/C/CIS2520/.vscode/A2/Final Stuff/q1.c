#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct AvailableNode
{
	char licensePlate[10];
	int mileage;
	int date;

	struct AvailableNode *next;
} AvailableC;
typedef struct RentedNode
{
	char licensePlate[10];
	int mileage;
	int date;
	struct RentedNode *next;
} RentedC;
typedef struct AtWkshopNode
{
	char licensePlate[10];
	int mileage;
	int date;
	struct AtWkshopNode *next;
} AtWkshopC;

void createAvailableNode();
void rentedCarReturn(RentedC *Rented, char licensePlate[]);
void deleteReturnedList(RentedC **Rented, RentedC *node);
void addNodeToAtWkshopList(AtWkshopC **AtWkshop, AtWkshopC *node);
void readFromFile(char *fileName, AvailableC *Available);
void writeToFile(char *fileName);
void addNodeToAvailableList(AvailableC **Available, AvailableC *node);

int main()
{
	AvailableC *Available = NULL;
	RentedC *Rented = NULL;
	AtWkshopC *AtWkshop = NULL;
	AvailableC *d;
	RentedC *c;
	AtWkshopC *e;
	int user = 0;
	char b[10];

	while (user != 7)
	{
		printf("1-Add a new car to the available-for-rent list.\n2-Add a returned car to the available-for-rent list.\n3-Add a returned car to the repair list.\n4-Transfer a car from the repair list to the available-for-rent list.\n5-Rent the first available car.\n6-Print all the lists.\n7-Quit.\nChoose a menu option: \n");
		scanf("%d", &user);
		printf("\n\n");
		if (user == 1)
		{
			createAvailableNode();
			addNodeToAvailableList(&Available, d);
		}
		else if (user == 2)
		{
			printf("Enter the car's license licensePlate:");
			scanf("%s", b);
			rentedCarReturn(Rented, b);
			if (c != NULL)
			{
				strcpy(d->licensePlate, c->licensePlate);
				d->mileage = c->mileage;
				d->date = c->date;
				addNodeToAvailableList(&Available, d);
				deleteReturnedList(&Rented, c);
			}
		}
		else if (user == 3)
		{
			printf("Enter the car's license licensePlate:");
			scanf("%s", b);
			rentedCarReturn(Rented, b);
			if (c != NULL)
			{
				strcpy(e->licensePlate, c->licensePlate);
				e->mileage = c->mileage;
				e->date = c->date;
				addNodeToAtWkshopList(&AtWkshop, e);
				deleteReturnedList(&Rented, c);
			}
		}
	}
	AvailableC *x;
	return 0;
}
void readFromFile(char *fileName, AvailableC *Available)
{
	int i = 0;
	FILE *fp = fopen(fileName, "r");
	while (!feof(fp))
	{
		fscanf(fp, "%s%d%d", Available->licensePlate, Available->mileage, Available->date);
		i++;
	}
}
void writeToFile(char *fileName)
{
}
void addNodeToAvailableList(AvailableC **Available, AvailableC *node)
{
	AvailableC *temp = *Available;
	if (*Available == NULL)
	{
		*Available = node;
		return;
	}
	else
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
	}
	temp->next = node;
}
void createAvailableNode()
{
	AvailableC *newEntry = malloc(sizeof(AvailableC));
	printf("Enter license licensePlate: ");
	scanf("%s", newEntry->licensePlate);
	printf("Enter mileage: ");
	scanf("%d", &newEntry->mileage);
	newEntry->date = 0;
	newEntry->next = NULL;
}
void rentedCarReturn(RentedC *Rented, char licensePlate[])
{
	RentedC *tempCar = Rented;
	if (Rented == NULL)
	{
		printf("\nThis rented car does not exist, please enter a different license licensePlate.\n\n");
	}
	while (tempCar != NULL)
	{
		if (strcmp(tempCar->licensePlate, licensePlate) == 0)
		{
		}

		tempCar = tempCar->next;
		if (tempCar == NULL)
		{
			printf("\nThis rented car does not exist, please enter a different license licensePlate.\n\n");
		}
	}
}
void deleteReturnedList(RentedC **Rented, RentedC *node)
{
	int counter = 0;
	int n = 0;
	RentedC *currentCar = *Rented;
	RentedC *tempCar = *Rented;
	RentedC *previousCar = *Rented;
	while (tempCar != NULL)
	{
		n++;
		tempCar = tempCar->next;
	}
	if (strcmp(currentCar->licensePlate, node->licensePlate) == 0 && n == 1)
	{
		*Rented = currentCar->next;
		free(currentCar);
		currentCar = NULL;
	}
	else
	{
		while (n != 1)
		{
			n--;
			previousCar = currentCar;
			currentCar = currentCar->next;

			if (strcmp(currentCar->licensePlate, node->licensePlate) == 0)
			{
				previousCar->next = currentCar->next;
				free(currentCar);
				currentCar = NULL;
			}
		}
	}
}
void addNodeToAtWkshopList(AtWkshopC **AtWkshop, AtWkshopC *node)
{
	AtWkshopC *temp = *AtWkshop;
	if (*AtWkshop == NULL)
	{
		*AtWkshop = node;
		return;
	}
	else
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
	}
	temp->next = node;
}
