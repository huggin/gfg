//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
 public:
  int waysToBreakNumber(int N) {
    // code here
    const int M = 1e9 + 7;

    return (static_cast<long long>(N + 2)) * (N + 1) / 2 % M;
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
    cout << ob.waysToBreakNumber(N) << endl;
  }
  return 0;
}
// } Driver Code Ends
