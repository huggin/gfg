//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

long long dp[1001][1001];
long long dp2[1001][1001];
    
//Function to find the maximum possible amount of money we can win.
class Solution{
   
    int *a;
    long long solve(int i, int j) {
        if (i > j) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        long long& ans = dp[i][j];
        ans = max(a[i] - solve2(i+1, j), a[j] - solve2(i, j-1));
        return ans;
    }
    
    long long solve2(int i, int j) {
        if (i == j) return a[i];
        if (dp[i][j] != -1) return dp[i][j];
        long long& ans = dp[i][j];
        ans = max(a[i] - solve(i+1, j), a[j] - solve(i, j-1));
        return ans;
    }
    
    
    public:
    long long maximumAmount(int arr[], int n){
        // Your code here
        memset(dp, -1, sizeof(dp));
        memset(dp2, -1, sizeof(dp2));
        a = arr;
        long long ans = solve(0, n-1);
        long long total = accumulate(arr, arr+n, 0LL);
        
        return (total - ans) / 2 + ans;
    }
};

//{ Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(a,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends
