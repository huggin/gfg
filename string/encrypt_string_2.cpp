//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  string hex(int k) {
    char buf[512];
    sprintf(buf, "%x", k);
    string s(buf);
    reverse(s.begin(), s.end());
    return s;
  }

public:
  string encryptString(string S) {
    // code here
    string ans;
    int i = 0;
    for (; i < S.size();) {
      char c = S[i];
      int k = i;
      for (; k < S.size(); ++k) {
        if (S[k] != c) {
          ans += c + hex(k - i);
          i = k;
          break;
        }
      }
      if (k == S.size()) {
        ans += c + hex(k - i);
        i = k;
      }
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};

//{ Driver Code Starts.
int main() {
  long long t;
  cin >> t;
  while (t--) {
    string S;
    cin >> S;

    Solution ob;
    cout << ob.encryptString(S) << endl;
  }
  return 0;
}
// } Driver Code Ends
