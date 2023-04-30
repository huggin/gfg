//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
public:
  /*You are required to complete this method */
  int atoi(string str) {
    // Your code here
    int ans = 0;
    int f = 1;
    bool first = true;
    for (int i = 0; i < str.size(); ++i) {
      if (str[i] == '-') {
        if (first) {
          f = -1;
          first = false;
        } else {
          return -1;
        }
      } else if (str[i] >= '0' && str[i] <= '9') {
        ans = ans * 10 + str[i] - '0';
      } else {
        return -1;
      }
    }
    return f * ans;
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
    cout << ob.atoi(s) << endl;
  }
}
// } Driver Code Ends
