//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
 public:
  int sumOfDigits(int N) {
    // code here
    vector<int> dp(1000001);
    for (int i = 0; i <= 9 && i <= N; ++i) {
      dp[i] = i;
    }
    for (int i = 10; i <= N; ++i) {
      dp[i] = dp[i % 10] + dp[i / 10];
    }

    return accumulate(dp.begin(), dp.end(), 0);
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int N;
    cin >> N;
    Solution ob;
    cout << ob.sumOfDigits(N) << endl;
  }
  return 0;
}
// } Driver Code Ends
