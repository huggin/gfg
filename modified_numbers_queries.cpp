//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  vector<int> prime;

  void sieve(int n) {
    vector<int> ok(n + 1, 1);
    ok[0] = ok[1] = 0;
    for (int i = 2; i <= n; ++i) {
      if (ok[i]) {
        prime.push_back(i);
        for (int j = i * i; j <= n; j += i) ok[j] = 0;
      }
    }
  }

 public:
  int sumOfAll(int l, int r) {
    sieve(r);
    int ans = 0;
    for (int j = l; j <= r; ++j) {
      for (int i = 0; i < prime.size(); ++i) {
        if (prime[i] > j) break;
        int k = j;
        if (k % prime[i] == 0) {
          ans += prime[i];
          while (k % prime[i] == 0) k /= prime[i];
        }
      }
    }
    return ans;
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int l, r;
    cin >> l >> r;
    Solution ob;
    cout << ob.sumOfAll(l, r) << endl;
  }
  return 0;
}

// } Driver Code Ends
