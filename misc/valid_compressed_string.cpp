//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
  int checkCompressed(string S, string T) {
    // code here
    int j = 0;
    for (int i = 0; i < T.size(); ++i) {
      if (T[i] >= '0' && T[i] <= '9') {
        int t = 0;
        while (T[i] >= '0' && T[i] <= '9') {
          t = t * 10 + T[i] - '0';
          ++i;
        }
        --i;
        if (j + t > S.size())
          return 0;
        j += t;
      } else if (j >= S.size() || T[i] != S[j++]) {
        return 0;
      }
    }
    return j < S.size() ? 0 : 1;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    string S, T;

    cin >> S >> T;

    Solution ob;
    cout << ob.checkCompressed(S, T) << endl;
  }
  return 0;
}
// } Driver Code Ends
