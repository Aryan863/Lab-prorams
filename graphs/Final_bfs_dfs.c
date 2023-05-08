#include<stdio.h>
#include<stdlib.h>
#define sz 50
void create(int g[sz][sz], int n)
{
    int i,j;
    for(int i=1;i<=n;i++)
    {
        for(int j=1; j<=n; j++)
        {
            g[i][j]=0;
        }
    
    }
    while(1)
    {
        printf("\nEnter 2 connected vertex. enter any vertex -1 to stop- ");
        scanf("%d %d",&i,&j);
        if(i==-1 || j==-1)
          break;
        else
        {
            if(i<1 || j<1 || i>n || j>n)
              printf("\nInvalid vertex");
            else
            {
                g[i][j]=g[j][i]=1;
            }
        }

    }

}

void DFS(int g[sz][sz], int n)
{
   int visit[sz]; int st[sz]; int v; int top=-1;
   int i;
   for(int i=1;i<=n;i++)
     visit[i]=0;

   printf("\nEnter starting vertex- ");
   printf("\n");
   scanf("%d",&v);
   top++; st[top]=v;
   while(top!=-1)
   {
     v=st[top];
     if(visit[v]==0)
     {
        printf("%d ",v);
        visit[v]=1;
     }
     for(i=1; i<=n; i++)
     {
        if(g[v][i]==1 && visit[i]==0)
        {
            top++; st[top]=i;
            break;
        }
     }
     if(i>n)
       top--;

   }

}

void BFS(int g[sz][sz], int n)
{
    int q[sz];
    int f=0, r=-1;
    int i;
    int visit[sz];
    int v;

    for(int i=1; i<=n; i++)
      visit[i]=0;
    
   printf("\nEnter starting vertex- ");
   printf("\n");
   scanf("%d",&v);
   r++; q[r]=v;
   while(f<=r)
   {
    v=q[f]; f++;
    if(visit[v]==0)
    {
        printf("%d ",v);
        visit[v]=1;
    }
    for(i=1; i<=n; i++)
    {
        if(g[v][i]==1 && visit[i]==0)
        {
            r++; q[r]=i;
        }
    }
   }
    
}

void main()
  {
    int g[sz][sz], n, ch;
    printf("\nEnter no. of vertices: ");
    scanf("%d",&n);
    create(g,n);
     printf("The adjacency matrix formed is \n");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%d\t" ,g[i][j] );
        }
        printf("\n");
        
    }
    do
    {
         printf("\n1.DFS\n2.BFS\n3.Exit\nEnter choice- ");
         scanf("%d",&ch);
         switch(ch)
         {
            case 1: DFS(g, n); break;
            case 2: BFS(g, n); break;
            case 3:
            printf("\nComing out!!");
            break;
            default:
            printf("\n Wrong choice");
            break;
         }
         
    } while (ch!=3);
    
     
  }
