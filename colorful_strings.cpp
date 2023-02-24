//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  long long ans;
  vector<long long> fact;

 public:
  long long possibleStrings(int n, int r, int b, int g) {
    // code here
    fact.assign(n + 1, 1);
    for (int i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i;

    ans = 0;
    for (int i = r; i + b + g <= n; ++i) {
      for (int j = b; i + j + g <= n; ++j) {
        ans += fact[n] / fact[i] / fact[j] / fact[n - i - j];
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
    int n, r, g, b;
    cin >> n >> r >> g >> b;
    Solution ob;
    cout << ob.possibleStrings(n, r, b, g) << endl;
  }
  return 0;
}

// } Driver Code Ends
