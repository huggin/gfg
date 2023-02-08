//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    string findAndReplace(string S ,int Q, int index[], string sources[], string targets[]) {
        // code here
        string ans;
        ans.reserve(S.size() * 10);
        int start = 0;
        for(int i = 0; i < Q; ++i) {
            string t = S.substr(start, index[i]-start);
            ans += t;
            if (S.find(sources[i], index[i]) == index[i]) {
                ans += targets[i];
                start = index[i]+sources[i].size();
            } else {
                start = index[i];
            }
        }
        ans += S.substr(start);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        
        int Q;
        cin>>Q;
        int index[Q];
        string sources[Q], targets[Q];
        
        for(int i=0; i<Q; i++)
            cin>>index[i];
        for(int i=0; i<Q; i++)
            cin>>sources[i];
        for(int i=0; i<Q; i++)
            cin>>targets[i];

        Solution ob;
        cout<<ob.findAndReplace(S,Q,index,sources,targets)<<endl;
    }
    return 0;
}
// } Driver Code Ends
