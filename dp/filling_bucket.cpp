//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  int const M = 1E8;
  int m[100001];

 public:
  int go(int N) {
    if (N == 1) return 1;
    if (N == 0) return 1;
    if (m[N] != -1) return m[N];
    return m[N] = (go(N - 1) + go(N - 2)) % M;
  }

  int fillingBucket(int N) {
    memset(m, -1, sizeof(m));
    return go(N);
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int N;

    cin >> N;

    Solution ob;
    cout << ob.fillingBucket(N) << endl;
  }
  return 0;
}
// } Driver Code Ends
