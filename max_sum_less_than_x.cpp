//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
 public:
  int findMaxSubarraySum(long long arr[], int n, long long sum) {
    // Your code goes here
    int j = 0;
    long long t = 0;
    long long ans = INT_MIN;
    for (int i = 0; i < n; ++i) {
      t += arr[i];
      if (t <= sum) {
        ans = max(ans, t);
      } else {
        while (t > sum && j <= i) {
          t -= arr[j++];
        }
        ans = max(ans, t);
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
    int n;
    cin >> n;

    long long a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    long long sum;
    cin >> sum;

    Solution ob;
    cout << ob.findMaxSubarraySum(a, n, sum);

    cout << "\n";
  }
  return 0;
}
// } Driver Code Ends
