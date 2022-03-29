#include <stdio.h>
#include <stdlib.h>
#define max 100
struct Mobile 
{
	char model[max];
	char brand[max];
	int memory;
	float price;
	struct Mobile* next;
};

struct Mobile* head = NULL;
struct Mobile* sorted = NULL;


void insert()
{

	struct Mobile *ptr,*temp;
	ptr = (struct Mobile*)malloc(sizeof(struct Mobile));
	
	if(ptr==NULL)
	{
		printf("\nOverflow!");
	}
	else
	{
		printf("\nModel: ");
		scanf("%s",&ptr->model);
		
		printf("\nBrand: ");
		scanf("%s",&ptr->brand);
		
		printf("\nMemory: ");
		scanf("%d",&ptr->memory);
		
		printf("\nPrice: ");
		scanf("%f",&ptr->price);
		
		if(head == NULL)  
        {  
            ptr -> next = NULL;  
            head = ptr;  
            printf("\nNode inserted\n");  
        } 
		else  
        {  
            temp = head;  
            while (temp -> next != NULL)  
            {  
                temp = temp -> next;  
            }  
            temp->next = ptr;  
            ptr->next = NULL;  
            printf("\nNode inserted\n");  
          
        }   
        
	}
}

void display()
{
	
	struct Mobile* ptr;
	ptr = head;   
    if(ptr == NULL)  
    {  
        printf("\nNothing to display");  
    }  
    
    else
    {
    	printf("\nPrinting values . . . . .\n"); 
    	printf("\n\n-----------------------------------------------------------\n");
		printf("|\tMODEL\t|\tBRAND\t|\tMEMORY\t|\tPRICE\t    |")  ;
        while (ptr!=NULL)  
        {  
 
			printf("\n\n----------------------------------------------------------------\n");
//			printf("\nModel\t:\t%s",ptr->model);
//			printf("\nBrand\t:\t%s",ptr->brand);
//			printf("\nMemory\t:\t%d",ptr->memory);
//			printf("\nPrice\t:\t%.2f",ptr->price);
			printf("|\t%s\t|\t%s\t|\t%d\t|\t%.2f  \t|",ptr->model,ptr->brand,ptr->memory,ptr->price)  ;
			
			ptr = ptr->next;
        } 
        printf("\n\n----------------------------------------------------------------------\n");
	}

}


void sortedInsert(struct Mobile* ptr)
{
	
	if (sorted == NULL || sorted->price >= ptr->price) 
	{
		ptr->next = sorted;
		sorted = ptr;
	}
	else {
		struct Mobile* current = sorted;
		
		while (current->next != NULL
			&& current->next->price < ptr->price) {
			current = current->next;
		}
		ptr->next = current->next;
		current->next = ptr;
	}
}


void priceSort()
{
	struct Mobile* current = head;

	while (current != NULL) 
	{
		struct Mobile* next = current->next;
		
		sortedInsert(current);
		
		current = next;
	}
	head = sorted;
}


void sortedBrandInsert(struct Mobile* ptr)
{
	
	if (sorted == NULL || strcmp(sorted->brand, ptr->brand) > 0)
	{
		ptr->next = sorted;
		sorted = ptr;
	}
	else {
		struct Mobile* current = sorted;
		
		while (current->next != NULL && (strcmp(current->brand , ptr->next->brand) > 0))
			{
			current = current->next;
		}
		ptr->next = current->next;
		current->next = ptr;
	}
}


void brandSort()
{
	struct Mobile* current = head;

	while (current != NULL) 
	{
		struct Mobile* next = current->next;
		
		sortedBrandInsert(current);
		
		current = next;
	}
	head = sorted;
}

int main()
{


int ch, ans = 1, count = 1 ;
	
	while(ans == 1)
	{
		printf("\nPress:\n1.\tAccept\n2.\tDisplay\n3.\tSort based on price\n4.\tAfter sort\n5.\tSort based on brand\n6.\tExit\n");
		printf("\n------------------------------------------------------------------------------------\n");
		printf("\t\t\tEnter :");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				while(count <=4 )
				{
					insert();
					count++;
				}
				insert();
				break;
			
			case 2:

				display();
				printf("\n");
				break;
							
			case 3:
				priceSort(head);
				printf("\nList sorted!");
				break;
				
			case 4:
				printf("Linked List after sorting:\n");
				display(head);
				printf("\nList sorted!");
				break;
				
			case 5:
				brandSort(head);
				printf("\nList sorted according to brand!");
				break;
			
			case 6:
				exit(0);
				break;
				
			default:
				printf("\nWrong choice!");
		}
		printf("\nDo you want to cont?(1/0): ")	;
		scanf("%d",&ans);
	}
}



