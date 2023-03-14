//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution {
 public:
  string removeDuplicates(string str) {
    // code here
    string s;
    unordered_map<char, int> m;
    for (int i = 0; i < str.size(); ++i) {
      if (m[str[i]] == 0) {
        s += str[i];
        m[str[i]] = 1;
      }
    }
    return s;
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
    auto ans = ob.removeDuplicates(str);

    cout << ans << "\n";
  }
  return 0;
}
// } Driver Code Ends
