//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
  int rank(string S) {
    // code here
    const int M = 1000003;
    set<int> s;
    int n = S.size();
    for (int i = 0; i < n; ++i) {
      if (s.find(S[i]) != s.end())
        return 0;
      s.insert(S[i]);
    }
    vector<long long> fact(n + 1, 1);
    for (int i = 1; i <= n; ++i)
      fact[i] = fact[i - 1] * i;

    long long ans = 1;
    for (int i = 0; i < n; ++i) {
      auto it = s.find(S[i]);
      int d = distance(s.begin(), it);
      ans += d * fact[n - 1 - i];
      s.erase(it);
    }
    return ans % M;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    string S;
    cin >> S;

    Solution ob;
    cout << ob.rank(S) << endl;
  }
  return 0;
}
// } Driver Code Ends
