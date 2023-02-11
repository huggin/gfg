//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
 public:
  int minimumNumberOfSwaps(string S) {
    // code here
    int ans = 0;
    int right = 0;
    for (int i = 0; i < S.size(); ++i) {
      if (S[i] == ']') {
        ++right;
      } else {
        if (right > 0) {
          ans += right;
        }
        --right;
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
    Solution ob;
    cout << ob.minimumNumberOfSwaps(S) << endl;
  }
  return 0;
}
// } Driver Code Ends
