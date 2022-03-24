#include <stdio.h>
#include <stdlib.h>

#include "mystack.h"

void insert()   
{  
    struct node *ptr,*temp;  
    int item;     
    ptr = (struct node*)malloc(sizeof(struct node));      
    if(ptr == NULL)  
    {  
        printf("\nOVERFLOW");     
    }  
    else  
    {  
        printf("\nEnter value : ");  
        scanf("%d",&item);  
        ptr->data = item;  
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
    struct node *ptr;  
    ptr = head;   
    if(ptr == NULL)  
    {  
        printf("Nothing to print");  
    }  
    else  
    {  
        printf("\nPrinting values . . . . .\n");   
        while (ptr!=NULL)  
        {  
            printf("\n%d",ptr->data);  
            ptr = ptr -> next;  
        }  
    }  
    printf("\n");
}


void neg()
{
	struct node *ptr;    
    ptr = head;   
    
	if(ptr == NULL)  
    {  
        printf("\nEmpty List\n");  
    }  
    else  
    {     
        while (ptr!=NULL)  
        {  
            if(ptr->data < 0)  
            {  
                ptr->next = (ptr->next)->next;  
            }     
            ptr = ptr -> next;  
        }  
    }     
 	
}


int main()
{
int choice;
	printf("\n******************************************************\n");      
	while(choice != 4)   
    {      
        printf("\n1.Insert\n2.NegativeCheck\n3.Display\n4.Exit\n");  
        printf("\nEnter your choice : ");  
        scanf("%d",& choice);  
        switch(choice)  
        {  
            case 1:  
            	insert();  
            	break;  
            case 2:
				neg();
			    display();  
	            break;  
            case 4:  
				exit(0);
				break;  
			case 3:
				display();
				break;
            default:   
	            printf("\nEnter valid choice. . . .\n");  
	            break;
        }  
    }  
}  
