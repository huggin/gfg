//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    bool isv(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    set<string> ans;
    int n;
    string S;
    void solve(int k, string& s) {
        if (k == n) {
            if (s.size() != 0 && !isv(s[s.size() - 1])) {
                ans.insert(s);
            }
            return;
        }
        if (s.empty()) {
            if (isv(S[k])) {
                s.push_back(S[k]);
                solve(k+1, s);
                s.pop_back();
            }
            solve(k+1, s);
        } else {
            s.push_back(S[k]);
            solve(k+1, s);
            s.pop_back();
            solve(k+1, s);
        }
    }
  public:
    set<string> allPossibleSubsequences(string S2) {
        // code here
        ans.clear();
        S = S2;
        n = S.size();
        string s;
        s.reserve(S.size());
        solve(0, s);
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
        set<string> ans = ob.allPossibleSubsequences(S);
        if (ans.size() == 0)
            cout << -1 << endl;
        else {
            for (auto i : ans) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// } Driver Code Ends
