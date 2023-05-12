//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  vector<vector<int>> ans;

  void go(int k, int m, vector<int> &c) {
    if (k == 0) {
      ans.push_back(c);
      return;
    }
    for (int i = m; i > 0; --i) {
      c.push_back(i);
      go(k - i, min(i, k - i), c);
      c.pop_back();
    }
  }

public:
  vector<vector<int>> UniquePartitions(int n) {
    // Code here
    ans.clear();
    vector<int> c;
    go(n, n, c);
    return ans;
  }
};

//{ Driver Code Starts.
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    Solution ob;
    vector<vector<int>> ans = ob.UniquePartitions(n);
    for (auto i : ans)
      for (auto j : i)
        cout << j << " ";
    cout << "\n";
  }
  return 0;
}
// } Driver Code Ends
