#include<stdio.h>
#include<stdlib.h>
#include <string.h>


int precedence(char ch)
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
    default:
        return -1;
    }
}

int isope(char ch)
{
    if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^' )
        return 1;
    else
        return 0;
}

char * infixToPostfix()
{
    char ch;
    int i, j;
    char iexp[80]; char pexp[80];
    char st[80];
    int top=-1;
    printf("\n Enter infix expression-");
    scanf("%s",&iexp);
    strrev(iexp);

    for(i=0 ,j=0 ; iexp[i]!='\0'; i++)
    {
        ch=iexp[i];
        if(ch>=97 && ch<=122)
        {
            pexp[j]=ch;
            j++;
        }
        else if(ch=='(')
        {
            top++;
            st[top]=ch;

        }
        else if(ch==')')
        {
            while(top!=-1 && st[top]!='(')
            {
                pexp[j]=st[top];
                j++; top--;
            }
            if(top==-1 && st[top]!='(')
            {
                printf("Invalid expression");
                return pexp;
            }

            else
              top--;
        }
        else if(isope(ch))
        {

            while(top!=-1 && precedence(st[top])>= precedence(ch))
            {
                pexp[j]=st[top];
                j++; top--;
            }
            top++; st[top]=ch;
        }


    }
    while(top!=-1)
    {
        if(st[top]=='(')
        {
            printf("invalid expression");
            return pexp;
        }
        pexp[j]=st[top];
        j++; top--;
    }
    pexp[j]='\0';

     strrev(pexp);
    printf("\n prefix expression= %s",pexp);
     return pexp;
}

void main()
{
    char * a=infixToPostfix();

}
