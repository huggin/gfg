//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  bool prime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; ++i) {
      if (n % i == 0) return false;
    }
    return true;
  }

 public:
  bool isSumOfKprimes(int N, int K) {
    // Code Here
    if (K == 1) return prime(N);
    if (K == 2) {
      if (N % 2 == 0) {
        if (N > 2)
          return true;
        else
          return false;
      } else {
        return prime(N - 2);
      }
    }
    if (N >= 2 * K) return true;
    return false;
  }
};

//{ Driver Code Starts.

int main() {
  Solution ob;
  int t;
  cin >> t;
  while (t--) {
    int N, K;
    cin >> N >> K;
    if (ob.isSumOfKprimes(N, K))
      cout << "1\n";
    else
      cout << "0\n";
  }
  return 0;
}
// } Driver Code Ends
