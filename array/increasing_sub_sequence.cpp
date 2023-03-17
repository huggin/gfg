//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
 public:
  int maxLength(string S) {
    // code here
    string s;
    for (int i = 0; i < S.size(); ++i) {
      auto it = lower_bound(s.begin(), s.end(), S[i]);
      if (it == s.end()) {
        s.push_back(S[i]);
      } else {
        *it = S[i];
      }
    }
    return s.size();
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
    cout << ob.maxLength(S) << endl;
  }
  return 0;
}
// } Driver Code Ends
