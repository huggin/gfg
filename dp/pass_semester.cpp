//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int Ispossible(vector<vector<int>> &arr, int n, int w, int p);

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, w, p, i, j;
    cin >> n >> w >> p;

    vector<vector<int>> arr(n);

    for (int i = 0; i < n; i++) {
      int a, b;
      cin >> a >> b;
      arr[i].push_back(a);
      arr[i].push_back(b);
    }

    int ans = Ispossible(arr, n, w, p);
    if (ans == -1) {
      cout << "NO\n";
    } else {
      cout << "YES " << ans << endl;
    }
  }
  return 0;
}
// } Driver Code Ends

vector<vector<int>> a;
pair<int, int> dp[1001][1001];

pair<int, int> solve(int k, int w) {
  if (k < 0 || w <= 0) return {0, 0};
  if (dp[k][w].first != -1) {
    return dp[k][w];
  }
  auto &ans = dp[k][w];
  ans = solve(k - 1, w);

  if (a[k][0] <= w) {
    auto temp = solve(k - 1, w - a[k][0]);
    if (ans.first < temp.first + a[k][1]) {
      ans.first = temp.first + a[k][1];
      ans.second = temp.second + a[k][0];
    }
  }
  return ans;
}

int Ispossible(vector<vector<int>> &arr, int n, int w, int p) {
  // Complete the function
  // sort(arr.begin(), arr.end());
  a = arr;
  memset(dp, -1, sizeof(dp));
  auto ans = solve(n - 1, w);
  if (ans.first < p) return -1;
  return ans.second;
}
