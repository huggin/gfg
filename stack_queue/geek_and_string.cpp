//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
  string removePair(string s) {
    // code here
    deque<char> Q;
    for (auto c : s) {
      if (Q.empty() || Q.back() != c) {
        Q.push_back(c);
      } else {
        Q.pop_back();
      }
    }
    if (Q.size() == 0)
      return "-1";
    string ans(Q.begin(), Q.end());
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

    Solution obj;
    string res = obj.removePair(s);

    cout << res << endl;
  }
}

// } Driver Code Ends
