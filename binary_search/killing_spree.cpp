//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
  long long int killinSpree(long long int n) {
    // Code Here
    long long lo = 1, hi = 15000;
    long long ans = -1;
    while (lo <= hi) {
      long long mid = lo + (hi - lo) / 2;
      long long sum = mid * (mid + 1) * (2 * mid + 1) / 6;
      if (sum > n)
        hi = mid - 1;
      else {
        lo = mid + 1;
        ans = mid;
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
    long long int n;
    cin >> n;
    Solution obj;
    long long int ans = obj.killinSpree(n);
    cout << ans << "\n";
  }
  return 0;
}

// } Driver Code Ends
