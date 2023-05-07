#include<iostream>
#include<array>
using namespace std;

int n;

void DispArray(int arr[], int n)              //Function to display array
{
  
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
}

void BubbleSort(int arr[], int n){
    int temp;

    for(int i=0;i<n-1;i++)
    {
        for(int j=0; j<n-1-i ; j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]= temp;
            }
        }
    }
      cout<<"sorted array -> ";
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
    BubbleSort(arr,n);
    return 0;
}