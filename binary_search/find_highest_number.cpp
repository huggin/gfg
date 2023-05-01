//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
  int findPeakElement(vector<int> &a) {
    // Code here.
    int lo = 0, hi = a.size() - 1;
    int ans = INT_MIN;
    while (lo <= hi) {
      int mid1 = lo + (hi - lo) / 3;
      int mid2 = hi - (hi - lo) / 3;
      if (a[mid1] < a[mid2]) {
        lo = mid1 + 1;
        ans = max(ans, a[mid2]);
      } else if (a[mid1] > a[mid2]) {
        hi = mid2 - 1;
        ans = max(ans, a[mid1]);
      } else {
        lo = mid1 + 1;
        hi = mid2 - 1;
        ans = max(ans, a[mid1]);
      }
    }
    return ans;
  }
};

//{ Driver Code Starts.
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    Solution ob;
    int ans = ob.findPeakElement(a);
    cout << ans << "\n";
  }
  return 0;
}

// } Driver Code Ends
