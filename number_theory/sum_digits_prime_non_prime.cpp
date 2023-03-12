//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
 public:
  int digitPrime(int N) {
    // code here
    while (N > 10) {
      int t = 0;
      while (N) {
        t += N % 10;
        N /= 10;
      }
      N = t;
    }
    return N == 2 || N == 3 || N == 5 || N == 7;
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
    cout << ob.digitPrime(N) << "\n";
  }
}
// } Driver Code Ends
