#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define SIZE 100
char stack[SIZE],top=-1;
char expr[SIZE];
char out[SIZE];
char myStr[2];
char* getStr(char ch)
{
    myStr[0] = ch;
    myStr[1] = '\0';
    return myStr;
}
int stackFull(){
    return(top==SIZE-1);
}
int stackEmpty()
{
    return(top==-1);
}
int prec(char ch)
{
    switch(ch)
    {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}
int isOperand(char ch)
{
    return(isdigit(ch)||isalpha(ch));
}
void push(char data)
{
    if(stackFull()) printf("Stack Overflow !");
    else
    {
        stack[++top] = data;
    }
}
char pop()
{
    char del;
    if(stackEmpty()) printf("Stack Underflow");
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
char peek()
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
void infixToPostfix()
{
    for(int i=0;i<strlen(expr);i++)
    {
        if(isOperand(expr[i]))
        {
            strcat(out,getStr(expr[i]));
        }
        else if(expr[i]=='(')
        {
            push(expr[i]);
        }
        else if(expr[i]==')')
        {
            while(peek()!='(')
            {
                if(stackEmpty())
                {
                    printf("Invalid exprression !");
                    break;
                }
                strcat(out,getStr(pop()));
            }
            pop();
        }
        else
        {
            while(!stackEmpty()&&prec(peek())>=prec(expr[i]))
            {
                strcat(out,getStr(pop()));
            }
            push(expr[i]);
        }
    }
    while(!stackEmpty())
    {
        if(peek()=='('||peek()==')')
        {
            printf("Invalid exprression");
            break;
        }
        strcat(out,getStr(pop()));
    }
}
void main()
{
    printf("Enter a valid Infix exprression :");
    scanf("%s",expr);
    out[0] = '\0';
    infixToPostfix();
    printf("%s",out);
}