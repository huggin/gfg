//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
  string reverse(string str) {
    // code here.
    int n = str.size();
    int i = 0, j = n - 1;
    while (true) {
      while (i < n && !isalpha(str[i]))
        ++i;
      while (j >= 0 && !isalpha(str[j]))
        --j;
      if (i < j) {
        swap(str[i], str[j]);
        ++i;
        --j;
      } else {
        break;
      }
    }
    return str;
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
    cout << ob.reverse(s) << endl;
  }
  return 0;
}

// } Driver Code Ends
