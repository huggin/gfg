//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
public:
  char nthCharacter(string S, int R, int N) {
    // code here
    int num = pow(2, R);
    int a = (N) / num;
    int b = (N) % num;
    string c = S.substr(a, 1);
    // cout << c << endl;

    for (int i = 0; i < R; ++i) {
      string t;
      t.reserve(c.size() * 2);
      for (int j = 0; j < c.size(); ++j) {
        if (c[j] == '0') {
          t += "01";
        } else {
          t += "10";
        }
      }
      c = t;
    }
    // cout << c << endl;
    return c[b];
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int R, N;
    string S;
    cin >> S >> R >> N;
    Solution ob;
    cout << ob.nthCharacter(S, R, N) << endl;
  }
  return 0;
}
// } Driver Code Ends
