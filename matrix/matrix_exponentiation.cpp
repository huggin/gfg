//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  int mod = 1e9 + 7;
  vector<vector<long long>> multiple(vector<vector<long long>> &a,
                                     vector<vector<long long>> &b) {
    vector<vector<long long>> ans(2, vector<long long>(2));
    ans[0][0] = ((a[0][0] * b[0][0]) % mod + (a[0][1] * b[1][0]) % mod) % mod;
    ans[0][1] = ((a[0][0] * b[0][1]) % mod + (a[0][1] * b[1][1]) % mod) % mod;
    ans[1][0] = ((a[1][0] * b[0][0]) % mod + (a[1][1] * b[1][0]) % mod) % mod;
    ans[1][1] = ((a[1][0] * b[0][1]) % mod + (a[1][1] * b[1][1]) % mod) % mod;
    return ans;
  }

  vector<vector<long long>> solve(vector<vector<long long>> &mat, long long k) {
    vector<vector<long long>> ans(2, vector<long long>(2));
    if (k == 0) {
      ans[0][0] = ans[1][1] = 1;
      ans[0][1] = ans[1][0] = 0;
      return ans;
    }
    ans = solve(mat, k / 2);
    ans = multiple(ans, ans);
    if (k % 2 == 1) {
      ans = multiple(ans, mat);
    }
    return ans;
  }

public:
  int FindNthTerm(long long int n) {
    // Code here
    vector<vector<long long>> mat = {{1, 1}, {1, 0}};
    auto ans = solve(mat, n - 1);
    return (ans[0][0] + ans[0][1]) % mod;
  }
};

//{ Driver Code Starts.
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    long long int n;
    cin >> n;
    Solution obj;
    int ans = obj.FindNthTerm(n);
    cout << ans << "\n";
  }
  return 0;
}
// } Driver Code Ends
