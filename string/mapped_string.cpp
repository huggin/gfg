//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
 public:
  long long int mapStr(long long int n) {
    // code here
    const int M = 1e9 + 7;
    vector<long long> dp(n, 1);
    for (int i = 1; i <= n; ++i) {
      dp[i] = dp[i - 1] * i % M;
    }
    return dp[n];
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int N;
    cin >> N;
    Solution ob;
    cout << ob.mapStr(N) << endl;
  }
  return 0;
}

// } Driver Code Ends
