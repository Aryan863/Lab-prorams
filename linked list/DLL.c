#include<stdio.h>
#include<stdlib.h>

struct DLL
{
    int d;
    struct DLL *pp, *np;
};

struct DLL * getNode()
{
    struct DLL *n;
    n=(struct DLL *)malloc(sizeof(struct DLL));
    n->np= n->pp= NULL;
    printf("\nEnter data- ");
    scanf("%d",&n->d);
    return(n);

}

void display(struct DLL *s)
{
    struct DLL *q;
    if(s==NULL)
        printf("\nList Empty");
    else
    {
        for(q=s; q!=NULL; q=q->np)
            printf("%d ",q->d);
    }
}

struct DLL * add(struct DLL *s)
{
    struct DLL *n, *q, *p;
    int pos, i;
    int cont;
    do
    {
       n=getNode();
       if(s==NULL)
        s=n;
        else
        {
        printf("Enter position to add node- ");
        scanf("%d",&pos);
            if(pos==1)
            {
                n->np=s;
                s->pp=n;
                s=n;
            }
            else
            {
                for(i=1, p=q=s; i<pos-1 && q!=NULL; p=q, q=q->np, i++);

                if(q==NULL)
                {
                    printf("\nOut of bounds. Node added at end of list");
                    p->np=n;
                    n->pp=p;
                }
                else
                {
                    n->np=q->np;
                    n->pp=q;
                    (n->pp)->np= n;
                    if(n->np!=NULL)
                        (n->np)->pp=n;
                }
            }
        }

      printf("\ndo you want to continue 1.Yes  0.No  ");
      scanf("%d",&cont);
    }while(cont==1);

    return s;

}

struct DLL * delete(struct DLL *s)
{
   struct DLL *q, *n, *t;
   int pos;
   int i;
   int cont;
   do
   {
        if(s==NULL)
        printf("\nList empty");
        else
        {
            printf("Enter position to delete node- ");
            scanf("%d",&pos);
            if(pos==1)
            {
                t=s;
                s=s->np;
                t->np= t->pp = NULL;
                free(t);
            }
            else
            {
                for(i=1, q=s; i<pos-1 && q!=NULL; q=q->np, i++);

                if(q==NULL || q->np==NULL)
                printf("Out of bounds");
                else
                {
                    t=q->np;
                    q->np=t->np;
                    if(t->np!=NULL)
                        (t->np)->pp=q;
                    t->np= t->pp= NULL;
                    free(t);
                }
            }

        }
      printf("\ndo you want to continue 1.Yes  0.No  ");
      scanf("%d",&cont);
   }while(cont==1);


   return s;

}

int main()
{
    struct DLL *s;
    s=NULL;
    int ch;
    do
    {
        printf("\n1.Add\n2.Delete\n3.Display\n4.Exit\nEnter choice- ");
        scanf("%d",&ch);

        switch(ch)
        {
           case 1:
           s=add(s);
           break;
           case 2:
           s=delete(s);
           break;
           case 3:
           display(s);
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