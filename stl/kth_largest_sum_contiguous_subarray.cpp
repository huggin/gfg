//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
 public:
  int kthLargest(vector<int> &Arr, int N, int K) {
    int dp[101][101];
    multiset<int> s;
    for (int i = 0; i < N; ++i) {
      dp[i][i] = Arr[i];
      s.insert(Arr[i]);
    }
    for (int i = 1; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        int k = i + j;
        if (k < N) {
          dp[j][k] = dp[j][k - 1] + Arr[k];
          s.insert(dp[j][k]);
        }
      }
    }
    // cout << s.size() << endl;
    int ans = -1;
    for (auto it = s.rbegin(); it != s.rend(); ++it) {
      // cout << *it << ' ';
      if (--K == 0) {
        ans = *it;
      }
    }
    return ans;
  }
};

//{ Driver Code Starts.

int main() {
  int T;
  cin >> T;
  while (T--) {
    int N, K;
    cin >> N;
    cin >> K;
    vector<int> Arr(N);
    for (int i = 0; i < N; i++) {
      cin >> Arr[i];
    }
    Solution ob;
    int ans = ob.kthLargest(Arr, N, K);
    cout << ans << endl;
  }
  return 0;
}
// } Driver Code Ends
