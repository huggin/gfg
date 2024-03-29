//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
  int minimumDays(int S, int N, int M) {
    // code here
    if (N < M)
      return -1;
    if (N == M) {
      if (S >= 7)
        return -1;
      return S;
    }
    if (N * 6 < M * 7) {
      if (S >= 7) {
        return -1;
      } else {
        if (S * M % N == 0) {
          return S * M / N;
        }
        return S * M / N + 1;
      }
    } else {
      if (S * M % N == 0) {
        return S * M / N;
      }
      return S * M / N + 1;
    }
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int S, N, M;
    cin >> S >> N >> M;

    Solution ob;
    cout << ob.minimumDays(S, N, M) << endl;
  }
  return 0;
}
// } Driver Code Ends
