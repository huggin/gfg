//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  vector<int> dp;
  int n;

  int solve(const string& s, int k) {
    if (k == n) return 0;
    if (k == n - 1) return 1;
    if (dp[k] != -1) return dp[k];
    int& ans = dp[k];

    ans = 1 + solve(s, k + 1);
    if (s[k] == s[k + 1]) {
      ans = max(ans, 3 + solve(s, k + 2));
    } else {
      ans = max(ans, 4 + solve(s, k + 2));
    }
    return ans;
  }

 public:
  int getMaxWeight(string s) {
    // Your code goes here
    n = s.size();
    dp.assign(n, -1);
    return solve(s, 0);
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;

    Solution ob;
    cout << ob.getMaxWeight(s);
    ;
    cout << "\n";
  }
  return 0;
}

// } Driver Code Ends
