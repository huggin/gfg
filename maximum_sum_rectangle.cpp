//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
    int solve(int R, int C, vector<int>& M) {
        int ans = M[0];
        int t = 0;
        for(int i = 0; i < R; ++i) {
            t += M[i];
            ans = max(ans, t);
            if (t < 0) {
                t = 0;
            }
        }

        return ans;
    }
  public:
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
        // code here
        vector<int> d(R);
        int ans = M[0][0];
        vector<vector<int>> M2(M);
        int k = 0;
        while(C >= 1) {
            for(int i = 0; i < C; ++i) {
                for(int j = 0; j < R; ++j) {
                    d[j] = M[j][i];
                }
                ans = max(ans, solve(R, C, d));
            }
            
            for(int j = 1; j < C; ++j) {
                for(int i = 0; i < R; ++i) {
                    M[i][j-1] += M2[i][j+k];
                }
            }
            ++k;
            --C;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(N, M, v) << "\n";
    }
}
// } Driver Code Ends
