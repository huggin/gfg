//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
public:
  int overlap(vector<pair<int, int>> iv, int n) {
    // Write your code here
    vector<pair<int, int>> v;
    for (int i = 0; i < n; ++i) {
      v.emplace_back(iv[i].first, 0);
      v.emplace_back(iv[i].second, 1);
    }
    sort(v.begin(), v.end());
    int ans = 0;
    int current = 0;
    for (int i = 0; i < v.size(); ++i) {
      // cout << v[i].first << ' ' << v[i].second << endl;
      if (v[i].second == 0) {
        ++current;
        ans = max(ans, current);
      } else {
        --current;
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
    vector<pair<int, int>> intervals;
    for (int i = 0; i < n; i++) {
      int a, b;
      cin >> a >> b;
      intervals.push_back({a, b});
    }
    Solution ob;
    int ans = ob.overlap(intervals, n);
    cout << ans << endl;
  }
  return 0;
}

// } Driver Code Ends
