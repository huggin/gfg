//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
  int smallestSumSubarray(vector<int> &a) {
    // Code here
    int ans = INT_MAX;
    int total = 0;
    for (int i = 0; i < a.size(); ++i) {
      if (a[i] >= 0) {
        if (total + a[i] < 0) {
          total += a[i];
        } else {
          ans = min(ans, a[i]);
          total = 0;
        }
      } else {
        total += a[i];
        ans = min(ans, total);
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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    Solution ob;

    int ans = ob.smallestSumSubarray(a);

    cout << ans << endl;
  }
}
// } Driver Code Ends
