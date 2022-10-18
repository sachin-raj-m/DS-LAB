/*
	Author:	JEC21AD041 SACHIN RAJ M
	Date : 20/10/2022 Thursday
	Exp No : 6
	Aim : Implementing Stack Operations in an Array
          (Operations: enqueue,dequeue,displaying)
*/


#include <stdio.h>
#define max 50
int top=-1,stackop[max];
void push();
void pop();
void display();
void main()
{
    int ch,size,x=1;
    while(x==1)
    {
        printf("\n--------Stack Operations--------\n");
        printf("1. Insert elements to the Stack.\n");
        printf("2. Delete elements from the Stack.\n");
        printf("3. Display the contents of the Stack.\n");
        printf("4. Exit\n");
        printf("Enter your Choice:");
        scanf("%d",&ch);

        switch(ch)              //Menu Driven Program
        {
        case 1:{
            push();
            break;
        }
        case 2:{
            pop();
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
}//end of main function


void push()      //function for pushing elements
{
    int ele;
    if(top==max-1)
        printf("Stack Overflows.\n\n");
    else{
        top++;
        printf("Enter element to be inserted:");
        scanf("%d",&ele);
        stackop[top]=ele;
    }
}


void pop()          //function for popping elements
{
    if(top==-1)
        printf("Stack Underflows.\n\n");
    else{
        printf("The popped out element: %d.\n\n",stackop[top]);
        top--;
    }
}


void display()        //function for displaying the current status of Stack after each operation
{
    for(int i=top; i>=0; i--)
        printf("%d\t",stackop[i]);
}
