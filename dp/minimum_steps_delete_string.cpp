//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  int n;
  int m[1001][1001];
  string s;

  int solve(int i, int j) {
    // cout << i << ' ' << j << endl;
    if (i == j)
      return 1;
    if (m[i][j] != -1)
      return m[i][j];

    m[i][j] = n;
    for (int k = i; k < j; ++k) {
      m[i][j] = min(m[i][j], solve(i, k) + solve(k + 1, j));
    }
    if (s[i] == s[j]) {
      if (i + 1 == j)
        return m[i][j] = 1;
      return m[i][j] = min(m[i][j], solve(i + 1, j - 1));
    }
    // cout << i << ' ' << j << ' ' << m[i][j] << endl;
    return m[i][j];
  }

public:
  int minStepToDeleteString(string S) {
    // Your code goes here
    s = S;
    n = s.size();
    memset(m, -1, sizeof(m));
    return solve(0, n - 1);
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
    cout << ob.minStepToDeleteString(s) << "\n";
  }
  return 0;
}
// } Driver Code Ends
