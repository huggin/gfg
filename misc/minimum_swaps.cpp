//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
  int minimumSwaps(int c[], int v[], int n, int k, int b, int T) {
    // code here
    // vector<pair<int, int>> sheep;
    // for(int i = 0; i < n; ++i) {
    //     sheep.emplace_back(c[i], v[i]);
    // }
    // sort(sheep.begin(), sheep.end(), greater<pair<int, int>>());
    int ans = 0;
    int u = 0;
    for (int i = n - 1; i >= 0; --i) {
      if (c[i] + T * v[i] >= b) {
        ans += u;
        if (--k == 0)
          break;
      } else {
        ++u;
      }
    }
    if (k != 0)
      return -1;
    return ans;
  }
};

//{ Driver Code Starts.
int main() {
  int t = 1, testcases = 1;
  cin >> t;
  while (t >= testcases) {
    int n, k, b, T;
    cin >> n >> k >> b >> T;
    int c[n];
    int v[n];
    for (auto &j : c)
      cin >> j;
    for (auto &j : v)
      cin >> j;
    Solution s;
    int ans = s.minimumSwaps(c, v, n, k, b, T);
    cout << ans << endl;
    testcases++;
  }
  // TIME;
  return 0;
}
// } Driver Code Ends
