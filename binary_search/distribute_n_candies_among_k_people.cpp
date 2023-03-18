//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  using ll = long long;

 public:
  vector<long long> distributeCandies(int N, int K) {
    // code here
    vector<ll> ans(K);
    ll lo = 1, hi = N;
    int n = -1;
    while (lo <= hi) {
      ll mid = lo + (hi - lo) / 2;
      if (mid * (mid + 1) <= 2LL * N) {
        n = mid;
        lo = mid + 1;
      } else {
        hi = mid - 1;
      }
    }

    int more = N - n * (1 + n) / 2;
    int a = n / K;

    for (int i = 0; i < K; ++i) {
      long long b = (2 * (i + 1) + (a - 1) * K) * a / 2;
      if (n % K > i)
        ans[i] = b + i + 1 + n / K * K;
      else if (n % K == i)
        ans[i] = b + more;
      else
        ans[i] = b;
    }
    return ans;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int N, K;
    cin >> N >> K;

    Solution ob;
    vector<long long> res = ob.distributeCandies(N, K);

    for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
    cout << endl;
  }
  return 0;
}
// } Driver Code Ends
