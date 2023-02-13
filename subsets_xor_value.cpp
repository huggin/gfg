//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  int dp[21][128];
  vector<int> a;
  int n;
  int k;
  int ans;

  void solve(int i, int t) {
    if (i == n) return;
    solve(i + 1, t);
    t ^= a[i];
    if (t == k) ++ans;
    solve(i + 1, t);
  }

 public:
  int subsetXOR(vector<int> arr, int N, int K) {
    // code here
    memset(dp, -1, sizeof(dp));
    a = arr;
    n = N;
    k = K;
    ans = 0;
    int t = 0;
    solve(0, t);
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
    int K;
    cin >> K;
    vector<int> v;
    for (int i = 0; i < N; i++) {
      int x;
      cin >> x;
      v.push_back(x);
    }
    Solution ob;
    cout << ob.subsetXOR(v, N, K) << endl;
  }
  return 0;
}
// } Driver Code Ends
