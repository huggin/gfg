//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int longestSubstrDistinctChars (string S)
{
    // your code here
    unordered_map<char, int> m;
    int ans = 0;
    int j = -1;
    for(int i = 0; i < S.size(); ++i) {
        if (m[S[i]] == 1) {
            while(S[++j] != S[i]) {
                m[S[j]]--;
            }
            m[S[i]]--;
        }
        m[S[i]]++;
        //cout << i << ' ' << j << endl;
        ans = max(ans, i - j);
    }
    ans = max(ans, int(S.size() -1 - j ));
    return ans;
}
