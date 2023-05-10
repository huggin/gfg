//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  vector<int> parent;
  vector<int> count;

  int find(int i) {
    while (parent[i] != i) {
      parent[i] = parent[parent[i]];
      i = parent[i];
    }
    return i;
  }

  void join(int i, int j) {
    int pi = find(i);
    int pj = find(j);
    if (count[pi] < count[pj]) {
      parent[pi] = pj;
      count[pj] += count[pi];
    } else {
      parent[pj] = pi;
      count[pi] += count[pj];
    }
  }

public:
  vector<string> avoidExplosion(vector<vector<int>> mix, int n,
                                vector<vector<int>> danger, int m) {
    vector<string> ans;

    parent.assign(n, 0);
    for (int i = 0; i < n; ++i) {
      parent[i] = i;
    }
    count.assign(n, 1);

    for (auto &m : mix) {
      vector<int> dp(parent);
      vector<int> dc(count);
      join(m[0] - 1, m[1] - 1);
      bool f = true;
      for (auto &d : danger) {
        if (find(d[0] - 1) == find(d[1] - 1)) {
          ans.emplace_back("No");
          f = false;
          break;
        }
      }
      if (f) {
        ans.emplace_back("Yes");
      } else {
        parent = dp;
        count = dc;
      }
    }
    return ans;
  }
};

//{ Driver Code Starts.

int main() {
  int tt;
  cin >> tt;
  Solution sol;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mix(n, vector<int>(2));
    vector<vector<int>> danger(m, vector<int>(2));
    for (int i = 0; i < n; i++) {
      cin >> mix[i][0] >> mix[i][1];
    }

    for (int i = 0; i < m; i++) {
      cin >> danger[i][0] >> danger[i][1];
    }

    auto ans = sol.avoidExplosion(mix, n, danger, m);
    for (auto &val : ans)
      cout << val << " ";
    cout << "\n";
  }

  return 0;
}

// } Driver Code Ends
