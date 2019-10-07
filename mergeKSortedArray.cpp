#include<bits/stdc++.h>
using namespace std;
# define int_max 9999

void heapify(int **arr,int k,int i)
{
   int min=i,lc=2*i+1,rc=2*i+2;
   if(lc<k && arr[lc][0]<arr[min][0])
   	min=lc;
   if(rc<k && arr[rc][0]<arr[min][0])
   	min=rc;
   if(min!=i)
   {
   	 swap(arr[i][0],arr[min][0]);
   	 heapify(arr,k,min);
   }
}

void build_min_heap(int **arr,int k,int n)
{
	for(int i=(k-2)/2;i>=0;i--)
		heapify(arr,k,i);
}

int func(int **arr,int idx_array[],int k,int n)
{ 
	 int min=0;
	 for(int i=1;i<k;i++)
	 {
	 	if(arr[i][idx_array[i]+1]<arr[min][idx_array[min]])
	 		min=i;
	 }
	 idx_array[min]++;
	 return arr[min][idx_array[min]];

}

int *merged(int **arr,int k,int n)
{
	int m=0,mini;
    int *res=new int[k*n];

    build_min_heap(arr,k,n);

   /* for(int i=0;i<k;i++)
    	cout<<arr[i][0]<<" ";
    cout<<endl; */

    int idx_array[k];
    for(int i=0;i<k;i++)
    	idx_array[i]=0;
    for(int j=0;j<n*k;j++){
    res[m++]=arr[0][0];

    mini=func(arr,idx_array,k,n); 

    arr[0][0]=mini;

    heapify(arr,k,0);

    /*for(int i=0;i<k;i++)
    	cout<<arr[i][0]<<" ";
    cout<<endl;*/

    }
    res[m]=arr[0][0];
    return res;
    
}

int main()
{
    int k,n;cin>>k>>n;
    int **arr=new int *[k];
    for(int i=0;i<k;i++)
    	arr[i]=new int[n+2];

    for(int i=0;i<k;i++)
    	for(int j=0;j<n;j++)
    		cin>>arr[i][j];

    for(int i=0;i<k;i++){
    	arr[i][n]=int_max;
    	arr[i][n+1]=int_max;
    }

    int *res=merged(arr,k,n);

    for(int i=0;i<k*n;i++)
    	cout<<res[i]<<" ";

	return 0;
}