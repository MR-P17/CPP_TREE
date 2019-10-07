#include<bits/stdc++.h>
using namespace std;
void swap(int arr[],int a,int b)
{
	int tmp=arr[a];
	arr[a]=arr[b];
	arr[b]=tmp;
}
void move_down(int arr[],int n,int i)
{
	int max=i;
	int parent=(i-1)/2;
	int lc=2*i+1;
	int rc=2*i+2;

	if(lc<n && arr[lc]>arr[max])
		max=lc;
	if(rc<n && arr[rc]>arr[max])
		max=rc;

	if(max!=i)
	{
		swap(arr,i,max);
		move_down(arr,n,max);
	}
}
void build_binary_heap(int arr[],int n)
{
	int start=(n-2)/2;
	for(int i=start;i>=0;i--)
		move_down(arr,n,i);
}
int main()
{
    int arr[]={4,20,25,17,7,10,11,35,54,51};
    int n=sizeof(arr)/sizeof(arr[0]);

    build_binary_heap(arr,n);

    for(int i=0;i<n;i++)
    	cout<<arr[i]<<" ";
	return 0;
}