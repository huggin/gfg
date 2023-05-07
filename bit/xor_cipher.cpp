//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
  string deCypher(string S) {
    // Code Here
    int n = S.size();
    string ans((n + 1) / 2, S[n - 1]);

    int m = ans.size();
    int t1 = isdigit(S[n - 1]) ? S[n - 1] - '0' : S[n - 1] - 'A' + 10;

    for (int j = m - 2, i = n - 2; j >= 0; --i, --j) {
      int t2 = isdigit(S[i]) ? S[i] - '0' : S[i] - 'A' + 10;
      int c = t1 ^ t2;
      // cout << t1 << ' ' << t2 << ' ' << c << endl;
      ans[j] = c <= 9 ? c + '0' : c - 10 + 'A';
      t1 = t2;
    }
    return ans;
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  string s;
  while (t--) {
    cin >> s;
    Solution ob;
    cout << ob.deCypher(s) << "\n";
  }
  return 0;
}
// } Driver Code Ends
