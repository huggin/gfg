//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int countRev(string s);
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    cout << countRev(s) << '\n';
  }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends

int countRev(string s) {
  // your code here
  if (s.size() % 2 == 1) return -1;
  stack<char> S;
  int ans = 0;
  for (auto c : s) {
    if (S.empty()) {
      if (c == '}') {
        ++ans;
      }
      S.push('{');
    } else {
      if (c == '{') {
        S.push('{');
      } else {
        S.pop();
      }
    }
  }
  ans += S.size() / 2;
  return ans;
}
