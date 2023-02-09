//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    int dp[1001][1001];
public:
    int nCr(int n, int r){
        // code here
        if (r > n) return 0;
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for(int i = 1; i <= n; ++i) {
            dp[i][0] = 1;
            dp[i][i] = 1;
            for(int j = 1; j < i; ++j) {
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % 1000000007;
            }
        }
        return dp[n][r];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends
