//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
  long long numberOfSubsequences(int N, long long A[]) {
    // code here
    const int M = 1e9 + 7;
    long long cnt = 0;
    for (int i = 1; i <= (int)1e9; i *= 2) {
      for (int j = 0; j < N; ++j) {
        if (A[j] == i)
          ++cnt;
      }
    }
    long long ans = 1;
    for (int i = 0; i < cnt; ++i) {
      ans = (ans * 2) % M;
    }
    return ans - 1;
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int N;
    cin >> N;
    long long A[N];
    for (int i = 0; i < N; ++i) {
      cin >> A[i];
    }
    Solution ob;
    cout << ob.numberOfSubsequences(N, A) << endl;
  }
  return 0;
}
// } Driver Code Ends
