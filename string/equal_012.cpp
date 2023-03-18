//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
 public:
  long long getSubstringWithEqual012(string str) {
    // code here
    unordered_map<int, int> m;
    m[0] = 1;
    int c[2] = {0};
    long long ans = 0;
    for (int i = 0; i < str.size(); ++i) {
      if (str[i] == '0') {
        c[0]++;
        c[1]++;
      } else if (str[i] == '1') {
        c[0]--;
      } else {
        c[1]--;
      }
      ans += m[c[0] * 100001 + c[1]];
      m[c[0] * 100001 + c[1]]++;
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
    cout << ob.getSubstringWithEqual012(s) << endl;
  }
  return 0;
}

// } Driver Code Ends
