//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
 public:
  int romanToDecimal(string &str) {
    // code here
    int ans = 0;
    for (int i = 0; i < str.size(); ++i) {
      if (str[i] == 'M') {
        ans += 1000;
      } else if (str[i] == 'D') {
        ans += 500;
      } else if (str[i] == 'C') {
        if (i + 1 < str.size() && (str[i + 1] == 'D' || str[i + 1] == 'M')) {
          ans -= 100;
        } else {
          ans += 100;
        }
      } else if (str[i] == 'L') {
        ans += 50;
      } else if (str[i] == 'X') {
        if (i + 1 < str.size() && (str[i + 1] == 'L' || str[i + 1] == 'C')) {
          ans -= 10;
        } else {
          ans += 10;
        }
      } else if (str[i] == 'V') {
        ans += 5;
      } else {
        if (i + 1 < str.size() && (str[i + 1] == 'V' || str[i + 1] == 'X')) {
          ans -= 1;
        } else {
          ans += 1;
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
    string s;
    cin >> s;
    Solution ob;
    cout << ob.romanToDecimal(s) << endl;
  }
}
// } Driver Code Ends
