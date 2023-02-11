//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int minFlips(string s);
int32_t main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;

    cout << minFlips(s) << endl;
  }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends

int minFlips(string S) {
  // your code here
  int ans = S.size();
  int t1 = 0, t2 = 0;
  for (int i = 0; i < S.size(); ++i) {
    if (i % 2 == 0) {
      if (S[i] == '0') {
        t1++;
      } else {
        t2++;
      }
    } else {
      if (S[i] == '0') {
        t2++;
      } else {
        t1++;
      }
    }
  }
  ans = min(t1, t2);
  return ans;
}
