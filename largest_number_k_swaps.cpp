//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  string ans;
  int n;
  bool found;

  void solve(string& s, int k, int i) {
    ans = max(ans, s);
    if (k == 0 || i == n) {
      return;
    }
    auto it = max_element(s.begin() + i, s.end());
    if (it - s.begin() == i) {
      solve(s, k, i + 1);
    } else {
      for (int j = i + 1; j < n; ++j) {
        if (s[j] == *it) {
          swap(s[j], s[i]);
          solve(s, k - 1, i + 1);
          swap(s[j], s[i]);
        }
      }
    }
  }

 public:
  // Function to find the largest number after k swaps.
  string findMaximumNum(string s, int k) {
    // code here.
    ans = s;
    n = s.size();
    found = false;
    solve(s, k, 0);

    return ans;
  }
};

//{ Driver Code Starts.

int main() {
  int t, k;
  string str;

  cin >> t;
  while (t--) {
    cin >> k >> str;
    Solution ob;
    cout << ob.findMaximumNum(str, k) << endl;
  }
  return 0;
}

// } Driver Code Ends
