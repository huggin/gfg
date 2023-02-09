//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
        int cnt[26] = {0};
        for(char c : s) {
            cnt[c-'a']++;
        }
        
        int ans = min(cnt[0], cnt[1]);
        ans = min(ans, cnt['n'-'a']);
        ans = min(ans, min(cnt['l'-'a']/2, cnt['o'-'a']/2));
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends
