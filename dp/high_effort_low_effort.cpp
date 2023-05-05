//{ Driver Code Starts
#include <iostream>
using namespace std;

// } Driver Code Ends

class Solution {
public:
  int maxAmt(int n, int hi[], int li[]) {
    // code here.
    if (n == 1)
      return max(hi[0], li[0]);
    int dp[n];
    dp[0] = max(hi[0], li[0]);
    dp[1] = max(dp[0] + li[1], hi[1]);
    for (int i = 2; i < n; ++i) {
      dp[i] = max(dp[i - 1] + li[i], dp[i - 2] + hi[i]);
    }
    return dp[n - 1];
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int hi[n], li[n];
    for (int i = 0; i < n; i++)
      cin >> hi[i];
    for (int i = 0; i < n; i++)
      cin >> li[i];
    Solution ob;
    cout << ob.maxAmt(n, hi, li) << endl;
  }
}
// } Driver Code Ends
