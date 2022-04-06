#include <stdio.h>
#include <stdlib.h>

void unsort(int array[])
{
	int i, size=10;
	int array1[10] = {23,56,12,78,45,89,90,45,67,34};
	for(i=0;i<=size;i++)
		array[i]=array1[i];
	printf("\n------Unsorted-----\n");
}

int count=0; 

void swap(int *a, int *b) {
  int temp = *a;
  count++;
  *a = *b;
  count++;
  *b = temp;
  count++;
}

int selectionSort(int array[], int size) {
	int i, step;
	printf("\nBefore Sorting:\n");
	for (i = 0; i < size; i++)
    printf("%d ", array[i]);
	for (step = 0; step < size - 1; step++){
		count++;
    	int min = step;
    	count++;
    	for (i = step + 1; i < size; i++){
    		count++;
    		if (array[i] < array[min]){
       			min = i;
       			count++;
       			count++;
       		}
    }
    swap(&array[min], &array[step]);
    count++;

  }
	printf("\n\nCOUNT : %d\n\n", count);
	return count;
//	count = 0;
}

void printArray(int array[], int size) {
  int i;
  printf("\nSorted Array \n");
  for (i = 0; i < size; ++i){
	printf("%d ", array[i]);
  }
  printf("\n");
}

  
int i,j,temp, count1 = 0;


int insertionSort(int array[], int size){
	printf("\nBefore Sorting:\n");
	for (i = 0; i < size; i++)
    	printf("%d ", array[i]);
    	
    	
	for(i = 1; i <= size - 1; i++){
		count1++;
      	for(j=i; j > 0 && array[j - 1] > array[j]; j--){
			count1++;
			temp = array[j];
			count1++;
        	array[j] = array[j - 1];
        	count1++;
			array[j - 1] = temp;
			count1++;
      	}
   	}
   	
   	
	printf("\n\nCOUNT : %d\n\n", count1);
	return count1;
	//count1 = 0;
}


int bubbleSort(int array[], int size)
{
printf("\nBefore Sorting:\n");
for (i = 0; i < size; i++)
    printf("%d ", array[i]);
   
   
    for (i = 1; i < size; i++){
      count1++;	
      for (j = 0; j < size - i; j++) {
      	 count1++;
         if (array[j] > array[j + 1]) {
         	count1++;
            temp = array[j];
            count1++;
            array[j] = array[j + 1];
            count1++;
            array[j + 1] = temp;
            count1++;
         }
      }
  }
  
  
printf("\n\nCOUNT : %d\n\n", count1);
return count1;
//count1 = 0;
}

void compare(int a, int b, int c)
{
	printf("\n----------------------------------Comparing Sort Algorithm----------------------------------\n");
	printf("|\tINSERTION SORT\t|\tSELECTION SORT\t|\tBUBBLE SORT\t|");
	printf("\n|\t%d\t\t\t%d\t\t\t%d\t\t|", a, b, c);
	printf("\n--------------------------------------------------------------------------------------------\n");
}


int main()
{
	int size = 10;
	int a, b, c;
	int array[10] = {23,56,12,78,45,89,90,45,67,34};
	
	int choice ;
	while(choice != 6)
	{
		
	
		printf("\n1. Insertion sort\n2. Selection Sort\n3. Bubble Sort\n4. Compare\n5. Unsort\n6. Exit\n Enter your choice : ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				a = insertionSort(array, size);
				printArray(array, size);  
				break;
			case 2:
				b = selectionSort(array, size);
				printArray(array, size);  
				break;
			
			case 3:
				c = bubbleSort(array, size);
				printArray(array, size);  
				break;
			
			case 4:
				
				//insertionSort(array, size);
				compare(a,b,c);
				break;
			
			case 5:
				unsort(array);
				printArray(array, size);  
				break;
			
			case 6:
				exit(0);
				break;
				
			default : 
				printf("\nWrong choice!");
			break;
		}
		
	}
}
