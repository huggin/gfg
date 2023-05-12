//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  int solve(const string &s, int k, int used) {
    if (k == 0)
      return 1;
    if (!used && k % 2 == 1 &&
        s.substr(0, (k + 1) / 2) == s.substr((k + 1) / 2, (k + 1) / 2)) {
      return 1 + solve(s, k / 2, 1);
    }
    return 1 + solve(s, k - 1, used);
  }

public:
  int minOperation(string s) {
    // code here
    return solve(s, s.size() - 1, 0);
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
    cout << ob.minOperation(s) << "\n";
  }
  return 0;
}

// } Driver Code Ends
