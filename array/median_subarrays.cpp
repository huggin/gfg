//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  long long solve(int n, const vector<int> &a, int M) {
    vector<int> cnt(2 * n + 1);
    long long ans = 0, t = 0, curr = n;
    cnt[curr] = 1;
    for (int i = 0; i < n; ++i) {
      int x = a[i] >= M ? 1 : -1;
      if (x == -1)
        t -= cnt[curr - 1];
      else
        t += cnt[curr];
      curr += x;
      cnt[curr]++;
      ans += t;
    }
    return ans;
  }

public:
  long long countSubarray(int N, vector<int> A, int M) {
    // code here
    // cout << solve(N, A, M) << ' ' << solve(N, A, M+1) << endl;
    return solve(N, A, M) - solve(N, A, M + 1);
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
      cin >> A[i];
    }
    Solution obj;
    auto ans = obj.countSubarray(N, A, M);
    cout << ans << endl;
  }
}
// } Driver Code Ends
