//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  int solve(const string& s) {
    int n = s.size();
    vector<int> dp(n + 1);
    dp[0] = 1;
    unordered_map<int, int> last_index;
    for (int i = 0; i < n; ++i) {
      dp[i + 1] = dp[i] * 2;
      if (last_index.find(s[i]) != last_index.end()) {
        dp[i + 1] = dp[i + 1] - dp[last_index[s[i]]];
      }
      last_index[s[i]] = i;
    }
    return dp[n];
  }

 public:
  string betterString(string str1, string str2) {
    // code here
    int n1 = solve(str1);
    int n2 = solve(str2);
    // cout << n1 << ' ' << n2 << endl;
    if (n1 >= n2) return str1;
    return str2;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    string str1, str2;
    cin >> str1 >> str2;
    Solution obj;
    string ans = obj.betterString(str1, str2);
    cout << ans << "\n";
  }
}

// } Driver Code Ends
