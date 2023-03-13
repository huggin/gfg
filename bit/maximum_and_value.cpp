//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
 public:
  // Function for finding maximum AND value.
  int maxAND(int arr[], int N) {
    // Your code here
    // 1e5 is less than 17 digits in binary
    int ans = 0;
    vector<int> a(arr, arr + N);
    for (int k = 17; k >= 0; --k) {
      vector<int> v;
      for (int i = 0; i < a.size(); ++i) {
        if (a[i] & (1 << k)) {
          v.push_back(a[i]);
        }
      }
      // cout << k << ' ' << v.size() << endl;
      if (v.size() >= 2) {
        ans = max(ans, v[0] & v[1]);
        swap(a, v);
      }
    }
    return ans;
  }
};

//{ Driver Code Starts.

// Driver function
int main() {
  int t;
  cin >> t;  // testcases
  while (t--) {
    int n;
    cin >> n;  // input n
    int arr[n + 5], i;

    // inserting elements
    for (i = 0; i < n; i++) cin >> arr[i];
    Solution obj;
    // calling maxAND() function
    cout << obj.maxAND(arr, n) << endl;
  }
  return 0;
}
// } Driver Code Ends
