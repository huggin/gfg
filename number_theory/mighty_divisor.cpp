//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  int count(int n) {
    int ans = 0;
    while (n) {
      ++ans;
      n /= 10;
    }
    return ans;
  }

public:
  long long int minNumber(int X, int Y, int Z, int N) {
    // code here
    vector<int> prime(1001);
    for (int i = 2; i <= X; ++i) {
      int t = 0;
      while (X % i == 0) {
        ++t;
        X /= i;
      }
      prime[i] = max(t, prime[i]);
    }
    for (int i = 2; i <= Y; ++i) {
      int t = 0;
      while (Y % i == 0) {
        ++t;
        Y /= i;
      }
      prime[i] = max(t, prime[i]);
    }
    for (int i = 2; i <= Z; ++i) {
      int t = 0;
      while (Z % i == 0) {
        ++t;
        Z /= i;
      }
      prime[i] = max(t, prime[i]);
    }
    long long ans = 1;
    for (int i = 2; i <= 1000; ++i) {
      if (prime[i] != 0) {
        ans *= powl(i, prime[i]);
      }
    }

    long long l = powl(10, N - 1);
    long long r = powl(10, N);
    if (ans >= r)
      return -1;
    return (l + ans - 1) / ans * ans;
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int X, Y, Z, N;
    cin >> X >> Y >> Z >> N;

    Solution ob;
    cout << ob.minNumber(X, Y, Z, N) << "\n";
  }
  return 0;
}
// } Driver Code Ends
