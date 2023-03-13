//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
 public:
  // Function to find the smallest window in the string s consisting
  // of all the characters of string p.
  string smallestWindow(string s, string p) {
    // Your code here
    int c[256] = {0};
    int num = 0;
    for (int i = 0; i < p.size(); ++i) {
      if (c[p[i]]++ == 0) {
        ++num;
      }
    }
    int len = -1;
    int left, right;
    int c2[256] = {0};
    for (int i = 0, j = 0; i < s.size(); ++i) {
      if (c[s[i]] != 0) {
        if (++c2[s[i]] == c[s[i]]) {
          if (--num == 0) {
            if (len == -1 || i - j < len) {
              left = j;
              right = i;
              len = i - j;
            }
            while (num == 0) {
              if (c[s[j]] != 0) {
                if (--c2[s[j]] < c[s[j]]) {
                  num = 1;
                  ++j;
                  break;
                }
              }
              ++j;
              if (i - j < len) {
                left = j;
                right = i;
                len = i - j;
              }
            }
          }
        }
      }
    }
    if (len == -1) return "-1";
    return s.substr(left, right - left + 1);
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    string pat;
    cin >> pat;
    Solution obj;
    cout << obj.smallestWindow(s, pat) << endl;
  }
  return 0;
}
// } Driver Code Ends
