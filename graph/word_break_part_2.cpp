//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  vector<string> ans;
  string S;
  int N;
  vector<string> vs;
  bool solve(int k, vector<string>& dict) {
    if (k == S.size()) {
      string t;
      for (int i = 0; i < vs.size() - 1; ++i) {
        t += vs[i] + ' ';
      }
      t += vs[vs.size() - 1];
      ans.push_back(t);
      return true;
    }
    for (int i = 0; i < N; ++i) {
      auto it = S.find(dict[i], k);
      if (it == k) {
        vs.push_back(dict[i]);
        solve(k + dict[i].size(), dict);
        vs.pop_back();
      }
    }
    return false;
  }

 public:
  vector<string> wordBreak(int n, vector<string>& dict, string s) {
    // code here
    ans.clear();
    S = s;
    N = n;
    vs.clear();
    solve(0, dict);
    return ans;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    vector<string> dict;
    string s;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> s;
      dict.push_back(s);
    }
    cin >> s;

    Solution ob;
    vector<string> ans = ob.wordBreak(n, dict, s);
    if (ans.size() == 0)
      cout << "Empty\n";
    else {
      sort(ans.begin(), ans.end());
      for (int i = 0; i < ans.size(); i++) cout << "(" << ans[i] << ")";
      cout << endl;
    }
  }
  return 0;
}
// } Driver Code Ends
