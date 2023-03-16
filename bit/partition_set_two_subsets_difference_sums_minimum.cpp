//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
 public:
  vector<vector<int>> minDifference(vector<int>& arr, int n) {
    // Code here
    vector<vector<int>> a(2);
    int ans = INT_MAX;
    for (int i = 0; i < (1 << n); ++i) {
      vector<int> v1, v2;
      int total1 = 0, total2 = 0;
      for (int j = 0; j < n; ++j) {
        if ((i & (1 << j)) != 0) {
          v1.push_back(arr[j]);
          total1 += arr[j];
        } else {
          v2.push_back(arr[j]);
          total2 += arr[j];
        }
      }
      if (v1.size() == v2.size() || v1.size() + 1 == v2.size()) {
        // cout << total1 << ' ' << total2 << endl;
        if (ans > abs(total1 - total2)) {
          ans = abs(total1 - total2);
          a[0] = v1;
          a[1] = v2;
        }
      }
    }
    return a;
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

    Solution obj;
    vector<vector<int>> ans = obj.minDifference(arr, n);

    long long s1 = 0, s2 = 0;

    for (int i = 0; i < ans[0].size(); i++) s1 += ans[0][i];
    for (int i = 0; i < ans[1].size(); i++) s2 += ans[1][i];

    if (s1 > s2) swap(s1, s2);

    cout << s1 << "\n" << s2 << "\n";
  }
}
// } Driver Code Ends
