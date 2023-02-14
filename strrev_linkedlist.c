/*
	Author:	JEC21AD041 SACHIN RAJ M
	Date : 15/12/2022 Thursday
	Exp No : 15
	Aim : Program to reverse a String Using Linked List
*/



#include<stdio.h>
#include<malloc.h>

struct node
{
    char data;
    struct node* next;
};
struct node* head = NULL;

struct node* create_node(char);
void insert(char);
void reverse_list();
void print();
int main()
{
    insert('s');
    insert('a');
    insert('c');
    insert('h');
    insert('i');
    insert('n');

    printf("Linked List before reversed: \n");
    print();
    reverse_list();
    printf("\nLinked List after reversed: \n");
    print();
    return 0;
}


struct node* create_node(char data)
{
    struct node* new_node = (struct node*) malloc (sizeof(struct node));
    if (new_node == NULL)
    {
        printf("Memory can't be allocated for new node");
        return NULL;
    }
    else
    {
        new_node -> data = data;
        new_node -> next = NULL;
        return new_node;
    }
}


void insert(char data)
{
    struct node* new_node = create_node(data);
    if (new_node != NULL)
    {
        new_node -> next = head;
        head = new_node;
    }
}


void reverse_list()
{
    if (head == NULL)
    {
        return;
    }

    //create a stack of size of 100
    struct node* stack[100];
    int top = -1;
    struct node* temp = head;

    // push list node into the stack
    while (temp != NULL)
    {
        top += 1;
        stack[top] = temp;
        temp = temp->next;
    }

    // make a new head node
    head = stack[top];
    temp = stack[top];

    // pop the nodes from the stack and insert them at the end of the last node
    while (--top >= 0)
    {
        temp->next = stack[top];
        temp = stack[top];
    }
    temp->next = NULL;
}


void print()
{
    struct node* temp = head;
    while (temp != NULL)
    {
        printf("%c --> ", temp->data);
        temp = temp->next;
    }
    printf("NULL \n");
}
