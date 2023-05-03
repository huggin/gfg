//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  long long binPow(long long a, long long b, long long m) {
    long long ans = 1;
    while (b) {
      if (b & 1)
        ans = (ans * a) % m;
      a = (a * a) % m;
      b >>= 1;
    }
    return ans;
  }

public:
  long long geoProg(long long N) {
    // code here
    const int M = 1e9 + 7;
    long long t = binPow(2, N, M - 1);
    return binPow(2, t, M) - 1;
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long N;

    cin >> N;

    Solution ob;
    cout << ob.geoProg(N) << endl;
  }
  return 0;
}
// } Driver Code Ends
