//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
  int primeSum(int N) {
    // code here
    int ans = 0;
    while (N) {
      int d = N % 10;
      N /= 10;
      if (d == 2 || d == 3 || d == 5 || d == 7)
        ans += d;
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

    Solution ob;
    cout << ob.primeSum(N) << "\n";
  }
  return 0;
}
// } Driver Code Ends
