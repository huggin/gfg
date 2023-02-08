//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    long long findRank(string str) {
        //code here
        long long ans = 0;
        int n = str.size();
        vector<long long> dp(str.size());
        dp[0] = 1;
        for(int i = 1; i < n; ++i) {
            dp[i] = dp[i-1] * i;
        }
        string s = str;
        list<char> S;
        for(auto c: str) {
            S.push_back(c);
        }
        S.sort();
        
        for(int i = 0; i < n; ++i) {
            int count = 0;
            list<char>::iterator it;
            for(it = S.begin(); it != S.end(); ++it) {
                if (*it == s[i]) {
                    break;
                } else {
                    ++count;
                }
            }
            ans += (count) * dp[n-1-i];
            S.erase(it);
        }
        return ans+1;
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        Solution obj;
        long long ans = obj.findRank(s);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends
