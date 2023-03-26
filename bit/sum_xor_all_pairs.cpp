//{ Driver Code Starts
// An efficient C++ program to compute 
// sum of bitwise OR of all pairs
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution{
    public:
    // Returns sum of bitwise OR
    // of all pairs
    long long int sumXOR(int arr[], int n)
    {
    	//Complete the function
    	vector<int> cnt(18);
    	for(int i = 0; i < n; ++i) {
    	    for(int j = 0; j < 18; ++j) {
    	        if (arr[i] & (1<<j)) {
    	            cnt[j]++;
    	        }
    	    }
    	}
    	long long ans = 0;
    	for(int i = 0, k = 1; i < 18; ++i, k *= 2) {
    	    ans += 1LL * cnt[i] * (n - cnt[i]) * k;
    	}
    	return ans;
    }
};

//{ Driver Code Starts.


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	 int n ;
	 cin>>n;
	 int arr[n+1];
	 for( int i=0;i<n;i++)
	    cin>>arr[i];
	 Solution ob;
	 cout<<ob.sumXOR(arr, n)<<endl;
	}	
	return 0;
}

// } Driver Code Ends
