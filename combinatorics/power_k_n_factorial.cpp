//{ Driver Code Starts

// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
public:
  int largestPowerOfK(int N, int K) {
    // code here
    int k = K;
    vector<int> f(k + 1);
    for (int i = 2; i * i <= k; ++i) {
      while (k % i == 0) {
        f[i]++;
        k /= i;
      }
    }
    if (k != 1)
      f[k]++;

    int ans = INT_MAX;
    for (int i = 2; i <= K; ++i) {
      if (f[i]) {
        int n = N;
        int t = 0;
        while (n) {
          t += n / i;
          n /= i;
        }
        ans = min(ans, t / f[i]);
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
    int N, K;
    cin >> N >> K;
    Solution ob;
    cout << ob.largestPowerOfK(N, K) << endl;
  }
  return 0;
}

// } Driver Code Ends
