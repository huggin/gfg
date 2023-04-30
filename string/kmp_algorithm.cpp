//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
  vector<int> search(string pat, string txt) {
    // code hee.
    int m = pat.size();
    vector<vector<int>> dfa(m, vector<int>(256));
    dfa[0][pat[0]] = 1;
    for (int x = 0, j = 1; j < m; ++j) {
      for (int c = 0; c < 256; ++c) {
        dfa[j][c] = dfa[x][c];
      }
      dfa[j][pat[j]] = j + 1;
      x = dfa[x][pat[j]];
    }

    int n = txt.size();
    vector<int> ans;
    int j = 0;
    int i = 0;
    while (i < n) {
      j = dfa[j][txt[i++]];

      if (j == m) {
        ans.push_back(i - m + 1);
        j = 0;
        i = i - m + 1;
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
    string S, pat;
    cin >> S >> pat;
    Solution ob;
    vector<int> res = ob.search(pat, S);
    if (res.size() == 0)
      cout << -1 << endl;
    else {
      for (int i : res)
        cout << i << " ";
      cout << endl;
    }
  }
  return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends
