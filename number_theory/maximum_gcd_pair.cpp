//{ Driver Code Starts
// Initial template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
  int MaxGcd(int n, int a[]) {
    // complete the function here
    int ma = *max_element(a, a + n);
    vector<int> dp(ma + 1);

    int ans = 1;
    for (int i = 0; i < n; ++i) {
      if (++dp[a[i]] > 1)
        ans = max(ans, a[i]);
    }

    for (int i = 2; i <= n; ++i) {
      if (dp[i]) {
        for (int j = i + i; j <= n; j += i) {
          if (dp[j]) {
            ans = max(ans, i);
          }
        }
      }
    }
    return ans;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
      cin >> a[i];
    Solution ob;
    cout << ob.MaxGcd(n, a) << endl;
  }
  return 0;
}

// } Driver Code Ends
