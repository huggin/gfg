//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
  int countWays(int N) {
    // Your code goes here
    const int M = 1e9 + 7;
    long long even = N / 2;
    long long odd = N - even;
    return (odd * (odd - 1) / 2 % M * even % M +
            even * (even - 1) * (even - 2) / 6 % M) %
           M;
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    Solution ob;
    cout << ob.countWays(n) << "\n";
  }
  return 0;
}
// } Driver Code Ends
