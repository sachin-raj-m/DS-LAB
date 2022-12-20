#include <stdio.h>
#include <stdlib.h>
#define max 5
int size;

void insert(int pq[size][max],int front[size],int rear[size])
{
    printf("Enter the element to insert:\n");
    int item;
    scanf("%d", &item);
    printf("Enter the Priority:\n");
    int p;
    scanf("%d", &p);
    if (rear[p] == size+1)
    {
        printf("Overflow!\n");
    }
    else
    {
        if (rear[p] == -1)
        {
            front[p] = 0;
            rear[p] = 0;
        }
        else
        {
            rear[p]++;
        }
        pq[p][rear[p]] = item;
    }
}

void delete (int pq[size][max],int front[size],int rear[size])
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (pq[i][j] != 'a')
            {
                pq[i][j]='a';
                printf("Item deleted!\n");
                return;
            }
        }
    }
    printf("No item to be deleted!\n");
}

void print(int pq[size][max],int front[size],int rear[size])
{
    printf("Displaying Queue:\n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (pq[i][j] == 'a')
                printf("_ ");
            else
                printf("%d ", pq[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    printf("Enter Size of Priority:\n");
    scanf("%d",&size);
    printf("Priority is considered from top to bottom i.e, if the entered priority is 3(0 have the highest priority, then 1 and then the lowest priority for 2.)\n\n");
    int pq[size][max];
    int front[size];
    int rear[size];
    for(int i=0; i<size; i++)
    {
        front[i]=-1;
        rear[i]=-1;
        for(int j=0; j<5; j++)
        {
            pq[i][j]='a';
        }
    }

    int x=1;
    while(x==1)
    {
        int choice;
        printf("\n----Menu----\n");
        printf("1. Insert Element.\n");
        printf("2. Delete Element.\n");
        printf("3. Print Elements.\n");
        printf("4. Exit.\n");
        printf("Enter choice:\n");
        scanf(" %d", &choice);
        printf("\n");
        switch(choice)
    {
    case 1:
    {
        insert(pq,front,rear);
            break;
        }
        case 2:
        {
            delete(pq,front,rear);
            break;
        }
        case 3:
        {
            print(pq,front,rear);
            break;
        }
        case 4:
        {
            x=2;
            break;
        } default:
            printf("Invalid Choice!!");

        }
    }
}
