//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
  int modifiedFib(int N, int A, int B, int C) {
    // code here
    const int M = 1e9 + 7;
    switch ((N - 1) % 6 + 1) {
    case 1:
      return (A + B + M) % M;
    case 2:
      return (B + C + M) % M;
    case 3:
      return (C - A + M) % M;
    case 4:
      return (M - A - B) % M;
    case 5:
      return (M - B - C) % M;
    case 6:
      return (A - C + M) % M;
    }
    return -1;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int N, A, B, C;
    cin >> N >> A >> B >> C;

    Solution ob;
    cout << ob.modifiedFib(N, A, B, C) << endl;
  }
  return 0;
}
// } Driver Code Ends
