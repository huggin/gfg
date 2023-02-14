//{ Driver Code Starts
// initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  vector<pair<int, int>> v;
  vector<int> dp;

 public:
  int StackingUpDiscs(int N, int R[], int H[]) {
    // code here
    for (int i = 0; i < N; ++i) {
      v.push_back({R[i], H[i]});
    }
    sort(v.begin(), v.end());
    dp.assign(N, -1);
    int ans = v[0].second;
    dp[0] = v[0].second;
    for (int i = 1; i < N; ++i) {
      dp[i] = v[i].second;
      for (int j = 0; j < i; ++j) {
        if (v[i].first > v[j].first && v[i].second > v[j].second) {
          dp[i] = max(dp[i], dp[j] + v[i].second);
        }
      }
      ans = max(ans, dp[i]);
    }
    return ans;
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int N;
    cin >> N;
    int R[N], H[N];
    for (int i = 0; i < N; i++) cin >> R[i] >> H[i];

    Solution ob;
    cout << ob.StackingUpDiscs(N, R, H) << endl;
  }
}
// } Driver Code Ends
