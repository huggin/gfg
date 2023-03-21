//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  long long count(const string &s, char a, char b, int X, int Y) {
    stack<char> S;
    long long ans = 0;
    for (char c : s) {
      if (!S.empty() && S.top() == a && c == b) {
        ++ans;
        S.pop();
      } else {
        S.push(c);
      }
    }
    ans *= X;
    stack<char> S2;
    while (!S.empty()) {
      char c = S.top();
      S.pop();
      if (!S2.empty() && S2.top() == a && c == b) {
        ans += Y;
        S2.pop();
      } else {
        S2.push(c);
      }
    }
    return ans;
  }

public:
  long long solve(int X, int Y, string S) {
    // code here
    // cout << count(S, 'r', 'p', Y, X) << endl;
    // cout << count(S, 'p', 'r', X, Y) << endl;
    return max(count(S, 'r', 'p', Y, X), count(S, 'p', 'r', X, Y));
  }
};

//{ Driver Code Starts.
signed main() {
  int t;
  cin >> t;
  while (t--) {
    int X, Y;
    cin >> X >> Y;
    string S;
    cin >> S;
    Solution obj;
    long long answer = obj.solve(X, Y, S);
    cout << answer << endl;
  }
}
// } Driver Code Ends
