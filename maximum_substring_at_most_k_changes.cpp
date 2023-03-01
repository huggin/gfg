//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
 public:
  int characterReplacement(string s, int k) {
    // Code here
    int ans = 0;
    int n = s.size();
    int dk = k;
    for (char c = 'A'; c <= 'Z'; ++c) {
      int j = 0;
      k = dk;
      for (int i = 0; i < n; ++i) {
        if (s[i] != c) {
          if (--k < 0) {
            while (s[j] == c) {
              ++j;
            }
            ++j;
            ++k;
          }
        }
        ans = max(ans, i - j + 1);
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
    string s;
    cin >> s;
    int k;
    cin >> k;
    Solution obj;
    int ans = obj.characterReplacement(s, k);
    cout << ans << "\n";
  }
  return 0;
}
// } Driver Code Ends
