#include <stdio.h>
#include <stdlib.h>

int array[100];

void random(int array[])
{   
	int i;
    for (i = 1; i <= 100; i++)
    {    
		array[i] = rand() % 200 ;
    }
}

void display()
{
	int i;
	for(i=1;i<=100;i++)
	{
		printf("Element at %d position : %d\n", i, array[i]);
	}
}

int search(int num, int array[]){

	int i, found=0, count=0;	
	for(i=0;i<100;i++)
	{
		count++;
		if(num==array[i])
			found++;
	}
	if(found > 0)
		printf("\nTHE NUMBER %d EXISTS IN THE ARRAY",num);
	else
	printf("\nTHE NUMBER %d DOES NOT EXIST IN THE ARRAY",num);
	
	printf("\nNo of Searches completed = %d",count);
	return(found);
}

int main()
{
	int num, count, cont = 1;
	float per;
	int choice ;
	while(cont == 1)
	{
		
		random(array);
		printf("\nRandom array genederated!");
		
		printf("\nDo you want to display?(1/0)");
		scanf("%d",&choice);
		
		if(choice ==1 )
		{
			display();
		}
	
		printf("-----------------------------------\n");
		printf("\nInput a random number between 1-200 : ");
		scanf("%d",&num);	
		
		printf("\n-----------------------------------\n");
		count=search(num, array);
		
		printf("\nNumber of Successful Search = %d",count);
		printf("\n-----------------------------------\n");
		
//		printf("\n %f", (count%100));

		per = count % 100;
		//per = (count/100)*100;
		
		printf("\nPercentage = %.2f %c",per, 37);
		
		printf("\nDo you want to cont?(1/0)");
		scanf("%d",&cont);
	}
}
