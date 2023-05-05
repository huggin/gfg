//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  vector<vector<int>> dp;
  int n;
  vector<int> a;

  int solve(const vector<int> &a, int k, int s) {
    if (s == 0) {
      return 1;
    }
    if (k == n) {
      return 0;
    }
    if (dp[k][s] != -1) {
      return dp[k][s];
    }
    int &ans = dp[k][s];
    ans = solve(a, k + 1, s) || (a[k] <= s) && solve(a, k + 1, s - a[k]);
    return ans;
  }

public:
  bool isSubsetSum(const vector<int> &arr, int sum) {
    // code here
    n = arr.size();
    dp.assign(n, vector<int>(sum + 1, -1));
    return solve(arr, 0, sum);
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int N, sum;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
      cin >> arr[i];
    }
    cin >> sum;

    Solution ob;
    cout << ob.isSubsetSum(arr, sum) << endl;
  }
  return 0;
}

// } Driver Code Ends
