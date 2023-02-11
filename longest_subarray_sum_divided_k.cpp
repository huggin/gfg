//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution {
 public:
  int longSubarrWthSumDivByK(int arr[], int n, int k) {
    // Complete the function
    for (int i = 0; i < n; ++i) {
      arr[i] = (arr[i] % k + k) % k;
    }
    unordered_map<int, int> m;
    m[0] = -1;
    int total = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      total = (total + arr[i]) % k;
      if (m.find(total) == m.end()) {
        m[total] = i;
      } else {
        ans = max(ans, i - m[total]);
      }
    }
    return ans;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k, i;
    cin >> n >> k;
    int arr[n];
    for (i = 0; i < n; i++) cin >> arr[i];
    Solution ob;
    cout << ob.longSubarrWthSumDivByK(arr, n, k) << "\n";
  }
  return 0;
}

// } Driver Code Ends
