#include<stdio.h>
#include<stdlib.h>

int row=10;
int col=4;
int arr[10][4];

void print()
{
  for(int i = 0;i<row;i++)
    {
      printf("%d | ",i);
      for(int j = 0;j<col;j++)
      {
       printf("%d ",arr[i][j]);
      }
      printf("\n");
    }
}

void delete()
{
    int n;
    printf("\nenter value to search");
    scanf("%d",&n);
  for(int i = 0;i<col;i++)
  {
    for(int j = 0;j<row;j++)
    {
      if(arr[i][j]==n)
      {
        arr[i][j]=-1;
        return;
      }
    }
  }
}

void search()
{
  int n;
   printf("\nenter value to delete");
    scanf("%d",&n);
  int f =0;
  for(int i = 0;i<col;i++)
  {
    for(int j = 0;j<row;j++)
    {
      if(arr[i][j]==n)
      {
        f=1;
        break;
      }
      }
      break;
    }
    if(f==1)
    {
      printf("\nFOUND");
    }
    else{
      printf("\nNot found");
    }
  }

void inputValue()
{
  int n;
  printf("\nenter value to input ");
  scanf("%d",&n);
  int key = n%8;
  for(int i = 0;i<row;i++)
  {
    int index = (key+i)%row;
    for(int j = 0;j<col;j++)
    {
      if(arr[index][j]==-1)
      {
        arr
        [index][j]=n;
        return;
      }
    }
  }
  printf("table full\n");
}

void main()
{
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<row; j++)
        {
            arr[i][j]=-1;
        }
    }

    int ch;
    do
    {
        printf("\n1.Add\n2.Delete\n3.Display\n4.Search\n5.Exit\nEnter choice- ");
        scanf("%d",&ch);

        switch(ch)
        {
           case 1:
           inputValue();
           print();
           break;
           case 2:
           delete();
           print();
           break;
           case 3:
           print();
           break;
           case 4:
           search();
           break;
           case 5:
           printf("Coming out!!");
           break;
           default:
           printf("Wrong choice");
           break;
        }
    } while (ch!=5);

    
}