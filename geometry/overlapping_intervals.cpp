//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  int in(vector<int> &v1, vector<int> &v2) {
    if (v1[0] >= v2[0] && v1[0] <= v2[1] || v1[1] >= v2[0] && v1[1] <= v2[1] ||
        v2[0] >= v1[0] && v2[0] <= v1[1] || v2[1] >= v1[0] && v2[1] <= v1[1])
      return 1;
    return 0;
  }

public:
  vector<vector<int>> overlappedInterval(vector<vector<int>> &intervals) {
    // Code here
    vector<vector<int>> ans;
    sort(intervals.begin(), intervals.end());
    for (int i = 0; i < intervals.size(); ++i) {
      if (ans.size() == 0) {
        ans.push_back(intervals[i]);
        continue;
      }
      vector<int> c(intervals[i]);
      while (ans.size() > 0 && in(ans[ans.size() - 1], c)) {
        c[0] = min(c[0], ans[ans.size() - 1][0]);
        c[1] = max(c[1], ans[ans.size() - 1][1]);
        ans.pop_back();
      }
      ans.push_back(c);
    }
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
    vector<vector<int>> Intervals(n);
    for (int i = 0; i < n; i++) {
      int x, y;
      cin >> x >> y;
      Intervals[i].push_back(x);
      Intervals[i].push_back(y);
    }
    Solution obj;
    vector<vector<int>> ans = obj.overlappedInterval(Intervals);
    for (auto i : ans) {
      for (auto j : i) {
        cout << j << " ";
      }
    }
    cout << "\n";
  }
  return 0;
}
// } Driver Code Ends
