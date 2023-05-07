#include<stdio.h>
#include<stdlib.h>
#define sz 5

struct Cqueue
{
    int d[sz];
    int f, r;
}Q;

int isFull()
{
    if((Q.f==0 && Q.r==sz-1) || (Q.f==Q.r+1 && Q.r!=-1))
      return 1;
    else 
      return 0;
}

int isEmpty()
{
    if(Q.r==-1)
      return 1;
    else
      return 0;
}

void display()
{
    int i;
    if(isEmpty()==1)
      printf("\nQueue Empty- ");
    else
    {
        printf("\nfront-> ");
        for(i=Q.f; i!=Q.r; i=(i+1)%sz)
          printf("%d ",Q.d[i]);

        printf("%d <-Rear",Q.d[i]);
    }
}

void add()
{
    int cont;
    do
    {
        if(isFull()==1)
        {
            printf("\nQueue full");
            break;
        }
     
        else
        {
            printf("\nEnter element-");
            Q.r=(Q.r+1)%sz;
            scanf("%d",&Q.d[Q.r]);
        }
              printf("\ndo you want to continue 1.Yes  0.No  ");
      scanf("%d",&cont);
    } while (cont==1);
    
    
}

void delete()
{
    int cont;
    do
    {
        if(isEmpty()==1)
        {
            printf("\nQueue empty");
            break;
        }
     
        else
        {
            if(Q.f==Q.r)
              {
                Q.f=0;
                Q.r=-1;
              }
              else
              {
                Q.f=(Q.f+1)%sz;
              }
        }
              printf("\ndo you want to continue 1.Yes  0.No  ");
      scanf("%d",&cont);
    } while (cont==1);
    
    
}

int main()
{
    int ch;
    Q.r=-1;
    Q.f=0;
    do
    {
        printf("\n1.Add\n2.Delete\n3.Display\n4.Exit\nEnter choice- ");
        scanf("%d",&ch);

        switch(ch)
        {
           case 1:
           add();
           break;
           case 2:
           delete();
           break;
           case 3:
           display();
           break;
           case 4:
           printf("Coming out!!");
           break;
           default:
           printf("Wrong choice");
           break;
        }
    } while (ch!=4);

    return 0;
}
