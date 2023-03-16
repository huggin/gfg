//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
 public:
  int distinctSubsequences(string s) {
    // Your code goes here
    int n = s.size();
    const int mod = 1e9 + 7;
    vector<int> dp(n + 1);
    dp[0] = 1;
    unordered_map<int, int> last_index;
    for (int i = 0; i < n; ++i) {
      dp[i + 1] = (dp[i] * 2) % mod;
      if (last_index.find(s[i]) != last_index.end()) {
        dp[i + 1] = (dp[i + 1] + mod - dp[last_index[s[i]]]) % mod;
      }
      last_index[s[i]] = i;
    }
    return dp[n];
  }
};

//{ Driver Code Starts.

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;

    Solution ob;
    cout << ob.distinctSubsequences(s) << "\n";
  }

  return 0;
}
// } Driver Code Ends
