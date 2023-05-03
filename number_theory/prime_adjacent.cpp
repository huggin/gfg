//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  bool prime(int n) {
    if (n == 0 || n == 1)
      return 0;
    for (int i = 2; i * i <= n; ++i)
      if (n % i == 0)
        return false;
    return true;
  }

public:
  int primeAdjacent(int N) {
    // code here
    return prime(N - 1) && prime(N + 1);
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
    if (ob.primeAdjacent(N))
      cout << "Y\n";
    else
      cout << "N\n";
  }
  return 0;
}
// } Driver Code Ends
