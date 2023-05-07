#include<iostream>
#include<array>
using namespace std;

int n;
int LinearSearch(int arr[], int n, int num){
    
    for(int i=0;i<n;i++){
        if(arr[i]==num){
          cout<<"Number found at "<<i<<" index"<<endl;     //If the number is found, return its position
          return i;
        }

    }
    cout<<"number not found"<<endl;
    return -1;                                              // if number is not found , return -1
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

    //Input number to be searched
    int num;
    cout<<"Enter the number to be searched"<<endl;
    cin>>num;

    //Calling the search function
    LinearSearch(arr,n,num);
    return 0;
}