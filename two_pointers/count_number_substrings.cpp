//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  long long solve(const string &s, int k) {
    int n = s.size();
    int j = 0;
    int c[26] = {0};
    int total = 0;
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
      if (c[s[i] - 'a']++ == 0) {
        ++total;
      }

      while (total > k) {
        if (--c[s[j] - 'a'] == 0) {
          --total;
        }
        ++j;
      }
      ans += i - j + 1;
    }
    return ans;
  }

public:
  long long int substrCount(string s, int k) {
    // code here.
    if (k == 1)
      return solve(s, 1);
    return solve(s, k) - solve(s, k - 1);
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int k;
    cin >> k;
    Solution ob;
    cout << ob.substrCount(s, k) << endl;
  }
}
// } Driver Code Ends
