//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
 public:
  int lenOfLongSubarr(int A[], int N, int K) {
    // Complete the function
    int ans = 0;
    unordered_map<int, int> m;
    int total = 0;
    for (int i = 0; i < N; ++i) {
      total += A[i];
      if (total == K) ans = max(ans, i + 1);
      if (m.find(total) == m.end()) {
        m[total] = i;
      }
      if (m.find(total - K) != m.end()) {
        // cout << m[total-K] << ' ' << i << endl;
        ans = max(ans, i - m[total - K]);
      }
    }
    return ans;
  }
};

//{ Driver Code Starts.

int main() {
  // code

  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    int a[n];

    for (int i = 0; i < n; i++) cin >> a[i];
    Solution ob;
    cout << ob.lenOfLongSubarr(a, n, k) << endl;
  }

  return 0;
}
// } Driver Code Ends
