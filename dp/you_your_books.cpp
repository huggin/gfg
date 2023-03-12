//{ Driver Code Starts
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
//#include<Windows.h>
using namespace std;

// } Driver Code Ends

class Solution {
 public:
  /*You are requried to complete this method */
  int max_Books(int a[], int n, int k) {
    // Your code here
    int ans = -100000000;
    vector<int> dp(n);
    for (int i = 0; i < n; ++i) {
      if (a[i] > k)
        dp[i] = 0;
      else {
        if (i - 1 >= 0)
          dp[i] = dp[i - 1] + a[i];
        else
          dp[i] = a[i];
      }
      ans = max(ans, dp[i]);
    }
    return ans;
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    int ar[n];
    for (int i = 0; i < n; i++) {
      cin >> ar[i];
    }
    Solution ob;
    cout << ob.max_Books(ar, n, k) << endl;
  }
  return 0;
}

// } Driver Code End
