//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
public:
  string lookandsay(int n) {
    // code here
    string s = "1";
    for (int i = 1; i < n; ++i) {
      int j = 0;
      string t;
      while (j < s.size()) {
        int k = j;
        for (; k < s.size(); ++k) {
          if (s[k] != s[j]) {
            break;
          }
        }
        t += (k - j) + '0';
        t += s[j];
        j = k;
      }
      s = t;
    }
    return s;
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    Solution obj;
    cout << obj.lookandsay(n) << endl;
  }
  return 0;
}
// } Driver Code Ends
