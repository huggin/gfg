//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
  vector<int> optimalArray(int n, vector<int> &a) {
    // Code here
    if (n == 1)
      return vector<int>{0};
    vector<int> ans(n);
    ans[1] = a[1] - a[0];

    for (int i = 2; i < n; ++i) {
      ans[i] = ans[i - 1] + a[i] - a[i / 2];
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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    Solution obj;
    vector<int> ans = obj.optimalArray(n, a);
    for (auto ele : ans) {
      cout << ele << " ";
    }
    cout << endl;
  }
  return 0;
}
// } Driver Code Ends
