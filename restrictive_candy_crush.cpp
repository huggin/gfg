//{ Driver Code Starts
#include <bits/stdc++.h>

#include <iostream>
using namespace std;

// } Driver Code Ends
class Solution {
  bool ok(const string& ans, int k, char c) {
    for (int i = ans.size() - 1; i >= 0 && k > 0; --i) {
      if (ans[i] != c) return false;
      --k;
    }
    return k == 0;
  }

 public:
  string Reduced_String(int k, string s) {
    // Your code goes here
    if (k == 1) return "";
    string ans;
    ans.reserve(s.size());
    for (auto c : s) {
      if (ans.empty()) {
        ans.push_back(c);
      } else {
        if (ok(ans, k - 1, c)) {
          ans.resize(ans.size() - (k - 1));
        } else {
          ans.push_back(c);
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
    int k;
    cin >> k;
    string s;
    cin >> s;
    Solution obj;
    cout << obj.Reduced_String(k, s) << "\n";
  }

  return 0;
}
// } Driver Code Ends
