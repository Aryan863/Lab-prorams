#include<iostream>
#include<array>
#include<algorithm>
using namespace std;


//Iterative Approach
int element;
int n;
int BinarySearch(int arr[], int s, int e, int element){
  int m;
while(s<=e)
{
    m=(s+e)/2;
    if(arr[m]==element)
    return m;
    else
    {
        if(arr[m]>element)
        e=m-1;
        else if(arr[m]<element)
        s=m+1;
    }

}
 return -1;
    
}


//Recursive approach

int RecBinarySearch(int arr[], int s, int e, int element)
{
    int m;
    if(s<=e)
    {
        m=(s+e)/2;
        if(arr[m]==element)
           return m;
         else
         {
            if(arr[m]>element)
               return(RecBinarySearch(arr,s,m-1,element));
            else
               return(RecBinarySearch(arr,m+1,e,element));
         }
    
    }
    return -1;
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
   
    sort(arr ,arr+n);    //c++ stl sort() function

    //Calling the iterative search function
    cout<<BinarySearch(arr, 0, n-1, num)<<endl;

    //calling the recursive search function
    cout<<RecBinarySearch(arr, 0, n-1, num)<<endl;
    
    return 0;
}