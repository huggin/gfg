//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    int* k;
    int* f;
    int dp[101][101];
    int total[101][101];
    
    int solve(int i, int j) {
        if (i > j) return 0;
        if (i == j) return total[i][i];
        if (dp[i][j] != -1) return dp[i][j];
        int& ans = dp[i][j];
        ans = INT_MAX;
        for(int k = i; k <= j; ++k) {
            ans = min(ans, solve(i, k-1) + total[i][j] + solve(k+1, j));
        }
        return ans;
    }
    
    public:
    int optimalSearchTree(int keys[], int freq[], int n)
    {
        // code here
        k = keys;
        f = freq;
        memset(dp, -1, sizeof(dp));
        memset(total, 0, sizeof(total));
        for(int i = 0; i < n; ++i) {
            total[i][i] = freq[i];
        }
        for(int k = 1; k < n; ++k) {
            for(int i = 0; i + k < n; ++i) {
                total[i][i+k] = total[i][i+k-1] + freq[i+k];
            }
        }
        return solve(0, n-1);
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
        cin >> n;
        int keys[n];
        for(int i=0;i<n;i++)cin>>keys[i];
        int freq[n];
        for(int i=0;i<n;i++)cin>>freq[i];
        Solution ob;
        cout<<ob.optimalSearchTree(keys, freq, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends
