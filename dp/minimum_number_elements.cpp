//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  vector<map<int, map<int, int>>> dp;
  int* a;

  int solve(int k, int mi, int ma) {
    if (k < 0) return 0;
    if (dp[k].find(mi) != dp[k].end() &&
        dp[k][mi].find(ma) != dp[k][mi].end()) {
      return dp[k][mi][ma];
    }
    int& ans = dp[k][mi][ma];
    ans = solve(k - 1, mi, ma) + 1;
    if (a[k] < ma) {
      ans = min(ans, solve(k - 1, mi, a[k]));
    }
    if (a[k] > mi) {
      ans = min(ans, solve(k - 1, a[k], ma));
    }
    return ans;
  }

 public:
  int minCount(int arr[], int N) {
    // Your code goes here
    a = arr;
    dp.clear();
    dp.resize(N);

    return min({solve(N - 2, INT_MIN, arr[N - 1]),
                solve(N - 2, arr[N - 1], INT_MAX),
                1 + solve(N - 2, INT_MIN, INT_MAX)});
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

    for (int i = 0; i < n; i++) cin >> a[i];

    Solution ob;
    cout << ob.minCount(a, n) << "\n";
  }
  return 0;
}

// } Driver Code Ends
