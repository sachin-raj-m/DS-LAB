/*
	Author:	JEC21AD041 SACHIN RAJ M
	Date : 20/10/2022 Thursday
	Exp No : 5
	Aim : Implementing Queue Operations in an Array
          (Operations: enqueue,dequeue,displaying)
*/


#include <stdio.h>
#define max 50
int front=-1,rear=-1,q[max];
void enqueue();
void dequeue();
void display();
void main()
{
    int ch,size,x=1;
    while(x==1)
    {

        printf("\n--------Queue Operations--------\n");
        printf("1. Insert elements to the Queue.\n");
        printf("2. Delete elements from the Queue.\n");
        printf("3. Display the contents of the queue.\n");
        printf("4. Exit\n");
        printf("Enter your Choice:");
        scanf("%d",&ch);

        switch(ch)              //Menu Driven Program
        {
        case 1:
        {

            enqueue();
            break;
        }
        case 2:
        {
            dequeue();
            break;
        }
        case 3:
        {
            display();
            break;
        }
        case 4:
        {
            x=2;
            break;
        }
        default:
            printf("You have entered an Invalid Choice.\n\n");
        }
    }
}


void enqueue()      //function for enqueue
{
    int ele;
    if(rear==max-1)
        printf("Queue Full.\n\n");
    else
    {
        if(front==-1)
            front=0;
        printf("Enter element to be inserted:");
        scanf("%d",&ele);
        rear++;
        q[rear]=ele;;
    }
}


void dequeue()          //function for popping elements
{
    if(front==-1||front>rear)
        printf("Queue is Empty.\n\n");
    else
    {
        printf("The popped out element: %d.\n\n",q[front]);
        front++;
    }
}


void display()        //function for displaying the current status of Queue after each operation
{
    for(int i=front; i<=rear; i++)
        printf("%d\t",q[i]);
}
