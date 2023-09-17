//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

const int MAX = 1000001;

class Solution {
  vector<vector<int>> g;
  vector<int> pa;
  vector<int> pb;
  vector<int> was;
  int round;

  bool dfs(int v) {
    was[v] = round;
    for (int w : g[v]) {
      if (pb[w] == -1) {
        pa[v] = w;
        pb[w] = v;
        return true;
      }
    }
    for (int w : g[v]) {
      if (was[pb[w]] != round) {
        if (dfs(pb[w])) {
          pa[v] = w;
          pb[w] = v;
          return true;
        }
      }
    }
    return false;
  };

public:
  int MaxmimumLength(const vector<vector<int>> &nums) {
    // Code here
    int n = nums.size();
    int left = MAX, right = 0;
    g.assign(MAX, vector<int>{});
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 6; j++) {
        g[nums[i][j]].push_back(i);
        left = min(left, nums[i][j]);
        right = max(right, nums[i][j]);
      }
    }
    pa.assign(MAX, -1);
    pb.assign(n, -1);
    was.assign(MAX, -1);
    round = 1;

    int ans = 0;
    int r = 0;
    for (int l = left; l <= right; l++) {
      r = max(r, l - 1);
      while (dfs(r + 1)) {
        r++;
        round++;
      }
      ans = max(ans, r - l + 1);
      if (pa[l] != -1) {
        pb[pa[l]] = -1;
        pa[l] = -1;
      }
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
    vector<vector<int>> nums(n, vector<int>(6, 0));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 6; j++)
        cin >> nums[i][j];
    }
    Solution obj;
    int ans = obj.MaxmimumLength(nums);
    cout << ans << "\n";
  }
  return 0;
}

// } Driver Code Ends
