//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
 public:
  string previousNumber(string S) {
    // code here
    if (is_sorted(S.begin(), S.end())) return "-1";
    int n = S.size();
    for (int i = n - 2; i >= 0; --i) {
      if (S[i] > S[i + 1]) {
        int j = i + 1;
        int v = S[j];
        for (int k = j + 1; k < n; ++k) {
          if (S[k] > v && S[k] < S[i]) {
            j = k;
            v = S[k];
          }
        }
        // cout << i << ' ' << j << endl;
        swap(S[i], S[j]);
        if (S[0] == '0') return "-1";
        return S;
      }
    }
    return "-1";
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
    cout << ob.previousNumber(S) << endl;
  }
  return 0;
}
// } Driver Code Ends
