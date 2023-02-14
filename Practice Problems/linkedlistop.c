/*
	Author:	JEC21AD041 SACHIN RAJ M
	Date : 28/11/2022 Thursday
	Exp No : 12
	Aim : Implementing Linked List and its Operations
*/


#include<stdlib.h>
#include <stdio.h>

void create();
void display();
void insertion();
void deletion();
void insert_begin();
void insert_end();
void insert_pos();
void delete_begin();
void delete_end();
void delete_pos();


struct node
{
        int data;
        struct node *next;
};
struct node *HEAD=NULL;
int main()
{
        int choice,x=1;
        while(x==1){

                printf("\n-----Linked List Operations-----\n");
                printf(" \n 1.Create");
                printf(" \n 2.Insertion");
                printf(" \n 3.Deletion");
                printf(" \n 4.Display");
                printf("\n 5.Exit");
                printf("\n Enter your choice:");
                scanf("%d",&choice);
                switch(choice)
                {
					case 1:
						create();
						break;
					case 2:
						insertion();
						break;
					case 3:
						deletion();
						break;
					case 4:
						display();
						break;
					case 5:
						x=2;
						break;
					}
				}
			}
void insertion()
{
	int choice,x=1;
        while(x==1){

                printf("\n---Insertion Operations---");
                printf(" \n 1.Insert at the beginning");
                printf(" \n 2.Insert at the end");
                printf(" \n 3.Insert at specified position");
                printf(" \n 4. Display");
                printf(" \n 5.Exit");
                printf("\n Enter your choice:");
                scanf("%d",&choice);
                switch(choice)
                {
					case 1:
						insert_begin();
						break;
					case 2:
						insert_end();
						break;
					case 3:
						insert_pos();
						break;
                    case 4:
                        display();
                        break;
                    case 5:
                        x=2;
                        break;
                        default:printf("\nWrong Choice!!\n");
                }
        }
}

void deletion()
{
    int x=1,choice;
    while(x==1){

        printf("\n---Insertion Operations---\n");
        printf(" \n 1.Deletion at the beginning");
        printf(" \n 2.Deletion at the end");
        printf(" \n 3.Deletion from a specified position");
        printf("\n 4.Display");
        printf(" \n 5.Exit");
        printf("\n Enter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                delete_begin();
                break;
            case 2:
                delete_end();
                break;
            case 3:
                delete_pos();
                break;
            case 4:
                display();
                break;
            case 5:
                x=2;
                break;
                default:printf("\nWrong Choice!!");
                }
        }
}


void create()
{
        struct node *temp,*ptr;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("Out of Memory Space.\n");
                exit(0);
        }
        printf("Enter the data value for the node:");
        scanf("%d",&temp->data);
        temp->next=NULL;
        if(HEAD==NULL)
        {
                HEAD=temp;
        }
        else
        {
                ptr=HEAD;
                while(ptr->next!=NULL)
                {
                        ptr=ptr->next;
                }
                ptr->next=temp;
        }
}
void display()
{
        struct node *ptr;
        if(HEAD==NULL)
        {
                printf("List is empty.\n");
                return;
        }
        else
        {
                ptr=HEAD;
                printf("The List elements are:");
                while(ptr!=NULL)
                {
                        printf("%d\t",ptr->data );
                        ptr=ptr->next ;
                }
        }
}
void insert_begin()
{
        struct node *temp;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("Out of Memory Space\n");
                return;
        }
        printf("Enter the data value for the node:" );
        scanf("%d",&temp->data);
        temp->next =NULL;
        if(HEAD==NULL)
        {
                HEAD=temp;
        }
        else
        {
                temp->next=HEAD;
                HEAD=temp;
        }
}
void insert_end()
{
        struct node *temp,*ptr;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("Out of Memory Space:");
                return;
        }
        printf("Enter the data value for the node:" );
        scanf("%d",&temp->data );
        temp->next =NULL;
        if(HEAD==NULL)
        {
                HEAD=temp;
        }
        else
        {
                ptr=HEAD;
                while(ptr->next !=NULL)
                {
                        ptr=ptr->next ;
                }
                ptr->next =temp;
        }
}
void insert_pos()
{
        struct node *ptr,*temp;
        int i,pos;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("Out of Memory Space:");
                return;
        }
        printf("Enter the position for the new node to be inserted:");
        scanf("%d",&pos);
        printf("nEnter the data value of the node.");
        scanf("%d",&temp->data) ;

        temp->next=NULL;
        if(pos==0)
        {
                temp->next=HEAD;
                HEAD=temp;
        }
        else
        {
                for(i=0,ptr=HEAD;i<pos-1;i++)
                {
                    ptr=ptr->next;
                    if(ptr==NULL)
                    {
                        printf("Position not found:[Handle with care]\n");
                        return;
                    }
                }
                temp->next =ptr->next ;
                ptr->next=temp;
        }
}
void delete_begin()
{
        struct node *ptr;
        if(ptr==NULL)
        {
                printf("List is Empty:n");
                return;
        }
        else
        {
                ptr=HEAD;
                HEAD=HEAD->next ;
                printf("The deleted element is :%d",ptr->data);
                free(ptr);
        }
}
void delete_end()
{
        struct node *temp,*ptr;
        if(HEAD==NULL)
        {
                printf("nList is Empty:");
                exit(0);
        }
        else if(HEAD->next == NULL)
        {
                ptr=HEAD;
                HEAD=NULL;
                printf("The deleted element is:%d",ptr->data);
                free(ptr);
        }
        else
        {
                ptr=HEAD;
                while(ptr->next!=NULL)
                {
                        temp=ptr;
                        ptr=ptr->next;
                }
                temp->next=NULL;
                printf("The deleted element is:%d",ptr->data);
                free(ptr);
        }
}
void delete_pos()
{
        int i,pos;
        struct node *temp,*ptr;
        if(HEAD==NULL)
        {
                printf("The List is Empty.");
                exit(0);
        }
        else
        {
                printf("Enter the position of the node to be deleted:");
                scanf("%d",&pos);
                if(pos==0)
                {
                        ptr=HEAD;
                        HEAD=HEAD->next ;
                        printf("The deleted element is:%d",ptr->data  );
                        free(ptr);
                }
                else
                {
                        ptr=HEAD;
                        for(i=0;i<pos;i++) {
                            temp=ptr;
                            ptr=ptr->next ;
                            if(ptr==NULL)
                            {
                                printf("Position not Found.");
                                return;
                            }
                        }
                        temp->next = ptr->next ;
                        printf("The deleted element is:%d .",ptr->data );
                        free(ptr);
                }
        }
}
