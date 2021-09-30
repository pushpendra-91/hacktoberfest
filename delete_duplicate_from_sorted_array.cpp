#include<iostream>
#include<vector>
using namespace std;

int delete_duplicate(vector<int> &arr, int n)
{
    int j=0;
    for(int i=0; i<n; i++)
    {
        if(arr[i] != arr[i+1])
        {
            arr[j] = arr[i];
            cout<<"element goes to j "<<arr[i]<<" in "<<i<<"iteration"<<endl;
            j++;
        }
    }
    return j;
}

int main()
{
    vector<int>arr;
    int size;
    cout<<"Enter the size of array: ";
    cin>>size;
    cout<<"Enter array elements: "<<endl;
    for(int i=0, element = 0; i<size; i++)
    {
        cin>>element;
        arr.push_back(element);
    }
    int k = delete_duplicate(arr, size);
    cout<<"Updated array is: "<<endl;
    for (int i = 0; i < k; i++)
    {
        /* code */
        cout<<arr[i]<<" ";
    }
    
}