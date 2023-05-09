//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
  int checkRedundancy(string s) {
    // code here
    stack<pair<char, int>> S;
    int left = -2, right = -2;
    bool flag = false;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '(') {
        S.emplace('(', i);
        flag = false;
      } else if (s[i] == ')') {
        if (flag == false)
          return 1;
        auto c = S.top();
        S.pop();
        if (c.second == left - 1 && i == right + 1) {
          return 1;
        }
        left = c.second;
        right = i;

      } else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
        flag = true;
      }
    }
    return 0;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    string s;
    cin >> s;

    Solution obj;
    int res = obj.checkRedundancy(s);

    cout << res << endl;
  }
}

// } Driver Code Ends
