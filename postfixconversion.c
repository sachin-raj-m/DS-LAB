#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

int priority(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    return 0;
}

int main()
{
    char exp[100],result[100];
    char *e, x;
    int count=0;
    printf("Enter the expression : ");
    scanf("%s",exp);
    printf("\n");
    e = exp;

    while(*e != '\0')
    {
        if(isalnum(*e)){
            printf("%c",*e);
            result[count]= *e;
            count++;
        }
        else if(*e == '(')
            push(*e);
        else if(*e == ')')
        {
            while((x = pop()) != '('){
                printf("%c", x);
                result[count]= x;
                count++;
            }
        }
        else
        {
            while(priority(stack[top]) >= priority(*e)){
                int temp = pop();
                printf("%c",temp);
                result[count]= temp;
                count++;
            }
            push(*e);
        }
        e++;
    }

    while(top != -1)
    {
        char temp = pop();
        printf("%c",temp);
        result[count]= temp;
        count++;
    }
    printf("\n%s",result);
}
