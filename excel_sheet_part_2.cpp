//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
 public:
  int ExcelColumnNumber(string s) {
    // Your code goes here
    int ans = 0;
    reverse(s.begin(), s.end());
    for (int i = 0; i < s.size(); ++i) {
      ans += (s[i] - 'A' + 1) * pow(26, i);
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
    cout << ob.ExcelColumnNumber(s) << endl;
  }
}
// } Driver Code Ends
