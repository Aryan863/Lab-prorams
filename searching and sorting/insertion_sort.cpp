#include<iostream>
#include<array>
using namespace std;

int n;
int temp;

void DispArray(int arr[], int n)              //Function to display array
{
  
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
}

void InsertionSort(int arr[], int n){                        
    int i, j;
     for(i=1;i<n;i++)
     {
        temp=arr[i];
        for( j=i; j>0 && arr[j-1]>temp ; j--)
        {
           arr[j]=arr[j-1];
        }
        arr[j]=temp;
     }

     cout<<"sorted array ->";
     DispArray(arr,n);
                                         
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
    InsertionSort(arr,n);
    return 0;
}