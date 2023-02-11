//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
 public:
  int findIndex(string str) {
    // Your code goes here
    vector<int> v(str.size() + 1), v2(str.size() + 1);
    v[0] = 0;
    for (int i = 1; i <= str.size(); ++i) {
      if (str[i - 1] == '(') {
        v[i] = v[i - 1] + 1;
      } else {
        v[i] = v[i - 1];
      }
    }
    int n = str.size();
    v2[n] = 0;
    for (int i = n - 1; i >= 0; --i) {
      if (str[i] == ')') {
        v2[i] = v2[i + 1] + 1;
      } else {
        v2[i] = v2[i + 1];
      }
    }
    for (int i = 0; i <= n; ++i) {
      if (v[i] == v2[i]) return i;
    }
    return -1;
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    Solution ob;
    cout << ob.findIndex(s) << endl;
  }
}
// } Driver Code Ends
