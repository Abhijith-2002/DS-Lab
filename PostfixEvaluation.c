#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define SIZE 100
int stack[SIZE],top=-1;
int expr[SIZE];
int stackFull(){
    return(top==SIZE-1);
}
int stackEmpty()
{
    return(top==-1);
}
int isOperand(int ch)
{
    return(isdigit(ch)||isalpha(ch));
}
void push(int data)
{
    if(stackFull()) printf("\nStack Overflow !");
    else
    {
        stack[++top] = data;
    }
}
int pop()
{
    int del;
    if(stackEmpty()) printf("\nStack Underflow");
    else if(top==0)
    {
        del = stack[top];
        top=-1;
    }
    else
    {
        del = stack[top];
        top--;
    }
    return del;
}
int peek()
{
    if(top==-1)
    {
        printf("\nStack empty");
        return '\0';
    }
    else
    {
        return stack[top];
    } 
}
void display()
{
    for(int i=0;i<=top;i++)
    {
        printf("%c",stack[i]);
    }
}
int postfixEval()
{
    for(int i=0;i<strlen(expr);i++)
    {
        if(isOperand())
        {
            push(expr[i]-'0');
        }
        else
        {
            int op2 = pop();
            int op1 = pop();
            int result;
            switch(expr[i])
            {
                case '+':
                    result = op1+op2;
                    break;
                case '-':
                    result = op1-op2;
                    break;
                case '*':
                    result = op1*op2;
                    break;
                case '/':
                    result = op1/op2;
                    break;
            }
            push(result);
        }
    }
    return pop();
}
void main()
{
    printf("\nEnter a valid Postfix exprression :");
    scanf("%s",expr);
    printf("\nResult : %d",postfixEval());
}