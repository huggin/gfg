//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  // Complete the function and return minimum number of operations
  int count(const string &s1, const string &s2, int k) {
    int n = s1.size();
    int ans = 0;
    for (int i = 0; i < n / 2; ++i) {
      int j = n - 1 - i;
      char a = s1[i];
      char b = s1[j];
      if (i >= k && i <= k + s2.size() - 1 && j >= k &&
          j <= k + s2.size() - 1) {
        if (s2[i - k] != s2[j - k])
          return 100000;
        if (s2[i - k] != s1[i])
          ++ans;
        if (s2[j - k] != s1[j])
          ++ans;
      } else {
        if (i >= k && i <= k + s2.size() - 1) {
          if (a != s2[i - k])
            ++ans;
          a = s2[i - k];
        }
        if (j >= k && j <= k + s2.size() - 1) {
          if (b != s2[j - k])
            ++ans;
          b = s2[j - k];
        }
        if (a != b)
          ++ans;
      }
    }
    if (n % 2 && n / 2 >= k && n / 2 <= k + s2.size() - 1 &&
        s1[n / 2] != s2[n / 2 - k])
      ++ans;

    // cout << k << ' ' << ans << endl;
    return ans;
  }

public:
  int specialPalindrome(string s1, string s2) {
    // Code Here
    if (s2.size() > s1.size())
      return -1;
    int oo = 100000;
    int ans = oo;
    for (int i = 0; i <= s1.size() - s2.size(); ++i) {
      ans = min(ans, count(s1, s2, i));
    }
    if (ans >= oo)
      return -1;
    return ans;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s1, s2;
    cin >> s1 >> s2;
    Solution obj;
    int ans = obj.specialPalindrome(s1, s2);

    cout << ans << endl;
  }
}
// } Driver Code Ends
