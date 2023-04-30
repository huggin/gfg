//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
  int solve(int n, string s) {
    // code here
    int ans = 0;
    int k = 0;
    int c[26] = {0};
    for (int i = 0; i < s.size(); ++i) {
      if (c[s[i] - 'A'] == 1) {
        c[s[i] - 'A'] = 0;
        --k;
      } else if (c[s[i] - 'A'] == -1) {
        c[s[i] - 'A'] = 0;
      } else {
        if (k < n) {
          c[s[i] - 'A'] = 1;
          ++k;
        } else {
          c[s[i] - 'A'] = -1;
          ++ans;
        }
      }
    }
    return ans;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);

    cin.ignore();
    string s;
    getline(cin, s);

    Solution obj;
    int res = obj.solve(n, s);

    cout << res << endl;
  }
}

// } Driver Code Ends
