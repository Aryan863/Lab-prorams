#include<stdio.h>
#include<stdlib.h>
#define sz 10
#define MAX 20
int stack[MAX];
int top=-1;
void push(int);
int pop();


  void push(int val){
    top++;
    stack[top] = val;
}
int pop(){
    int val = stack[top];
    top--;
    return val;
}


void create(int g[sz][sz], int n)
{
   int i, j, d;
   for(i=1; i<=n; i++)
   {
     for(j=1; j<=n; j++)
       g[i][j]= 0;
   }

   while(1)
    {
        printf("\nEnter 2 Edge Vertices (Enter any vertex -1 to stop..): ");
        scanf("%d %d",&i, &j);
        if(i==-1 || j==-1)
        break;
        else
        {
            if(i<1 || j<1 || i>n || j>n)
            printf("\nInvalid Edge");
            else{
                g[i][j]=g[j][i]=1;      //Undirected
            }
        }
    }
       printf("The adjacency matrix formed is \n");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%d\t" ,g[i][j] );
        }
        printf("\n");
        
    }
}

void dfs(int g[sz][sz], int n)
{
    int v, st[20], top=-1, i, cont, visit[20];

    
        printf("\nEnter starting vertex: ");
        scanf("%d", &v);
        for(i=1; i<=n; i++)
          visit[i]=0;
        
        top++; st[top]= v;
        while(top!=-1)
        {
            v=st[top];
            if(visit[v]==0)
            {
                printf("%d ", v);
                visit[v]=1;
            }

            for(i=1; i<=n; i++)
            {
                if(g[v][i]==1 && visit[i]==0)
                {
                   
                    top++; st[top]= i;
                    break;
                }
            }
            if(i>n)
              top--;
        }
       
    
    
}

// void dfs(int arr[sz][sz]  , int n ){

//     int s;
//        printf("\nEnter starting vertex: ");
//         scanf("%d", &s);
//     int visited[n];
//     for (int i = 1; i <= n; i++)
//     {
//         visited[i] = 0;
//     }
//     push(s);
//     visited[s] = 1;
//     while (top!=-1)
//     {
//         s=pop();
//         printf("%d\t",s);
//         for (int i = 1; i <= n; i++)
//         {
//             if(arr[s][i]==1 && visited[i]!=1){
//                 visited[i] = 1;
//                 push(i);
//             }
//         }       
//     }
// }


void bfs(int arr[sz][sz]  , int n ){
    int s;
       printf("\nEnter starting vertex: ");
        scanf("%d", &s);
    int queue[20] , visited[n];
    int rear = 0 , front = 0;
    for (int i = 1; i <= n; i++)
    {
        visited[i] = 0;
    }
    queue[rear++] = s;
    visited[s] = 1;
    while (rear!= front)
    {
        s = queue[front++];
        printf("%d\t" , s);
        for (int i = 1; i <= n; i++)
        {
            if(arr[s][i]==1 && visited[i]!=1){
                visited[i] = 1;
                queue[rear++] = i;
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
    do
    {
         printf("\n1.DFS\n2.BFS\n3.Exit\nEnter choice- ");
         scanf("%d",&ch);
         switch(ch)
         {
            case 1: dfs(g, n); break;
            case 2: bfs(g, n); break;
            case 3:
            printf("\nComing out!!");
            break;
            default:
            printf("\n Wrong choice");
            break;
         }
         
    } while (ch!=3);
    
     
  }