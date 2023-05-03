//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  bool prime(int n) {
    if (n == 1)
      return true;
    for (int i = 2; i * i <= n; ++i) {
      if (n % i == 0)
        return false;
    }
    return true;
  }

public:
  int minThirdPiles(int A, int B) {
    // code here
    for (int i = 1;; ++i) {
      if (prime(A + B + i))
        return i;
    }
    return 1;
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int A, B;
    cin >> A >> B;
    Solution ob;
    cout << ob.minThirdPiles(A, B) << endl;
  }
  return 0;
}

// } Driver Code Ends
