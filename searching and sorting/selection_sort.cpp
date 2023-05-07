#include<iostream>
#include<array>
using namespace std;

int n;

void DispArray(int arr[], int n)              //Function to display array
{
  
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
}

void SelectionSort(int arr[], int n){
    int temp;
    for(int i=0; i<n-1;i++)
    {
        for(int j=i+1; j<n;j++)
        {
            if(arr[i]>arr[j])
            {
                temp=arr[i];     //swap the elements
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    cout<<"sorted array-> ";
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
    SelectionSort(arr,n);
    return 0;
}