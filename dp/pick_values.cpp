//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
public:
  int pickValues(int arr[], int n) {
    // code here
    if (n <= 4)
      return *min_element(arr, arr + n);
    vector<int> dp(n);
    for (int i = 0; i < 4 && i < n; ++i) {
      dp[i] = arr[i];
    }
    for (int i = 4; i < n; ++i) {
      dp[i] = min({dp[i - 4], dp[i - 3], dp[i - 2], dp[i - 1]}) + arr[i];
    }
    return min({dp[n - 1], dp[n - 2], dp[n - 3], dp[n - 4]});
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    Solution ob;
    auto ans = ob.pickValues(arr, n);
    cout << ans << "\n";
  }
  return 0;
}

// } Driver Code Ends
