//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  vector<int> all;
  bool dfs(int k, vector<int> &arr, vector<int> &marked, vector<int> &safe) {
    marked[k] = 1;
    all.push_back(k);
    if (arr[k] == 0) {
      return false;
    }
    if (k + arr[k] < 0 || k + arr[k] >= arr.size())
      return true;
    if (!marked[k + arr[k]]) {
      return dfs(k + arr[k], arr, marked, safe);
    } else if (!safe[k + arr[k]]) {
      return false;
    }
    return true;
  }

public:
  int goodStones(int n, vector<int> &arr) {
    // Code here
    vector<int> marked(n);
    vector<int> safe(n);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      if (!marked[i]) {
        all.clear();
        bool f = dfs(i, arr, marked, safe);
        if (f) {
          ans += all.size();
          for (auto c : all) {
            safe[c] = 1;
          }
        }
        // cout << i << ' ' << ans << ' ' << f << endl;
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
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    Solution ob;
    cout << ob.goodStones(n, arr) << endl;
  }
  return 0;
}
// } Driver Code Ends
