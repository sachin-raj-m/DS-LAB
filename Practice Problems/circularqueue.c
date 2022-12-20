/*
	Author:	JEC21AD041 SACHIN RAJ M
	Date : 20/10/2022 Thursday
	Exp No : 7
	Aim : Implementing Circular Queue Operations in an Array
          (Operations: enqueue,dequeue,displaying)
*/


#include <stdio.h>
#define max 5
int front=-1,rear=-1,q[max];
void enqueue();
void dequeue();
void display();
void main()
{
    int ch,size,x=1;
    while(x==1)
    {
        printf("\n--------Circular Queue Operations--------\n");
        printf("1. Insert elements to the Queue.\n");
        printf("2. Delete elements from the Queue.\n");
        printf("3. Display the contents of the queue.\n");
        printf("4. Exit\n");
        printf("Enter your Choice:");
        scanf("%d",&ch);

        switch(ch)              //Menu Driven Program
        {
        case 1: {
            enqueue();
            break;
        }
        case 2:{
            dequeue();
            break;
        }
        case 3:{
            display();
            break;
        }
        case 4:{
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
    int item;
    if((rear+1)%max==front)
        printf("Circular Queue is Full.\n\n");
    else if(front==-1 && rear==-1){
     front=0;
     rear=0;
     printf("Enter the element to be inserted:");
     scanf("%d",&item);
     q[rear]=item;
    }
    else {
         printf("Enter the element to be inserted:");
         scanf("%d",&item);
        rear = (rear+1)%max;
        q[rear]=item;
    }
}


void dequeue()          //function for popping elements
{
    if(front==-1 && rear==-1)
        printf("Circular Queue is Empty.\n\n");
    else if(front==rear){
        printf("The popped out element: %d.\n\n",q[front]);
        front=-1,rear=-1;
    }
    else{
        printf("The popped out element: %d.\n\n",q[front]);
        front = (front+1)%max;
    }
}


void display() {        //function for displaying the status for each operation
  int i;
  if (front==-1 && rear==-1)
    printf(" \n Empty Queue\n");
  else {
    for (i = front; i != rear; i = (i + 1) % max) {
      printf("%d ", q[i]);
    }
    printf("%d ", q[i]);
  }
}
