//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
  int MinSquares(int n) {
    // Code here
    vector<int> v(n + 1, INT_MAX);
    vector<int> t;
    for (int i = 1; i * i <= 10000; ++i) {
      t.push_back(i * i);
    }
    for (int i = 1; i <= n; ++i) {
      if (find(t.begin(), t.end(), i) != t.end()) {
        v[i] = 1;
        continue;
      }
      for (int j = 1; j * j <= i; ++j) {
        v[i] = min(v[i], v[i - j * j] + 1);
      }
    }
    return v[n];
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
    int ans = ob.MinSquares(n);
    cout << ans << "\n";
  }
  return 0;
}
// } Driver Code Ends
