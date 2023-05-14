//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  vector<vector<int>> ans;

  void solve(const vector<int> &a, int i, int n, int k, vector<int> &curr) {
    if (k == 0) {
      if (ans.size() == 0 || ans.back() != curr)
        ans.push_back(curr);
      return;
    }
    if (i == n || k < 0) {
      return;
    }
    curr.push_back(a[i]);
    solve(a, i + 1, n, k - a[i], curr);
    curr.pop_back();
    int j = i + 1;
    while (j < n && a[j] == a[i])
      ++j;
    solve(a, j, n, k, curr);
  }

public:
  vector<vector<int>> CombinationSum2(vector<int> arr, int n, int k) {
    // code here
    ans.clear();
    sort(arr.begin(), arr.end());
    vector<int> curr;
    solve(arr, 0, n, k, curr);
    return ans;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    Solution ob;
    auto obj = ob.CombinationSum2(arr, n, k);
    for (int i = 0; i < obj.size(); i++) {
      for (int j = 0; j < obj[i].size(); j++) {
        cout << obj[i][j] << " ";
      }
      cout << "\n";
    }
    if (obj.size() == 0)
      cout << "\n";
  }
  return 0;
}
// } Driver Code Ends
