//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
  int longestSubstring(string S) {
    // code here
    unordered_map<int, int> m;
    int ans = 1;
    int mask = 0;
    m[0] = -1;
    for (int i = 0; i < S.size(); ++i) {
      mask ^= (1 << S[i] - 'a');

      if (m.find(mask) != m.end()) {
        ans = max(ans, i - m[mask]);
      } else {
        m[mask] = i;
      }
      for (int j = 0; j < 26; ++j) {
        int mask2 = mask ^ (1 << j);
        if (m.find(mask2) != m.end()) {
          ans = max(ans, i - m[mask2]);
        }
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
    string S;
    cin >> S;

    Solution ob;
    cout << ob.longestSubstring(S) << endl;
  }
  return 0;
}
// } Driver Code Ends
