#include<iostream>
#include<array>
using namespace std;

int n;

void DispArray(int arr[], int n)              //Function to display array
{
  
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
}

void Merge(int arr[], int s, int m, int e){
   int i,j,k;
   int b[100];
  i=s;
  j=m+1;
  k=s;

  while(i<=m && j<=e)
  {
    if(arr[i]<=arr[j])
    {
        b[k]=arr[i];
        i++,k++;
    }
    else
    {
        b[k]=arr[j];
        j++,k++;
    }
  }

  while(i<=m)     // for handling left part
  {
    b[k]=arr[i];
    i++,k++;
  }
  while(j<=e)      //for handling right part
  {
    b[k]=arr[j];
    j++,k++;
  }
  for(i=s;i<=e;i++)
  {
    arr[i]=b[i];
  }
 
  


}

void Part(int arr[], int s, int e)
{
    int m;
    if(s<e)
    {
        m=(s+e)/2;
        Part(arr,s,m);
        Part(arr,m+1,e);
        Merge(arr,s,m,e);
    }

}



int main()
{
    //Array input
    cout<<"input array size"<<endl;;
    cin>>n;
    int arr[n];
    cout<<"Input array elements"<<endl;
    for(int i=0;i<n;i++)
    cin>>arr[i];

  

    //Calling the search function
   Part(arr, 0 ,n-1);
       cout<<"Sorted array-> ";
   DispArray(arr,n);
    return 0;
}