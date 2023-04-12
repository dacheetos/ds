#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 20

int stack[SIZE], top;

void push(int);
int pop();
void disp();
void balanced(char[]);
int prec(char);


int main()
{
    top=-1;   
    char exp[20];
    int i, x;
    printf("\nEnter the infix expression: ");
    gets(exp);
    balanced(exp);
    printf("\nThe postfix expression is: ");
    for(i=0; exp[i]!='\0'; i++)
    {
        if(isalnum(exp[i]))
            printf("%c", exp[i]);
        else
            if(exp[i] == '(')
               push(exp[i]);
        else
          if(exp[i] == ')')
          {
              while((x=pop()) != '(')
                      printf("%c", x);
          }
        else
        {
            while(prec(stack[top]) >= prec(exp[i]))
                 printf("%c", pop());

            push(exp[i]);
        }
    }

    while(top!=-1)
        printf("%c", pop());

    return 0;
}


void push(int item)
{
    if(top==SIZE-1)
    {
        printf("\nStack Overflow");
        return;
    }
    stack[++top]=item;
}

int pop()
{
    if(top==-1)
    {
        printf("\nStack underflow");
        return -1;
    }
    return stack[top--];
}

void disp()
{
    if(top==-1)
    {
        printf("\nStack is empty");
        return;
    }
    printf("\nThe stack contents are: ");
    for(int i=0; i<=top; i++)
        printf("%d  ", stack[i]);
}


void balanced(char exp[])
{
    int i, count=0;
    for(i=0; exp[i]!='\0'; i++)
    {
       if(exp[i] == '(')
           count++;
        else
            if(exp[i] == ')')
               count--;
    }
    if(count == 0)
    {
        printf("\nBalanced expression");
        return;
    }
    printf("\nUnbalanced expression");
    exit(1);
}


int prec(char x)
{
    if(x=='(')
        return 0;
    else
        if(x=='+' || x=='-')
           return 1;
    else
        if(x=='*' || x=='/')
           return 2;
    else
        return(-1);
}
