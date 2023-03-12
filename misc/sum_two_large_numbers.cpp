//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution {
 public:
  string findSum(string X, string Y) {
    // Your code goes here
    reverse(begin(X), end(X));
    reverse(begin(Y), end(Y));
    char ans[100001] = {0};
    int more = 0;
    int i = 0;
    for (; i < X.size() && i < Y.size(); ++i) {
      int t = more + ans[i] + X[i] - '0' + Y[i] - '0';
      if (t >= 10) {
        more = 1;
        ans[i] = t - 10;
      } else {
        more = 0;
        ans[i] = t;
      }
    }
    for (; i < X.size(); ++i) {
      int t = more + ans[i] + X[i] - '0';
      if (t >= 10) {
        more = 1;
        ans[i] = t - 10;
      } else {
        ans[i] = t;
        more = 0;
      }
    }
    for (; i < Y.size(); ++i) {
      int t = more + ans[i] + Y[i] - '0';
      if (t >= 10) {
        more = 1;
        ans[i] = t - 10;
      } else {
        ans[i] = t;
        more = 0;
      }
    }
    int n = i;
    if (more == 1) {
      ans[i] = 1;
      n = i + 1;
    }
    int len = 0;
    for (int i = n - 1; i >= 0; --i) {
      if (ans[i] != 0) {
        len = i + 1;
        break;
      }
    }
    if (len == 0) return "0";
    string s(len, ' ');
    for (int j = len - 1; j >= 0; --j) {
      s[len - 1 - j] = ans[j] + '0';
    }

    return s;
  }
};

//{ Driver Code Starts.

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    string x, y;
    cin >> x >> y;
    Solution ob;
    cout << ob.findSum(x, y) << "\n";
  }

  return 0;
}
// } Driver Code Ends
