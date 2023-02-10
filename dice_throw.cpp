//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
    long long dp[51][51];
    long long solve(int M, int N, int X) {
        if (X == 0 && N == 0) return 1;
        if (X < 0) return 0;
        if (N > 0 && X <= 0) return 0;
        if (N <= 0 && X > 0) return 0;
        if (dp[N][X] != -1) return dp[N][X];
        long long& ans = dp[N][X];
        ans = 0;
        for(int i = 1; i <= M; ++i) {
            ans += solve(M, N-1, X-i);
        }
        //cout << N << ' ' << X << ' ' << ans << endl;
        return ans;
    }
  public:
    long long noOfWays(int M , int N , int X) {
        // code here
        memset(dp, -1, sizeof(dp));
        return solve(M, N, X);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int M,N,X;
        
        cin>>M>>N>>X;

        Solution ob;
        cout << ob.noOfWays(M,N,X) << endl;
    }
    return 0;
}
// } Driver Code Ends
