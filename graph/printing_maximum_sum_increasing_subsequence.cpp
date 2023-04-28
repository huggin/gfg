//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
  vector<int> maxSumSequence(int N, int A[]) {
    // code here
    vector<int> dp(N);
    dp[0] = A[0];
    int ans = A[0];
    vector<int> prev(N, -1);
    int last = 0;
    for (int i = 1; i < N; ++i) {
      dp[i] = A[i];
      for (int j = 0; j < i; ++j) {
        if (A[i] > A[j]) {
          if (dp[j] + A[i] > dp[i]) {
            dp[i] = dp[j] + A[i];
            prev[i] = j;
          }
        }
      }
      if (dp[i] > ans) {
        last = i;
        ans = dp[i];
      }
      // cout << i << ' ' << dp[i] << endl;
    }
    // cout << ans << endl;
    vector<int> ret;
    while (last != -1) {
      ret.push_back(A[last]);
      last = prev[last];
    }
    reverse(ret.begin(), ret.end());
    return ret;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int N;
    cin >> N;
    ;
    int A[N];
    for (int i = 0; i < N; i++)
      cin >> A[i];

    Solution ob;
    vector<int> ans = ob.maxSumSequence(N, A);
    for (auto num : ans)
      cout << num << " ";
    cout << "\n";
  }
  return 0;
}
// } Driver Code Ends
