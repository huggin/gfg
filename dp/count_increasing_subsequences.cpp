//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
  unsigned long long int countSub(int arr[], int n) {
    // Your code goes here
    vector<long long> dp(n, 1);
    long long ans = 1;
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (arr[i] > arr[j]) {
          dp[i] += dp[j];
        }
      }
      ans += dp[i];
      // cout << dp[i] << ' ';
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
    int a[n + 1];
    for (unsigned long long int i = 0; i < n; i++)
      cin >> a[i];
    Solution ob;
    cout << ob.countSub(a, n) << endl;
  }
}

// } Driver Code Ends
