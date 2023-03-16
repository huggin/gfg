//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
 public:
  int pyramidForm(int a[], int N) {
    // code here
    vector<int> dp(N, 1), dp2(N, 1);
    int start = 1;
    for (int i = 1; i < N; ++i) {
      if (a[i] >= start + 1) {
        dp[i] = start + 1;
        ++start;
      } else {
        dp[i] = a[i];
        start = a[i];
      }
    }
    start = 1;
    for (int i = N - 2; i >= 0; --i) {
      if (a[i] >= start + 1) {
        dp2[i] = start + 1;
        ++start;
      } else {
        dp2[i] = a[i];
        start = a[i];
      }
    }

    int height = 0;
    for (int i = 0; i < N; ++i) {
      height = max(height, min(dp[i], dp2[i]));
    }

    int ans = 0;
    for (int i = 0; i < height; ++i) {
      ans += 2 * i;
    }
    ans += height;
    return accumulate(a, a + N, 0) - ans;
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int N;

    cin >> N;
    int a[N];

    for (int i = 0; i < N; i++) cin >> a[i];

    Solution ob;
    cout << ob.pyramidForm(a, N) << endl;
  }
  return 0;
}
// } Driver Code Ends
