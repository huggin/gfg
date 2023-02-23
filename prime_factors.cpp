//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

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
  vector<int> AllPrimeFactors(int N) {
    // Code here
    sieve(N);
    vector<int> ans;
    for (int i = 0; i < prime.size(); ++i) {
      if (N % prime[i] == 0) {
        ans.push_back(prime[i]);
        while (N % prime[i] == 0) N /= prime[i];
      }
    }
    return ans;
  }
};

//{ Driver Code Starts.
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    long long int N;
    cin >> N;
    Solution ob;
    vector<int> ans = ob.AllPrimeFactors(N);
    for (auto i : ans) cout << i << " ";
    cout << "\n";
  }
  return 0;
}
// } Driver Code Ends
