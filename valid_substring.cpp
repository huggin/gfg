//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for c++
class Solution {
  public:
    int findMaxLen(string s) {
        // code here
        stack<pair<int, char>> S;
        vector<int> dp(s.size());
        for(int i = 0; i < s.size(); ++i) {
            if (S.empty()) {
                if (s[i] == ')') continue;
                S.emplace(i, s[i]);
            } else {
                if (s[i] == '(') {
                    S.emplace(i, s[i]);
                } else {
                    if (!S.empty()) {
                        auto c = S.top();
                        S.pop();
                        if (c.first == 0) {
                            dp[i] = i + 1;
                        } else {
                            dp[i] = i - c.first + 1 + dp[c.first - 1];
                        }
                    }
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < dp.size(); ++i) {
            //cout << i << ' ' << dp[i] << endl;
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S; 
        Solution ob;
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}

// } Driver Code Ends
