//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
 public:
  // Function to find sum of all possible substrings of the given string.
  long long sumSubstrings(string s) {
    // your code here
    int const mod = 1000000007;
    long long ans = 0;
    int n = s.size();
    vector<long long> dp(n);
    dp[0] = s[0] - '0';
    for (int i = 1; i < n; ++i) {
      dp[i] = (dp[i - 1] + (i + 1) * (s[i] - '0')) % mod;
    }
    for (int i = 0; i < n; ++i) {
      ans = (ans * 10 + dp[i]) % mod;
    }
    return ans;
  }
};

//{ Driver Code Starts.
int main() {
  // taking total testcases
  int t;
  cin >> t;
  while (t--) {
    // taking string
    string s;
    cin >> s;
    Solution ob;
    // calling sumSubstrings() function
    cout << ob.sumSubstrings(s) << endl;
  }
  return 0;
}

// } Driver Code Ends
