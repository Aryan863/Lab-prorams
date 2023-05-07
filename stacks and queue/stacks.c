#include<stdio.h>
#include<stdlib.h>
#define sz 10
struct Stack{

    int st[sz];
    int top;
}s;

int st_full()
{
  if(s.top == sz-1)
    return(1);
  else
    return 0;
}

int st_empty()
{
  if(s.top == -1)
    return(1);
  else
    return 0;
}

void push()
{
    int cont;
    int element;
    do
    {
        if(st_full()==1)
            printf("\nStack full");
        else
        {
            printf("\nEnter Element- ");
            scanf("%d",&element);
            s.top++;
            s.st[s.top]=element;
        }
        printf("\nDo you want to continue? 1:YES 0:NO- ");
        scanf("%d",&cont);
    } while (cont==1);     
}

void pop()
{
    int cont;
    do
    {
        if(st_empty()==1)
          printf("\nStack Empty");
        else
        {
            printf("\n%d is popped- ",s.st[s.top]);
            s.top--;
        }
    printf("\nDo you want to continue? 1:yes 0:No- ");
    scanf("%d",&cont);
    } while (cont == 1);
    
}

void display()
{
    if(st_empty()==1)
      printf("Stack Empty");
    else
    {
        printf("\n Stack -> ");
        for(int i=s.top; i>=0; i--)
          printf("%d ",s.st[i]);
    }
}

int main()
{
    s.top = -1;
    int ch;
    do
    {
       printf("\n1.push\n2.pop\n3.Display\n4.Exit\nEnter choice- ");
       scanf("%d",&ch);
       switch(ch)
       {
         case 1:
           push();
           break;
         case 2:
           pop();
           break;
         case 3:
           display();
           break;
         case 4:
           printf("\nComing out!!!");
           break;
         default:
           printf("\nWrong choice");
           break;
       }

    }while(ch!=4);
    return 0;
}