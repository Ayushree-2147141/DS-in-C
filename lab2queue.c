#include<stdio.h>  
#include<stdlib.h>

//struct node   
//{  
//    int data;   
//    struct node *next;  
//};  
//
//struct node *front, *rear; 

#include "mystack.h"

int temp, sum = 0, avg = 0, item, n = 0;


//inserting values into queue
void insert(int item)  
{  
    struct node *ptr;     
    
    //memory allocation
    ptr = (struct node *) malloc (sizeof(struct node));  
    if(ptr == NULL)  
    {  
        printf("\nOVERFLOW\n");  
        return;  
    } 
	
	//inserting the items into queue 
    else  
    {     
        ptr -> data = item; 
        //increasing the count
		n++; 
		//first node
        if(front == NULL)  
        {  
            front = ptr;  
            rear = ptr;   
            front -> next = NULL;  
            rear -> next = NULL;  
        }  
        else   
        {  
            rear -> next = ptr;  
            rear = ptr;  
            rear->next = NULL;  
        }  
    }  
}

//dequeue operation 
void delete()  
{  
    struct node *ptr; 
	//queue is empty 
    if(front == NULL)  
    {  
    	printf("\nNo elements to be removed!");
        printf("\nUNDERFLOW\n");  
        return;  
    }  
    else   
    {  
    
        ptr = front;  
        temp = front -> data;
        front = front -> next;  
        free(ptr);  
    }  
}  
  
//displaying the contents of queue  
void display()  
{  
    struct node *ptr;  
    ptr = front;      
    if(front == NULL)  
    {  
        printf("\nQueueUnderflow\n"); 
    }  
    else  
    {   printf("\nPrinting Queue.....\n");  
        while(ptr != NULL)   
        {  
            printf("| %d ",ptr -> data);  
            ptr = ptr -> next;  
        }  
        printf("|\n");
    }  
}   

//performing sum of all data in nodes in queue
void add(int n)
{
	int i = n;
	sum=0;
	while(i>0){
		delete();
		sum = sum + temp;
		insert(temp);
		i--;
	}
	printf("\n******************************\n");
	printf("SUM = %d\n", sum);
	avg =  sum/n;
	printf("AVERAGE = %d\n", avg);
	printf("******************************\n");
}

//negative numbers
void neg(int n)
{
	int i=n;
	while(i>0){
		
		delete();
		if(temp>=0){
		insert(temp);
		}
	i--;	
	}
}

//main 
void main ()  
{  
    int choice;
	printf("\n*************************Queue Implementation using Linked List*****************************\n");      
	while(choice != 6)   
    {      
        printf("\n1.Enqueue\n2.Dequeue\n3.Negative\n4.Add&Avg\n5.Display\n6.Exit");  
        printf("\nEnter your choice : ");  
        scanf("%d",& choice);  
        switch(choice)  
        {  
            case 1:  
	            printf("\nEnter value : ");  
	        	scanf("%d",&item);
	            insert(item);  
            break;  
            case 2:  
	            delete();  
	            break;  
            case 3:  
	   			neg(n);
			    display();
            break;  
            case 4:  
	            add(n);
	            break;
			case 6:
				exit(0);
			break;  
			case 5: 
				display();
			break;
            default:   
            	printf("\nEnter valid choice. . . .\n");  
            break;
        }  
    }  
}  

