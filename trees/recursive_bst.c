#include<stdio.h>
#include<stdlib.h>

struct BST
{
    int data;
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
    scanf("%d",&n->data);
    return(n);
}

void insert(struct BST * r, struct BST *n)
{
    while(1)
    {
        if(r->data > n->data)
        {
            if(r->lp == NULL)
            {
                r->lp = n;break;
            }
              
            else
              r= r->lp;  
        }
        else if(r->data < n->data)
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

// Preorder traversal using recursion

void preOrder(struct BST *r){
   
    if(r!=NULL){
        printf("%d ", r->data);
        preOrder(r->lp);
        preOrder(r->rp);
    }
}

// Inorder traversal using recursion
void inOrder(struct BST *r){
    if(r!=NULL){
        inOrder(r->lp);
        printf("%d ", r->data);
        inOrder(r->rp);
    }
}

// Postorder traversal using recursion
void postOrder(struct BST *r){
    if(r!=NULL){
        postOrder(r->lp);
        postOrder(r->rp);
        printf("%d ", r->data);
    }
}

// Function to generate mirrror image of a tree
void mirror(struct BST * r){
    struct BST * temp;
    if(r!=NULL){
        mirror(r->lp);
        mirror(r->rp);
        temp = r->lp;
        r->lp = r->rp;
        r->rp = temp;
    }
} 

// Function to count number of nodes.
//int cnt=0;
 int cnt1=0;
void count(struct BST *r){
   
    if(r!=NULL){
        printf("%d ", r->data);
        cnt1++;
        count(r->lp);
        count(r->rp);
    }
}
int ht=0;
void height(struct BST *r, int hn){
   
    if(r!=NULL){
        height(r->lp, hn+1);
        height(r->rp, hn+1);
        if(hn>ht)
          ht=hn;

          hn--;
    }
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
             // r = delete(r);
              break;
            case 3:
            //preOrder(r);
           // printf("number of nodes= %d",cnt1);   //no. of nodes.
             // postorder(r);
             // inorder(r);
             height(r,1);
             printf("height= %d",ht);
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