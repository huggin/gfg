//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
  int countBits(int N, long long int A[]) {
    // code here
    vector<int> cnt(32);
    for (int j = 0; j < N; ++j) {
      for (int i = 0; i <= 31; ++i) {
        if (A[j] & (1 << i)) {
          cnt[i]++;
        }
      }
    }
    const int M = 1e9 + 7;
    long long ans = 0;
    long long t = 1;
    for (int i = 0; i < 32; ++i) {
      // cout << cnt[i] << ' ';
      ans = (ans + t * 2 * cnt[i] * (N - cnt[i])) % M;
    }
    return ans;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int N;
    cin >> N;
    long long int A[N];
    for (int i = 0; i < N; i++)
      cin >> A[i];

    Solution ob;
    cout << ob.countBits(N, A) << "\n";
  }
  return 0;
}
// } Driver Code Ends
