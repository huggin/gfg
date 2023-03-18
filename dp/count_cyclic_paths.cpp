//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
 public:
  int countPaths(int N) {
    // code here
    const int M = 1e9 + 7;
    long long a = 1, b = 0;
    for (int i = 1; i <= N; ++i) {
      long long t = (3 * a + 2 * b) % M;
      a = b;
      b = t;
    }
    return a;
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
    cout << ob.countPaths(N) << endl;
  }
  return 0;
}

// } Driver Code Ends
