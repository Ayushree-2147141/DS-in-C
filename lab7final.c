#include<stdio.h>

typedef struct hash{
	int part;
	int quantity;
}hash;

int count;
int arr[20];


void mod(hash tab[])
{
	int k, i, mod, index;
	for(k=1; k<=20; k++)
		arr[k] = 0;
	
	for(i=1; i<=3; i++)
	{
		printf("Enter P value : ");
		scanf("%d",&tab[i].part);
		printf("Enter Q value : ");
		scanf("%d",&tab[i].quantity);
		mod = tab[i].part % 20;
		while(arr[mod] != 0)
		{
			mod++;
			count++;
		}
		arr[mod] = i;
	}
	printf("\nCollision : %d", count);
}

int search(hash tab[])
{
	int i, mod, buff, var, var2;
	
	printf("\nEnter Value : ");
	scanf("%d",&buff);
	mod = buff % 20;
	
	var = arr[mod];
	
	while(arr[mod] != 0)
	{
	if(tab[var].part == buff)
	{
		printf("\nQuantity = %d", tab[var].quantity);
		return(0);
	}
	else
		mod++;
	}
	
}


int main()
{
	hash tab[21];
	mod(tab);
	search(tab);
}
