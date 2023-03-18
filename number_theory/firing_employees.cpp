//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  vector<int> prime;
  void sieve(int n) {
    prime.assign(n + 1, 1);
    prime[0] = prime[1] = 0;
    for (int i = 2; i <= n; ++i) {
      if (prime[i]) {
        for (int j = i * i; j <= n; j += i) prime[j] = 0;
      }
    }
  }

  int solve(vector<int>& a, int k, vector<int>& s) {
    if (a[k] == 0) return s[k] = 0;
    if (s[k] != -1) return s[k];
    return s[k] = 1 + solve(a, a[k] - 1, s);
  }

 public:
  int firingEmployees(vector<int>& arr, int n) {
    // code here
    sieve(2 * 1e5);
    int ans = 0;
    vector<int> senior(n, -1);
    for (int i = 0; i < n; ++i) {
      if (arr[i] == 0) continue;
      solve(arr, i, senior);
      int k = i + 1 + senior[i];
      // cout << i+1 << ' ' << senior[i] << endl;
      if (prime[k]) ++ans;
    }
    return ans;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> arr(n, 0);

    for (int i = 0; i < n; i++) cin >> arr[i];

    Solution obj;
    cout << obj.firingEmployees(arr, n) << endl;
  }
  return 0;
}
// } Driver Code Ends
