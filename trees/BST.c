#include<stdio.h>
#include<stdlib.h>

struct BST
{
    int d;
    struct BST *lp,*rp;
    int v;
};

struct BST * getNode()
{
    struct BST * n;
    n=(struct BST *)malloc(sizeof(struct BST));
    n->lp=n->rp=NULL;
    n->v=0;
    printf("\nEnter data for new node- ");
    scanf("%d",&n->d);
    return(n);
}

void insert(struct BST * r, struct BST *n)
{
    while(1)
    {
        if(r->d > n->d)
        {
            if(r->lp == NULL)
            {
                r->lp = n;break;
            }
              
            else
              r= r->lp;  
        }
        else if(r->d < n->d)
        {
            if(r->rp == NULL)
            {
                r->rp=n;break;
            }
            else
              r=r->rp;
              
        }
        else
        {
            printf("\n duplicate node");
            free(n);
            break;
        }
        
    }
}

struct BST * delete(struct BST *r)
{
    struct BST *q, *p;
    int data;
    int i=0;     //root node deleted case(i=0)
    p=q=r;
    printf("\nEnter data to be deleted- ");
    scanf("%d",&data);
    while(q!=NULL)
    {
        if(q->d == data)
        {
           break;
        }
        else if(q->d > data)
        {
            p=q; q=q->lp;
            i=1;           //left child deletion case
        }
        else
        {
            p=q; q=q->rp;
            i=2;
        }
    }
    if(q==NULL)
    {
        printf("\nData not found");
        return r;
    }
    else if(i==1)
    {
        p->lp = q->rp;
        if(q->lp!=NULL)
          insert(p, q->lp); 
    }
    else if(i==2)
    {
        p->rp = q->rp;
        if(q->lp != NULL)
          insert(p, q->lp);
    }
    else if(i==0)
    {
        if(r->rp != NULL)
        {
            r=r->rp;
            if(q->lp!=NULL)            //q is used to check as r is changed
              insert(r, q->lp);
        }
        else
        {
            r=r->lp;
        }
    }
    q->lp=q->rp=NULL;
    free(q);
    return(r);


}

void inorder(struct BST * r)
{
    struct BST * st[50];
    int top=-1, flag, eflag=0;
    do
    {
        flag=0;
        while(r!=NULL)
        {
            //printf("%d ",r->d);
            top++;st[top]=r;
            r=r->lp;
        }
        do
        {
            if(top==-1)
            {
                eflag =1 ;
                break;
            }
            r= st[top]; top--;
            printf("%d ",r->d);
            if(r->rp!=NULL)
            {
                r=r->rp;
                flag=1;
            }
        } while (flag == 0);

    } while (eflag==0);
    

   
}


void preorder(struct BST * r)
{
    struct BST * st[50];
    int cnt=0;
    int top=-1, flag, eflag=0;
    do
    {
        flag=0;
        while(r!=NULL)
        {
            printf("%d ",r->d);
            cnt++;
            top++;st[top]=r;
            r=r->lp;
        }
        do
        {
            if(top==-1)
            {
                eflag =1 ;
                break;
            }
            r= st[top]; top--;
            //printf("%d ",r->d);
            if(r->rp!=NULL)
            {
                r=r->rp;
                flag=1;
            }
        } while (flag == 0);

    } while (eflag==0);
    printf("No. of nodes in tree- %d",cnt);
}

void postorder(struct BST *r)
{
    struct BST * st[50]; int top=-1;
    struct BST *t;
    int flag, eflag=0;
    int hn=0 , ht=0;
    do
    {
        flag=0;
        while(r!=NULL)
        {
            r->v=1; //hn++;
            top++; st[top]=r;
            r=r->lp;
        }
        do
        {
            if(top== -1)
            {
                eflag=1; break;
            }
            r= st[top]; top--;
            if(r->v==1)
            {
                r->v=2;
                top++; st[top]= r;
                r=r->rp;
                flag=1;
            }
            else
            {
                t=r->lp;
                r->lp=r->rp;
                r->rp = t;
            }

        } while (flag==0);
        
    } while (eflag==0);
    printf("\nheight of tree= %d",ht);
    
}

int main()
{
    int ch;
    struct BST *r, *n;
    r=NULL;
    do
    {
        printf("\n1. Add\n2. Delete\n3. Inorder\n4. Exit\nEnter choice- ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
              n=getNode();
              if(r == NULL)
                r = n;
              else
                insert(r, n);

              break;
            case 2:
              r = delete(r);
              break;
            case 3:
            inorder(r);
              postorder(r);
              inorder(r);
              break;
            case 4:
              printf("\n coming out");
              break;
            default:
              printf("\n Wrong choice");
              break;

        }

    }while(ch!=4);


    return 0;
}