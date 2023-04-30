//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
  int maxSumLis(int Arr[], int n) {
    // code here
    vector<int> dp(n, 1);
    vector<int> total(Arr, Arr + n);
    int ans = 1;
    int t = Arr[0];
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (Arr[j] < Arr[i]) {
          if (dp[i] < dp[j] + 1) {
            dp[i] = dp[j] + 1;
            total[i] = total[j] + Arr[i];
          } else if (dp[i] == dp[j] + 1) {
            if (total[i] > total[j] + Arr[i]) {
              total[i] = total[j] + Arr[i];
            }
          }
        }
        if (dp[i] > ans || dp[i] == ans && total[i] < t) {
          ans = dp[i];
          t = total[i];
        }
      }
    }

    return accumulate(Arr, Arr + n, 0) - t;
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int Arr[n];
    for (int i = 0; i < n; i++)
      cin >> Arr[i];
    Solution obj;
    cout << obj.maxSumLis(Arr, n) << endl;
  }
  return 0;
}
// } Driver Code Ends
