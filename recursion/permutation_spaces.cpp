//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  vector<string> ans;
  string s;

  void solve(int k, string &t) {
    if (k == s.size()) {
      ans.push_back(t);
      return;
    }
    if (t.back() != ' ') {
      t.push_back(' ');
      solve(k, t);
      t.pop_back();
    }
    t.push_back(s[k]);
    solve(k + 1, t);
    t.pop_back();
  }

public:
  vector<string> permutation(string S) {
    // Code Here
    s = S;
    ans.clear();
    string t(1, S[0]);
    solve(1, t);
    return ans;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    string S;
    cin >> S;
    vector<string> ans;
    Solution obj;
    ans = obj.permutation(S);
    for (int i = 0; i < ans.size(); i++) {
      cout << "(" << ans[i] << ")";
    }
    cout << endl;
  }
}

// } Driver Code Ends
