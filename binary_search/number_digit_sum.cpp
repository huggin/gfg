//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  int sumofdigit(int n) {
    int ans = 0;
    while (n) {
      ans += n % 10;
      n /= 10;
    }
    return ans;
  }

public:
  long long int numberCount(long long int N, long long int K) {
    // your code here
    int lo = 9, hi = N;
    int ans = 0;
    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;
      int s = sumofdigit(mid);
      if (mid - s >= K) {
        ans = mid;
        hi = mid - 1;
      } else {
        lo = mid + 1;
      }
    }
    if (ans == 0)
      return 0;
    return N - ans + 1;
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n, k;
    cin >> n >> k;
    Solution ob;
    cout << ob.numberCount(n, k) << endl;
  }
  return 0;
}
// } Driver Code Ends
