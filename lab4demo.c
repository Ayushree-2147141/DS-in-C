#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 25
/********************************************************************
* STRUCTURE MOBILE *
********************************************************************/
struct mobile {
   char model[MAX];
   char brand[MAX];
   int capacity;
   float price;
};

void display(struct mobile *mob, int size);
void sort_brand(struct mobile *mob, int size);
void sort_price(struct mobile *mob, int size);

int main()
{
	int i, n, capacity;
	char mob_model[MAX], mob_brand[MAX];
	float price;
	
	printf("Enter number of mobiles:");
	scanf("%d", &n);
	
	struct mobile mob[n];
	
	for (i = 0; i < n; i++) 
	{
		printf("\n");

		printf("\nEnter mobile %d details :", i);
		
		printf("\nEnter mobile model : ");
		scanf("%s", &mob[i].model);
		
		printf("\nEnter mobile brand : ");
		scanf("%s", &mob[i].brand);
		
		printf("\nEnter mobile capacity : ");
		scanf("%d", &mob[i].capacity);
		
		printf("\nEnter Selling price : ");
		scanf("%f", &mob[i].price);
		
		printf("\n");
	}
		
	sort_brand(mob, n);
	sort_price(mob, n);
   
    return 0;
}

void display(struct mobile *mob, int size)
{
	int i;
	for (i = 0; i < size; i++) 
	{
		printf("\n");
		
		printf("\n\t\t\tMobile %d details :", i);
		
		printf("\n\n\t\t\tMobile model : %s", mob[i].model);
		
		printf("\n\n\t\t\tMobile brand : %s", mob[i].brand);
		
		printf("\n\n\t\t\tMobile capacity : %d", mob[i].capacity);
		
		printf("\n\n\t\t\tMobile price : %2f", mob[i].price);
		
		printf("\n");
   }
}

void sort_brand(struct mobile *mob, int size)
{
	int i, j, min_idx;
	
	char minStr[MAX];
	for (i = 0; i < size-1; i++)
	{
		// Find the minimum element in unsorted array
		int min_idx = i;
		strcpy(minStr, mob[i].brand);
		for (j = i+1; j < size; j++)
		{
		    // If min is greater than arr[j]
		    if (strcmp(minStr, mob[j].brand) > 0)
		    {
		        // Make arr[j] as minStr and update min_idx
		        strcpy(minStr, mob[j].brand);
		        min_idx = j;
		    }
		}
		
		// Swap the found minimum element with the first element
		if (min_idx != i)
		{
		    struct mobile temp;
		    temp = mob[i];
		    mob[i] = mob[min_idx];
		    mob[min_idx] = temp;
		}
	}
	
	display(mob, size);
}

void sort_price(struct mobile *mob, int size)
{
	int i, j, min_idx;
	float min_price;
		
	for (i = 0; i < size-1; i++)
	{
		// Find the minimum element in unsorted array
		int min_idx = i;
		min_price = mob[i].price;
		for (j = i+1; j < size; j++)
		{
		    // If min is greater than arr[j]
		    if (min_price > mob[j].price)
		    {
		        // Make arr[j] as minStr and update min_idx
		        min_price = mob[j].price;
		        min_idx = j;
		    }
		}
		
		// Swap the found minimum element with the first element
		if (min_idx != i)
		{
		    struct mobile temp;
		    temp = mob[i];
		    mob[i] = mob[min_idx];
		    mob[min_idx] = temp;
		}
	}
	
	display(mob, size);
}

