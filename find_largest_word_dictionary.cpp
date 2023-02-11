//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
 public:
  bool ok(const string& s, const string& p) {
    int k = 0;
    for (int i = 0; i < s.size() && k < p.size(); ++i) {
      if (s[i] == p[k]) {
        ++k;
      }
    }
    if (k == p.size()) return true;
    return false;
  }

 public:
  string findLongestWord(string S, vector<string> d) {
    // code here
    string ans;
    int len = 0;
    for (int i = 0; i < d.size(); ++i) {
      if (ok(S, d[i])) {
        if (len < d[i].size() || len == d[i].size() && ans > d[i]) {
          len = d[i].size();
          ans = d[i];
        }
      }
    }
    return ans;
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<string> d(n + 1);
    for (int i = 0; i < n; i++) cin >> d[i];
    string S;
    cin >> S;
    Solution ob;
    cout << ob.findLongestWord(S, d) << endl;
  }
  return 0;
}

// } Driver Code Ends
