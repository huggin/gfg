//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  vector<int> prime;

  void sieve(long long n) {
    prime.assign(n + 1, 1);
    prime[0] = prime[1] = 0;
    for (int i = 2; i * i <= n; ++i)
      if (prime[i])
        for (int j = i + i; j <= n; j += i) prime[j] = 0;
  }

 public:
  int count3DivNums(long long L, long long R) {
    // code here
    int n = sqrt(R);
    int l = sqrt(L);
    if (l * l != L) ++l;
    sieve(n);
    return count(prime.begin() + l, prime.begin() + n + 1, 1);
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long L, R;

    cin >> L >> R;

    Solution ob;
    cout << ob.count3DivNums(L, R) << endl;
  }
  return 0;
}
// } Driver Code Ends
