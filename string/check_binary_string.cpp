//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
  bool checkBinary(string s) {
    // Your Code Here
    int i = 0;
    for (char c : s) {
      if (c == '1') {
        if (i == 2)
          return false;
        i = 1;
      } else {
        if (i == 1)
          i = 2;
      }
    }
    return true;
  }
};

//{ Driver Code Starts.

int32_t main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    Solution ob;
    if (ob.checkBinary(s))
      cout << "VALID\n";
    else
      cout << "INVALID\n";
  }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends
