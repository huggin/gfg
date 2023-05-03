//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  using ll = long long;
  ll orientation(const vector<int> &a, const vector<int> &b,
                 const vector<int> &c) {
    ll o = 1LL * a[0] * (b[1] - c[1]) + 1LL * b[0] * (c[1] - a[1]) +
           1LL * c[0] * (a[1] - b[1]);
    return o;
  }

  ll dist(ll x1, ll y1, ll x2, ll y2) {
    return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
  }

public:
  vector<vector<int>> FindConvexHull(vector<vector<int>> points_list) {
    // Code here
    vector<vector<int>> ans;
    vector<int> p0 = *min_element(points_list.begin(), points_list.end());
    sort(points_list.begin(), points_list.end(),
         [&](const vector<int> &l, const vector<int> &r) {
           ll o = orientation(p0, l, r);
           return o > 0 || o == 0 && dist(p0[0], p0[1], l[0], l[1]) <
                                         dist(p0[0], p0[1], r[0], r[1]);
         });

    for (int i = 0; i < points_list.size(); ++i) {
      while (ans.size() > 1 &&
             orientation(ans[ans.size() - 2], ans[ans.size() - 1],
                         points_list[i]) <= 0) {
        ans.pop_back();
      }
      ans.push_back(points_list[i]);
    }

    if (ans.size() < 3)
      return vector<vector<int>>(1, vector<int>{-1});
    sort(ans.begin(), ans.end());
    return ans;
  }
};

// } Driver Code Ends

//{ Driver Code Starts.
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<vector<int>> points_list;
    for (int i = 0; i < n; i++) {
      int a, b;
      cin >> a >> b;
      points_list.push_back({a, b});
    }
    Solution obj;
    vector<vector<int>> ans = obj.FindConvexHull(points_list);
    if (ans.size() == 1 and ans[0].size() == 1)
      cout << ans[0][0] << "\n";
    else {
      for (auto i : ans) {
        for (auto j : i)
          cout << j << " ";
        cout << "\n";
      }
    }
  }
  return 0;
}
// } Driver Code Ends
