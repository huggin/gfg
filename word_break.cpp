//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
    string a;
    int dp[1101];
    
    bool start(int k, const string& s) {
        if (a.size() - k < s.size()) return false;
        for(int i = 0; i < s.size(); ++i) {
            if (s[i] != a[k+i]) return false;
        }
        return true;
    }
    int solve(int k, vector<string>& b) {
        //cout << "k = " << k << endl;
        if (k == a.size()) return 1;
        if (dp[k] != -1) return dp[k];
        dp[k] = 0;
        for(int i = 0; i < b.size(); ++i) {
            if (start(k, b[i])) {
                dp[k] |= solve(k+b[i].size(), b);
            }
        }
        //cout << k << ' ' << dp[k] << endl;
        return dp[k];
    }
public:
    int wordBreak(string A, vector<string> &B) {
        //code here
        memset(dp, -1, sizeof(dp));
        a = A;
        return solve(0, B);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends
