//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
        string ans;
        string::size_type st = S.rfind('.');
        string::size_type st2 = S.size();
        while(st != string::npos) {
            ans += S.substr(st + 1, st2 - st) + '.';
            st2 = st - 1;
            st = S.rfind('.', st - 1);
        }
        ans += S.substr(0, st2+1);
        return ans;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends
