//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  string s;
  vector<string> vs;
  int N;
  vector<int> marked;
  int K;

  void solve(int i, int k) {
    if (i == N) {
      vs.push_back(s);
      return;
    }
    for (int j = 0; j < k; ++j) {
      s.push_back(j + '0');
      solve(i + 1, k);
      s.pop_back();
    }
  }

  bool dfs(string &t, int k) {
    if (k == vs.size())
      return true;

    for (int j = 0; j < vs.size(); ++j) {
      if (!marked[j]) {
        if (neighbour(t.substr(t.size() - N), vs[j])) {
          t += vs[j][N - 1];
          marked[j] = 1;
          if (dfs(t, k + 1))
            return true;
          marked[j] = 0;
          t.pop_back();
        }
      }
    }
    return false;
  }

  bool neighbour(const string &s1, const string &s2) {
    for (int i = 1; i < N; ++i) {
      if (s1[i] != s2[i - 1])
        return false;
    }
    return true;
  }

public:
  string findString(int n, int k) {
    // code here
    N = n;
    solve(0, k);
    marked.assign(vs.size(), 0);
    K = k;
    string t(N, '0');
    marked[0] = 1;
    dfs(t, 1);

    return t;
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int N, K;
    cin >> N >> K;
    Solution ob;
    string ans = ob.findString(N, K);
    int ok = 1;
    for (auto i : ans) {
      if (i < '0' || i > K - 1 + '0')
        ok = 0;
    }
    if (!ok) {
      cout << -1 << endl;
      continue;
    }
    unordered_set<string> st;
    for (int i = 0; i + N - 1 < ans.size(); i++) {
      st.insert(ans.substr(i, N));
    }
    int tot = 1;
    for (int i = 1; i <= N; i++)
      tot *= K;
    if (st.size() == tot) {
      cout << ans.size() << endl;
    } else {
      cout << -1 << endl;
    }
  }
  return 0;
}
// } Driver Code Ends
