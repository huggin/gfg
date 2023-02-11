//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  bool ok(int arr[], int n, int k, long long mid) {
    long long total = 0;
    int used = 0;
    for (int i = 0; i < n; ++i) {
      total += arr[i];
      if (total > mid) {
        ++used;
        total = arr[i];
      }
    }
    if (used + 1 > k) return false;
    return true;
  }

 public:
  long long minTime(int arr[], int n, int k) {
    // code here
    long long lo = arr[0], hi = arr[0];
    for (int i = 1; i < n; ++i) {
      if (arr[i] > lo) {
        lo = arr[i];
      }
      hi += arr[i];
    }
    long long ans = -1;
    while (lo <= hi) {
      long long mid = lo + (hi - lo) / 2;
      bool flag = ok(arr, n, k, mid);
      if (flag) {
        ans = mid;
        hi = mid - 1;
      } else {
        lo = mid + 1;
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
    int k, n;
    cin >> k >> n;

    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    Solution obj;
    cout << obj.minTime(arr, n, k) << endl;
  }
  return 0;
}
// } Driver Code Ends
