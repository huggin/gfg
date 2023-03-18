//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  vector<long long> ans;

 public:
  void precompute() {
    // Code Here
    for (int i = 0; i < 63; ++i) {
      long long x = 1LL << i;
      for (int j = i + 1; j < 63; ++j) {
        long long y = 1LL << j;
        for (int k = j + 1; k < 63; ++k) {
          long long z = 1LL << k;
          long long v = x | y | z;
          ans.push_back(v);
        }
      }
    }
    sort(ans.begin(), ans.end());
  }

  long long solve(long long l, long long r) {
    // Code Here
    auto c1 = lower_bound(ans.begin(), ans.end(), l);
    auto c2 = upper_bound(ans.begin(), ans.end(), r);

    return c2 - c1;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  Solution ob;
  ob.precompute();
  cin >> t;
  while (t--) {
    long long l, r;
    cin >> l >> r;
    cout << ob.solve(l, r) << endl;
  }
  return 0;
}
// } Driver Code Ends
