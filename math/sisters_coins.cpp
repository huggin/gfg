//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends

class Solution {
 public:
  int sisterCoin(int arr[], int n, int m) {
    // Code Here
    int t = accumulate(arr, arr + n, 0);
    if (t < m || (t - m) % 2 == 1) return 0;
    int need = (t - m) / 2;
    vector<int> dp(need + 1);
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
      for (int j = need; j >= 0; --j) {
        if (j - arr[i] >= 0 && dp[j - arr[i]] == 1) {
          dp[j] = 1;
        }
      }
    }

    if (dp[need] == 1) return 1;
    return 0;
  }
};

//{ Driver Code Starts.

int main() {
  Solution ob;
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    cout << ob.sisterCoin(a, n, m) << endl;
  }
  return 0;
}
// } Driver Code Ends
