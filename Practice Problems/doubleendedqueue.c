/*
	Author:	JEC21AD041 SACHIN RAJ M
	Date : 20/10/2022 Thursday
	Exp No : 7
	Aim : Implementing Double Ended Queue Operations in an Array
	Operations : 1. Input Restricted Queue (insertion only in rear and deletion in front and rear)
		     2. Output Restricted Queue (deletion at front only and insertion in both front and rear)

*/


#include <stdio.h>
#define size 5
int front=-1,rear=-1,q[size],exit=1,loop=1,x=1;
void irq();
void orq();
void ins_rear();
void ins_front();
void del_front();
void del_rear();
void main()
{
    int choice,item;
    while(loop==1){
    printf("\n--------Double Ended Queue Operations--------\n");
    printf("1. Input Restricted Queue. \n");
    printf("2. Output Restricted Queue.\n");
    printf("3. Reset the Queue.\n");
    printf("4. Exit.\n");
    printf("Enter your Choice:");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
          {
               irq();
               break;
          }
    	case 2:
    	    {
    	         orq();
    	         break;
    	    }
        case 3:
            {
                front=-1,rear=-1;
                printf("Queue is Reset to Empty State.\n");
                break;
            }
        case 4:
            {
                loop=2;
                break;
            }default:printf("Invalid Choice!\n");
    }
  }
}


void ins_rear()      //function for insertion at rear
{
    int item;
    if((rear+1)%size==front)
        printf("Queue is Full.\n\n");
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
        rear = (rear+1)%size;
        q[rear]=item;
    }
}

void ins_front()	 //function for insertion at front
{
    int item;
    if((front+1)%size==rear)
        printf("Queue is Full.\n\n");
    else if(front==-1 && rear==-1){
     front=0;
     rear=0;
     printf("Enter the element to be inserted:");
     scanf("%d",&item);
     q[front]=item;
    }
    else {
         printf("Enter the element to be inserted:");
         scanf("%d",&item);
         front = (front+1)%size;
         q[front]=item;
  }
}

void del_rear()		//function for deleting from rear
{
   if(front==-1 && rear==-1)
   {
   	printf("Queue is Empty.\n");
   }
   else if(front==rear)
   {
   	printf("The deleted element:%d.\n\n",q[rear]);
   	front=-1,rear=-1;
   }
   else {
    printf("The deleted element:%d.\n\n",q[rear]);
    rear--;
   }
}

void del_front()          //function for popping elements
{
    if(front==-1 && rear==-1)
        printf("Circular Queue is Empty.\n\n");
    else if(front==rear){
        printf("The popped out element: %d.\n\n",q[front]);
        front=-1,rear=-1;
    }
    else{
        printf("The popped out element: %d.\n\n",q[front]);
        front = (front+1)%size;
    }
}


void display() {        //function for displaying the status for each operation
  int i;
  if (front==-1 && rear==-1)
    printf(" \n Empty Queue\n");
  else {
    for (i = front; i != rear; i = (i + 1) % size) {
      printf("%d ", q[i]);
    }
    printf("%d ", q[i]);
  }
}


void irq(){         //input restricted queue
        int x=1,ch;
      	while(x==1)
      	{
      	  printf("\n--------Input Restricted Queue Operations--------\n");
    	  printf("1. Insertion at Rear. \n");
    	  printf("2. Deletion from Front. \n");
    	  printf("3. Deletion from Rear. \n");
    	  printf("4. Display the current status of the Queue. \n");
    	  printf("5. Exit. \n");
    	  printf("Enter your Choice:");
    	  scanf("%d",&ch);
    	  switch(ch)
    	  {
    	    case 1:
    	    {
    	    	ins_rear();
    	    	break;
    	    }
    	    case 2:
    	    {
    	    	del_front();
    	    	break;
    	    }
    	    case 3:
    	    {
    	    	del_rear();
    	    	break;
    	    }
    	    case 4:
    	    {
    	    	display();
    	    	break;
    	    }
    	    case 5:
    	    {
    	    	x=2;
    	    	break;
    	    }default:printf("Invalid Choice.\n\n");
    	  }
      	}
}


void orq(){           //output restricted queue
          int ch,item;
    	  while(exit==1)
      	  {
      	  printf("\n--------Output Restricted Queue Operations--------\n");
    	  printf("1. Insertion at Front. \n");
    	  printf("2. Insertion at Rear. \n");
    	  printf("3. Deletion from Front. \n");
    	  printf("4. Display the current status of the Queue. \n");
    	  printf("5. Exit. \n");
    	  printf("Enter your Choice:");
    	  scanf("%d",&ch);
    	  switch(ch)
    	  {
    	    case 1:
    	    {
    	    	ins_front();
    	    	break;
    	    }
    	    case 2:
    	    {
    	    	ins_rear();
    	    	break;
    	    }
    	    case 3:
    	    {
    	    	del_front();
    	    	break;
    	    }
    	    case 4:
    	    {
    	    	display();
    	    	break;
    	    }
    	    case 5:
    	    {
    	    	exit=2;
    	    	break;
    	    }default:printf("Invalid Choice.\n\n");
    	  }
    	 }
    }

