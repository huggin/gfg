//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
 public:
  long long solve(int N, int K, vector<long long> GeekNum) {
    // code here
    vector<long long> dp;
    long long total = 0;
    for (int i = 0; i < K; ++i) {
      dp.push_back(GeekNum[i]);
      total += GeekNum[i];
    }
    for (int i = K; i < N; ++i) {
      dp.push_back(total);
      total += dp[i] - dp[i - K];
    }
    return dp[N - 1];
  }
};

//{ Driver Code Starts.

int main() {
  int T;
  cin >> T;
  while (T--) {
    int N, K;
    cin >> N >> K;

    vector<long long> GeekNum(K);

    for (int i = 0; i < K; i++) cin >> GeekNum[i];

    Solution ob;
    cout << ob.solve(N, K, GeekNum) << "\n";
  }
  return 0;
}

// } Driver Code Ends
