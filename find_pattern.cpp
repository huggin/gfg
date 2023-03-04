//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  const int M = 1e9 + 7;

  void multiple(long long a[2][2], long long ans[2][2]) {
    long long temp[2][2] = {
        ((a[0][0] * ans[0][0]) % M + (a[0][1] * ans[1][0]) % M) % M,
        ((a[0][0] * ans[0][1]) % M + (a[0][1] * ans[1][1]) % M) % M,
        ((a[1][0] * ans[0][0]) % M + (a[1][1] * ans[1][0]) % M) % M,
        ((a[1][0] * ans[0][1]) % M + (a[1][1] * ans[1][1]) % M) % M};

    memcpy(ans, temp, sizeof(temp));
  }

  void power(long long a[2][2], long long b, long long ans[2][2]) {
    while (b) {
      if (b & 1) multiple(a, ans);
      multiple(a, a);
      b >>= 1;
    }
  }

 public:
  long long int NthTerm(long long int N) {
    // Code here
    if (N == 1 || N == 2) return 1;
    if (N == 3) return 7;
    if (N == 4) return 19;

    long long a[2][2] = {0, 5, 1, 2};
    long long ans[2][2] = {1, 0, 0, 1};
    power(a, N - 3, ans);

    return (ans[0][1] + ans[1][1] * 7) % M;
  }
};

//{ Driver Code Starts.
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    long long int N;
    cin >> N;
    Solution obj;
    long long int ans = obj.NthTerm(N);
    cout << ans << "\n";
  }
  return 0;
}
// } Driver Code Ends
