//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  const int M = 1e9 + 7;
  const int ma = 1e5;
  vector<int> p;

 public:
  void precompute() {
    // Code Here
    p.assign(100001, 1);
    vector<char> is_prime(ma + 1, 1);
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i <= ma; ++i) {
      if (is_prime[i]) {
        p[i] = p[i - 1] * i % M;
        for (int j = i * i; j <= ma; j += i) is_prime[j] = 0;
      } else {
        p[i] = p[i - 1];
      }
    }
  }
  long long primorial(long long n) {
    // Code here
    return p[n];
  }
};

//{ Driver Code Starts.

int main() {
  Solution ob;
  ob.precompute();
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    cout << ob.primorial(n) << endl;
  }
  return 0;
}
// } Driver Code Ends

