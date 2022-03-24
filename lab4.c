#include <stdio.h>
#include <stdlib.h>

struct Mobile
{
	char model[100];
	char brand[50];
	int mem;
	float price;
	struct Mobile* next;
};

struct Mobile* head;

void insert()
{
	struct Mobile *mobile, *temp;
	int count = 0, choice = 1;
	
	mobile = (struct Mobile*)malloc(sizeof(struct Mobile));  
	    
	while(count < 5)
	{
		printf("\nEnter the details\n");
		printf("1. Model : ");
		scanf("%s",&mobile->model);
		
		printf("2. Brand : ");
		scanf("%s",&mobile->brand);
		
		printf("3. Memory : ");
		scanf("%d",&mobile->mem);
		
		printf("4. Price : ");
		scanf("%f",&mobile->price);
		
		count = count + 1;
	}
	printf("\n5 data inserted!");
	
	printf("\n\nDo you want to cont?(1/0)");
	scanf("%d",&choice);
	
	while(choice)
	{
		printf("\nEnter the details\n");
		printf("1. Model : ");
		scanf("%s",&mobile->model);
		
		printf("2. Brand : ");
		scanf("%s",&mobile->brand);
		
		printf("3. Memory : ");
		scanf("%d",&mobile->mem);
		
		printf("4. Price : ");
		scanf("%f",&mobile->price);
		
		if(head == NULL)
		{
			mobile -> next = NULL;  
            head = mobile;  
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
		
		printf("\nDo you want to cont?(1/0)");
		scanf("%d",&choice);
	}
}

void display()
{
	struct Mobile* mobile;
	mobile = head;
	
	if(mobile == NULL)
	{
		printf("\nOverflow");
	}
	
	
}


int main()
{
	int choice = 0;
	printf("\nPress:\n1. Insert\n2. Exit");
	scanf("%d",&choice);
	
	while(choice != 2)
	{
		switch(choice)
		{
			case 1:
				insert();
				break;
			
			case 2:
				exit(0);
				break;
			
			case 3:
				printf("\nWrong choice!");
				break;
		}
	}
}
