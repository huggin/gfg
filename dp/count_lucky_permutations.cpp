//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
  long long int luckyPermutations(int N, int M, vector<int> arr,
                                  vector<vector<int>> graph) {
    // Code here
    vector<vector<int>> g(N, vector<int>(N));
    for (auto e : graph) {
      g[e[0] - 1][e[1] - 1] = 1;
      g[e[1] - 1][e[0] - 1] = 1;
    }

    vector<vector<long long>> dp(N, vector<long long>(1 << N));
    for (int i = 0; i < N; ++i) {
      dp[i][1 << i] = 1;
    }

    for (int mask = 0; mask < (1 << N); ++mask) {
      for (int j = 0; j < N; ++j) {
        for (int i = 0; i < N; ++i) {
          if (!g[arr[i] - 1][arr[j] - 1])
            continue;

          if (dp[i][mask] == 0)
            continue;
          if ((mask & (1 << j)) == 0) {
            dp[j][mask | (1 << j)] += dp[i][mask];
          }
        }
      }
    }

    long long ans = 0;
    for (int i = 0; i < N; ++i) {
      ans += dp[i][(1 << N) - 1];
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
    vector<int> arr(N);
    vector<vector<int>> graph(M, vector<int>(2));
    for (int i = 0; i < N; i++) {
      cin >> arr[i];
    }
    for (int i = 0; i < M; i++) {
      for (int j = 0; j < 2; j++) {
        cin >> graph[i][j];
      }
    }
    Solution obj;
    cout << obj.luckyPermutations(N, M, arr, graph) << endl;
  }
}

// } Driver Code Ends
