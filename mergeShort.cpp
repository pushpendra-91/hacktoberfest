 // { Driver Code Starts
#include <stdio.h>
#include <conio.h>
#include <iostream>
// #include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


 // } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
         // Your code here
         if(l>=r){
             return;
         }
         int sa1 = m-l+1;
         int sa2 = r-m;
         int *la = new int[sa1];
         int *ra = new int[sa2];
         int k = l;
         for(int i=0; i<sa1; i++)
         {
             la[i] = arr[k];
             k++;
         }
         for(int j=0; j<sa2; j++)
         {
             ra[j] = arr[k];
             k++;
         }
         int isa1 = 0, isa2 = 0;
         int ima = l;
         while(isa1<sa1 && isa2<sa2)
         {
             if(la[isa1]<=ra[isa2])
             {
                 arr[ima] = la[isa1];
                 isa1++;
                 ima++;
             }
             else
             {
                 arr[ima] = ra[isa2];
                 isa2++;
                 ima++;
             }
         }
         
        if(isa1==sa1)
         {
             while(isa2<sa2)
             {
             arr[ima] = ra[isa2];
             isa2++;
             ima++;
            }
         }
         else if(isa2==sa2)
         {
             while(isa1<sa1)
             {
                 arr[ima] = la[isa1];
                 isa1++;
                 ima++;
             }
         }
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        if(l>=r)
        {
            return;
        }
        int m = (l+r)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
    public:
    void printArray(int A[], int size)
    {
    for (auto i = 0; i < size; i++)
    {
        cout << A[i] << " ";
    }
        
    }
};

// { Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}  // } Driver Code Ends
