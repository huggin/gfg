//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
 public:
  int getCarries(string N, string M) {
    // code here
    int ans = 0;
    int carry = 0;
    int n = N.size();
    int m = M.size();
    for (int i = n - 1, j = m - 1; i >= 0 || j >= 0; --i, --j) {
      if (j < 0) {
        carry = N[i] - '0' + carry;
        if (carry >= 10) {
          ++ans;
          carry = 1;
        } else {
          break;
        }
      } else if (i < 0) {
        carry = M[j] - '0' + carry;
        if (carry >= 10) {
          ++ans;
          carry = 1;
        } else {
          break;
        }
      } else {
        carry = N[i] - '0' + M[j] - '0' + carry;
        if (carry >= 10) {
          ++ans;
          carry = 1;
        } else {
          carry = 0;
        }
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
    string N, M;

    cin >> N >> M;

    Solution ob;
    cout << ob.getCarries(N, M) << endl;
  }
  return 0;
}
// } Driver Code Ends
