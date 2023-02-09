//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
    int mem[501][201][2];
    int n;
    int *p;
    
    int dp2(int k, int i) {
        if (i >= n || k == 0) {
            return 0;
        }
        if (mem[i][k][1] != -1) {
            return mem[i][k][1];
        }
        int &ans = mem[i][k][1];
        ans = 0;
        for(int j=i; j<n; ++j) {
            if (p[j] > p[i-1]) {
                ans = max(ans, dp(k-1, j+1) + p[j]);
            }
        }
        return ans;
    }
    
    int dp(int k, int i) {
        if (i >= n || k == 0) {
            return 0;
        }
        if (mem[i][k][0] != -1) {
            return mem[i][k][0];
        }
        int& ans = mem[i][k][0];
        ans = dp2(k, i+1) - p[i];
        ans = max(ans, dp(k, i+1));
        return ans;
    }
  public:
    int maxProfit(int K, int N, int A[]) {
        // code here
        memset(mem, -1, sizeof(mem));
        p = A;
        n = N;
        
        return dp(K, 0);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends
