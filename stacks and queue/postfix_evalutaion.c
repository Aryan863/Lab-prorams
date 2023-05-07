#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int isope(char ch)
{
    if(ch=='+' ||ch=='-' ||ch=='*' ||ch=='/' ||ch=='^' )
      return 1;
    else
      return 0;
}

void posEval()
{
    char pexp[80]; int flag[26], opr[26];
    int opr1, opr2;
    int st[80]; int top=-1;
    char ch;
    printf("\nEnter postfix expression");
    scanf("%s",&pexp);

    for(int i=0; i<26; i++)
      flag[i]=0;

    for(int i=0; pexp[i]!='\0'; i++)
    {
        ch= pexp[i];
        if(ch>=97 && ch<=122)
        {
            if(flag[ch-97]==0)
            {
                flag[ch-97]=1;
                printf("\nEnter value of %c",ch);
                scanf("%d",&opr[ch-97]);
            }
        }
    }

    for(int i=0; pexp[i]!='\0'; i++)
    {
        ch= pexp[i];
        if(isope(ch)==0)
        {
            top++;
            st[top] = opr[ch-97];
        }
        else
        {
            opr1= st[top]; top--;
            opr2= st[top]; top--;

            switch(ch)
            {
                case '+':
                  top++; st[top]= opr1+ opr2;
                  break;
                
                case '-':
                  top++; st[top] = opr1+ opr2;
                  break;

                case '*':
                  top++; st[top]= opr1* opr2;
                  break;

                case '/':
                  top++; st[top]= opr1/ opr2;
                  break;

                case '^':
                  top++; st[top]= pow(opr1, opr2);
                  break;

                default:
                  printf("\nWrong choice");
                  break;
            }
        }
    }
    printf("\nPostfix evaluation- %d",st[top]);
}

int main()
{
    posEval();
    return 0;
}