//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
 public:
  vector<int> sophie_Primes(int n) {
    // Code here
    vector<char> prime(2 * n + 1, 1);
    vector<int> p;

    for (int i = 2; i < 2 * n + 1; ++i)
      if (prime[i]) {
        if (i < n) p.push_back(i);
        for (int j = i * i; j < 2 * n + 1; j += i) prime[j] = 0;
      }

    vector<int> ans;
    for (int i = 0; i < p.size(); ++i) {
      if (prime[2 * p[i] + 1]) ans.push_back(p[i]);
    }
    return ans;
  }
};

//{ Driver Code Starts.
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    Solution ob;
    vector<int> ans = ob.sophie_Primes(n);
    for (auto i : ans) cout << i << " ";
    cout << "\n";
  }
  return 0;
}
// } Driver Code Ends
