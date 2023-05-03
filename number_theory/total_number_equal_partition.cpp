//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
  long long partitions(int l, int r) {
    // code here
    long long ans = 0;
    if (l == 1) {
      ans = 1;
      l = 2;
    }
    for (int i = 2; i <= r; ++i) {
      if (l <= i && i <= r)
        ans += i + 1;

      for (int j = max((l + i - 1) / i * i, i + i); j <= r; j += i) {
        ans += j / i;
      }
    }
    // cout << p[1] << ' ' << p[2] << endl;
    // return accumulate(p.begin() + l, p.begin() + r + 1, 0LL);
    return ans;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int l, r;
    cin >> l >> r;

    Solution ob;
    cout << ob.partitions(l, r) << endl;
  }
  return 0;
}
// } Driver Code Ends
