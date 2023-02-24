//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
 public:
  long long totalDivisors(int N) {
    // code here
    vector<int> p(N + 1, 1);
    vector<int> prime;
    p[0] = p[1] = 0;
    for (int i = 2; i <= N; ++i) {
      if (p[i]) {
        prime.push_back(i);
        for (int j = i * i; j <= N; j += i) {
          p[j] = 0;
        }
      }
    }

    vector<int> cnt(N + 1);
    for (int i = 2; i <= N; ++i) {
      int k = i;
      for (int j = 0; j < prime.size() && prime[j] <= k; ++j) {
        while (k % prime[j] == 0) {
          cnt[prime[j]]++;
          k /= prime[j];
        }
      }
    }
    long long ans = 1;
    for (int i = 2; i <= N; ++i) {
      ans *= (cnt[i] + 1);
    }
    return ans;
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
    cout << ob.totalDivisors(N) << "\n";
  }
  return 0;
}
// } Driver Code Ends
