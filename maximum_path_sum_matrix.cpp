//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        vector<vector<int>> dp(N, vector<int>(N));
        copy(Matrix[0].begin(), Matrix[0].end(), dp[0].begin());
        for(int i = 1; i < N; ++i) {
            for(int j = 0; j < N; ++j) {
                dp[i][j] = dp[i-1][j];
                if (j - 1 >= 0) {
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1]);
                }
                if (j + 1 < N) {
                    dp[i][j] = max(dp[i][j], dp[i-1][j+1]);
                }
                dp[i][j] += Matrix[i][j];
            }
        }
        return *max_element(dp[N-1].begin(), dp[N-1].end());
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
