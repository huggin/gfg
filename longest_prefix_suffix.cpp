//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function template for C++

class Solution {
 public:
  int lps(string s) {
    // Your code goes here
    s.push_back('$');
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
};

//{ Driver Code Starts.

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    string str;
    cin >> str;

    Solution ob;

    cout << ob.lps(str) << "\n";
  }

  return 0;
}

// } Driver Code Ends
