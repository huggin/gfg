//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int cuts(string s);

int main() {
  int t;
  cin >> t;
  string s;
  while (t--) {
    cin >> s;
    cout << cuts(s) << endl;
  }

  return 0;
}

// } Driver Code Ends

string S;
vector<int> dp;
int n;

int ok(int i, int j) {
  if (S[i] == '0') return 0;
  long long t = 0;
  for (int k = i; k <= j; ++k) {
    t = t * 2 + (S[k] - '0');
  }
  if (t == 1) return 1;
  if (t % 5 != 0) return 0;
  while (t % 5 == 0) {
    t /= 5;
  }
  return t == 1;
}

int solve(int k) {
  if (k == n) return 0;
  if (dp[k] != -1) return dp[k];
  int& ans = dp[k];
  ans = 100;
  for (int i = k; i < n; ++i) {
    if (ok(k, i)) {
      ans = min(ans, 1 + solve(i + 1));
    }
  }
  return ans;
}

int cuts(string s) {
  // code
  S = s;
  n = s.size();
  dp.assign(n, -1);
  int ans = solve(0);
  return ans >= 100 ? -1 : ans;
}
