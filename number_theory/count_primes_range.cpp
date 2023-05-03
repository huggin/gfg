//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
  int countPrimes(int L, int R) {
    // code here
    vector<int> prime(R + 1, 1);
    prime[0] = prime[1] = 0;
    for (int i = 2; i <= R; ++i) {
      if (prime[i]) {
        for (int j = i + i; j <= R; j += i) {
          prime[j] = 0;
        }
      }
    }
    return accumulate(prime.begin() + L, prime.begin() + R + 1, 0);
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
    int ans = ob.countPrimes(L, R);
    cout << ans << "\n";
  }
}
// } Driver Code Ends
