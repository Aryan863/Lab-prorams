#include<stdio.h>
#include<stdlib.h>

struct SLL
{
    int d;
    struct SLL *lp;
};

struct SLL * getNode()
{
    struct SLL *n;
    n=(struct SLL *)malloc(sizeof(struct SLL));
    n->lp= NULL;
    printf("\n Enter data-");
    scanf("%d",&n->d);
    return(n);
}

void display(struct SLL *s)
{
    struct SLL *q;
    if(s==NULL)
        printf("\n List Empty");
    else
    {
        for(q=s; q!=NULL; q=q->lp)
        {
            printf("%d ",q->d);
        }
    }
}

struct SLL * add(struct SLL *s)
{
    struct SLL *n, *q, *p;
    int pos;
    int cont;
    int i;
    do
    {
       n=getNode();
    if(s==NULL)
        s=n;
    else
    {
        printf("\n Enter position to add new node- ");
        scanf("%d",&pos);
        if(pos==1)
        {
            n->lp=s;
            s=n;
        }
        else
        {
            for(i=1, p=q=s; i<pos-1 && q!=NULL; p=q, q=q->lp, i++);

            if(q==NULL)
            {
                printf("\nOut of bounds position!!\nNode added at last");
                p->lp=n;
            }
            else
            {
                n->lp=q->lp;
                q->lp=n;
            }
        }
    }


      printf("\ndo you want to continue 1.Yes  0.No  ");
      scanf("%d",&cont);
    }while(cont==1);

    return(s);
}

struct SLL * delete(struct SLL *s)
{
     struct SLL *n, *q, *t;
    int pos;
    int cont;

    do
    {

        if(s==NULL)
        printf("\nList empty");
        else
        {
        printf("\n Enter position to delete- ");
        scanf("%d",&pos);
        if(pos==1)
        {
           t=s;
           s= s->lp;
           t->lp= NULL;
           free(t);
        }
        else
        {
            for(int i=1, p=q=s; i<pos-1 && q!=NULL; p=q, q=q->lp, i++);

            if(q==NULL || q->lp==NULL)
            {
                printf("\nOut of bounds position!!");
            }
            else
            {
                t=q->lp;
                q->lp= t->lp;
                t->lp=NULL;
                free(t);
            }
        }
    }

      printf("\ndo you want to continue 1.Yes  0.No  ");
      scanf("%d",&cont);
    }while(cont==1);


    return(s);

}

int main()
{
    struct SLL *s;
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
