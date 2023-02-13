//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    int minCost(int N, vector<int> cost[]) {
        // code here
        vector<vector<int>> dp(3, vector<int>(N));
        dp[0][0] = cost[0][0];
        dp[1][0] = cost[0][1];
        dp[2][0] = cost[0][2];
        
        for(int i = 1; i < N; ++i) {
            for(int j = 0; j < 3; ++j) {
                dp[j][i] = min(dp[(j+1)%3][i-1], dp[(j+2)%3][i-1]) + cost[i][j];
            }
        }
        int ans = INT_MAX;
        for(int i = 0; i < 3; ++i) {
            ans = min(ans, dp[i][N-1]);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> cost[N];
        int x, y, z;
        for(int i = 0;i < N;i++){
            cin>>x>>y>>z;
            cost[i].push_back(x);
            cost[i].push_back(y);
            cost[i].push_back(z);
        }
        
        Solution ob;
        cout<<ob.minCost(N, cost)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
