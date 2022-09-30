#include<iostream>



int search(int arr[],int s,int e, int ele)
{
	if(s>e)
		return -1;
	int mid=(s+e)/2;
	if(arr[mid]==ele)
			return mid;
	else if(ele>arr[mid])
		search(arr,mid+1,e,ele);
	else
		search(arr,s,mid-1,ele);  		
}
int main()
{
	int i,n,ele,add,s=0,e;
	printf("Enter the number of element");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the array");
	for (i=0;i<n;i++)
		scanf("%d",&arr[i]);
	
	printf("Enter the element to search");
	scanf("%d",&ele);
	 
	add=search(arr,s,n-1,ele);
	
	if(add!=-1)
		printf("element found at position %d",add+1);
	else
		printf("element not found ! ");
	    
}
