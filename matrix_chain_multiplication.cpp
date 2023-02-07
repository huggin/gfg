//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    int dp[101][101];
    int n;
    int* a;
    
    int solve(int i, int j) {
        if (i > j) return 0;
        if (i == j) return dp[i][j] = a[i] * a[i-1] * a[i+1];
        if (dp[i][j] != -1) return dp[i][j];
        int& ans = dp[i][j];
        ans = INT_MAX;
        for(int k = i; k<=j; ++k) {
            ans = min(ans, a[i-1] * a[k] * a[j+1] + solve(i, k-1) + solve(k+1, j));
        }
        return ans;
    }
public:
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        n = N;
        memset(dp, -1, sizeof(dp));
        a = arr;
        return solve(1, N-2);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends
