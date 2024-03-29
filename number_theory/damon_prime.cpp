//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  bool prime(int n) {
    if (n == 0 || n == 1)
      return false;
    for (int i = 2; i * i <= n; ++i)
      if (n % i == 0)
        return false;
    return true;
  }

public:
  string damonPrime(int N) {
    // code here
    if (prime(N - 1) && prime(N + 1))
      return "Yes";
    return "No";
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
    cout << ob.damonPrime(N) << endl;
  }
  return 0;
}

// } Driver Code Ends
