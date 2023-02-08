//{ Driver Code Starts
// C++ program to find all distinct palindrome sub-strings
// of a given string
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
  public:
    int palindromeSubStrs(string s) {
        // code here
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        unordered_set<string> S;
        for(int i = 0; i < n; ++i) {
            dp[i][i] = 1;
            string t = s.substr(i, 1);
            if (S.find(t) == S.end()) {
                S.insert(t);
            }
        }
        for(int k = 1; k < n; ++k) {
            for(int i = 0; i + k < n; ++i) {
                int j = i+k;
                if (k == 1 && s[i]==s[j] ||
                    k > 1 && s[i]==s[j] && dp[i+1][j-1] == 1) {
                        dp[i][j] = 1;
                        string t = s.substr(i, j - i + 1);
                        if (S.find(t) == S.end()) {
                            S.insert(t);
                        }
                    }
            }
        }
        return S.size();
    }
};

//{ Driver Code Starts.

// Driver program
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.palindromeSubStrs(str) << endl;
    }
    return 0;
}

// } Driver Code Ends
