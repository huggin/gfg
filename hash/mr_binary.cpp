//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
 public:
  int maximum_index(string s) {
    // Code here
    int n = s.size();
    unordered_map<char, int> mi, ma;
    ma['a'] = 0;
    mi['a'] = 0;
    char curr = 'a';
    for (int i = 1; i < n; ++i) {
      ma[s[i]] = i;
      if (s[i] == curr + 1) {
        mi[s[i]] = i;
        ++curr;
      }
    }

    char c = s[0];
    int ans = ma[c];
    for (char i = c + 1; i <= 'z'; ++i) {
      if (ma.find(i) == ma.end() || mi[i - 1] > ma[i]) {
        return ans;
      }
      // cout << i << ' ' << mi[i] << ' ' << ma[i] << endl;
      ans = max(ans, ma[i]);
    }
    return ans;
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
    int ans = ob.maximum_index(s);
    cout << ans << "\n";
  }
  return 0;
}

// } Driver Code Ends
