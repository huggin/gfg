//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std; 
int binarySearch(int arr[], int low, int high);
int main()
{
	int test =0; 
	cin>>test;
	while(test--)
	{
	    int n, i; 
	    cin>>n; 
	    int a[n]; 
	    for(i=0; i<n; i++)
	    cin>>a[i]; 
	    
	    cout<<binarySearch(a, 0, n-1)<<endl; 
	    
	   // cout<<"\n\n"; 
	}
	
}

// } Driver Code Ends


int binarySearch(int arr[], int low, int high)
{
      //add code here.
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == mid) return mid;
        else if (arr[mid] > mid) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}
