//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  int solve(string s) {
    // Your code goes here
    s.push_back('%');
    int m = s.size();
    vector<int> next(m);
    int j = -1;
    for (int i = 0; i < m; i++) {
      if (i == 0)
        next[i] = -1;
      else if (s[i] != s[j])
        next[i] = j;
      else
        next[i] = next[j];
      while (j >= 0 && s[i] != s[j]) {
        j = next[j];
      }
      j++;
    }
    return next[m - 1];
  }

public:
  int minChar(string str) {
    // Write your code here
    string s(str);
    s.push_back('$');
    copy(str.rbegin(), str.rend(), back_inserter(s));

    return str.size() - solve(s);
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    string str;
    cin >> str;
    Solution ob;
    int ans = ob.minChar(str);
    cout << ans << endl;
  }
  return 0;
}

// } Driver Code Ends
