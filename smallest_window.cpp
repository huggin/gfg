//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
 public:
  int smallestSubstring(string S) {
    // Code here
    int c[3] = {0};
    int n = S.size();
    int num = 0;
    int ans = n + 1;
    int j = 0;
    for (int i = 0; i < n; ++i) {
      if (c[S[i] - '0']++ == 0) {
        if (++num == 3) {
          ans = min(ans, i - j + 1);
          while (j < n && --c[S[j] - '0'] > 0) {
            ++j;
            ans = min(ans, i - j + 1);
          }
          ++j;
          --num;
        }
      }
    }
    return ans == n + 1 ? -1 : ans;
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
    cout << ob.smallestSubstring(S);
    cout << endl;
  }
}
// } Driver Code Ends
