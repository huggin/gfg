//{ Driver Code Starts

// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  bool prime(int n) {
    if (n == 0 || n == 1) return false;
    for (int i = 2; i * i <= n; ++i)
      if (n % i == 0) return false;
    return true;
  }

  int count(int n) {
    int ans = 0;
    while (n) {
      ++ans;
      n &= (n - 1);
    }
    return ans;
  }

 public:
  int primeSetBits(int L, int R) {
    // code here
    int ans = 0;
    for (int i = L; i <= R; ++i) {
      if (prime(count(i))) ++ans;
    }
    return ans;
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int L, R;
    cin >> L >> R;
    Solution ob;
    cout << ob.primeSetBits(L, R) << endl;
  }
  return 0;
}

// } Driver Code Ends
