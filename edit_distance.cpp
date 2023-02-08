//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    int mem[101][101];

    int dp(const string& s, const string& t, int i, int j) 
    {
        if (i == s.size()) {
            return t.size() - j;
        }
        if (j == t.size()) {
            return s.size() - i;
        }
        if (mem[i][j] != -1) {
            return mem[i][j];
        }
        int& ans = mem[i][j];
        if (s[i] == t[j]) {
            ans = dp(s, t, i+1, j+1);
        } else {
            ans = dp(s, t, i+1, j+1) + 1;
            ans = min(ans, dp(s, t, i, j+1) + 1);
            ans = min(ans, dp(s, t, i+1, j) + 1);
        }
        return ans;
    }
  public:
    int editDistance(string s, string t) {
        // Code here
        memset(mem, -1, sizeof(mem));
        return dp(s, t, 0, 0);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
