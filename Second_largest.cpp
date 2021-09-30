/* Naive Solution to find Second largest element */

#include<iostream>
using namespace std;

//Function finds largest element
int getlargest(int arr[], int n)
{
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        /* code */
        if(arr[i]> arr[max])
        max = i;
    }
    return max;
}
/*function check for second largest element and returns index of the element */
int getseclargest(int arr[], int n)
{
    int largest = getlargest(arr, n);
    int result = -1;
    for (int i = 0; i<n; i++)
    {
        if(arr[i] != arr[largest])
        {
            if(result == -1)
                result = i;
            else if(arr[i] > arr[result])
            result = i;
        }
    }
    return result;
}
/* Efficient Method */
int get_second_largest(int arr[], int n)
{
    int sec_largest = -1, largest = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[largest])
        {
            sec_largest = largest;
            largest = i;
        }
        else if (arr[i] != arr[largest])
        {
            if (sec_largest == -1 || arr[i] > arr[sec_largest])
            {
                sec_largest = i;
            }
        }
    }
    return sec_largest;
}

int main()
{
    int arr[]={3, 5, 7, 6, 3, 9, 8};
    int x;
    cout<<"Want to solve with Naive Method: Press 1, \n Want an efficient solution: Press 2"<<endl;
    cin>>x;
    int s_largest = 0;
    switch(x){
        case 1:  s_largest = getseclargest(arr, 7);
                cout<<"Second Largest is: "<<arr[s_largest]<<"\n";break;
        case 2:  s_largest = get_second_largest(arr, 7);
                cout<<"Second Largest Using Efficient method: "<<arr[s_largest]<<"\n"<<endl;break;
        default: cout<<"Select correct key\n";
    }
}