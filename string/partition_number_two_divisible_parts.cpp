//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
 public:
  string stringPartition(string S, int a, int b) {
    // code here
    int n = S.size();
    if (n < 2) return "-1";
    int n1 = (S[0] - '0') % a, n2 = 0;

    vector<int> dp(n);
    int k = 1;
    for (int i = n - 1; i >= 1; --i) {
      int t = k * (S[i] - '0') % b;
      n2 += t % b;
      dp[i] = t;
      k = k * 10 % b;
    }
    if (n1 == 0 && n2 == 0) {
      return S.substr(0, 1) + " " + S.substr(1);
    }
    int pos = 2;
    for (int i = 1; i < n; ++i, ++pos) {
      n1 = (n1 * 10 + (S[i] - '0')) % a;
      n2 = (n2 + b - dp[i]) % b;
      // cout << n1 << ' ' << n2 << endl;
      if (n1 == 0 && n2 == 0) {
        if (pos == S.size()) return "-1";
        return S.substr(0, pos) + " " + S.substr(pos);
      }
    }
    return "-1";
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    string S;
    cin >> S >> a >> b;
    Solution ob;
    cout << ob.stringPartition(S, a, b) << endl;
  }
  return 0;
}
// } Driver Code Ends
