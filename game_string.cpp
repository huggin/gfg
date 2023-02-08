//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        // code here
        int count[26] = {0};
        for(int i = 0; i < s.size(); ++i) {
            ++count[s[i]-'a'];
        }
        multiset<int> ms;
        for(int i = 0; i < 26; ++i) {
            if (count[i] != 0) {
                ms.insert(count[i]);
            }
        }
        for(int i=0; i<k; ++i) {
            multiset<int>::iterator it = ms.end();
            --it;
            int temp = *it;
            ms.erase(it);
            ms.insert(temp-1);
        }
        int ans = 0;
        for(auto item : ms) {
            ans += item * item;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
