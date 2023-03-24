//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
public:
  string removeReverse(string S) {
    // code here
    int cnt[26] = {0};
    for (char c : S) {
      cnt[c - 'a']++;
    }
    int n = S.size();
    bool rev = false;
    for (int i = 0, j = n - 1; i <= j;) {
      if (!rev) {
        if (cnt[S[i] - 'a'] > 1) {
          --cnt[S[i] - 'a'];
          S[i] = ' ';
          rev = !rev;
        }
        ++i;
      } else {
        if (cnt[S[j] - 'a'] > 1) {
          --cnt[S[j] - 'a'];
          S[j] = ' ';
          rev = !rev;
        }
        --j;
      }
    }
    string ans;
    if (rev) {
      for (int i = n - 1; i >= 0; --i) {
        if (S[i] != ' ') {
          ans.push_back(S[i]);
        }
      }
    } else {
      for (int i = 0; i < n; ++i) {
        if (S[i] != ' ') {
          ans.push_back(S[i]);
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
    Solution obj;
    auto ans = obj.removeReverse(S);
    cout << ans << endl;
  }
}
// } Driver Code Ends
