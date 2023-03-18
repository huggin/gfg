//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  long long speed(long H[], long A[], long N, long m, long L) {
    long long ans = 0;
    for (int i = 0; i < N; ++i) {
      long c = H[i] + m * A[i];
      if (c >= L) ans += c;
    }
    return ans;
  }

 public:
  long buzzTime(long N, long M, long L, long H[], long A[]) {
    // code here
    long lo = 1, hi = max(M, L);
    long ans = -1;
    while (lo <= hi) {
      long mid = lo + (hi - lo) / 2;
      long long s = speed(H, A, N, mid, L);
      if (s < M) {
        ans = mid + 1;
        lo = mid + 1;
      } else {
        hi = mid - 1;
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
    long N, M, L;
    cin >> N >> M >> L;
    long H[N], A[N];
    for (long i = 0; i < N; i++) cin >> H[i] >> A[i];

    Solution ob;
    cout << ob.buzzTime(N, M, L, H, A) << "\n";
  }
  return 0;
}
// } Driver Code Ends
