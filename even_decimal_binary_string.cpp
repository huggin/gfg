//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
 public:
  long long evenDecimalSubStr(string S, int N) {
    // code here
    long long ans = 0;
    for (int i = 0; i < N; ++i) {
      if (S[i] == '0') {
        ans += N - i;
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
    int n;
    cin >> n;
    string s;
    cin >> s;
    Solution ob;
    cout << ob.evenDecimalSubStr(s, n) << "\n";
  }
  return 0;
}
// } Driver Code Ends
