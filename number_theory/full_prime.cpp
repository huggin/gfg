//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  bool isPrime(int n) {
    if (n == 1 || n == 0) return false;
    for (int i = 2; i * i <= n; ++i) {
      if (n % i == 0) return false;
    }
    return true;
  }

 public:
  int fullPrime(int N) {
    // code here
    if (!isPrime(N)) return 0;
    while (N > 0) {
      if (!isPrime(N % 10)) return 0;
      N /= 10;
    }
    return true;
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
    cout << ob.fullPrime(N) << "\n";
  }
}
// } Driver Code Ends
