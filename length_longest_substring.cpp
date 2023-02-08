//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int longestUniqueSubsttr(string S){
        //code
        int c[26] = {0};
        int j = 0;
        int ans = 1;
        for(int i = 0; i < S.size(); ++i) {
            if (c[S[i]-'a'] == 0) {
                c[S[i]-'a'] = 1;
            } else {
                ans = max(i-j, ans);
                while(S[j] != S[i]) {
                    c[S[j]-'a']--;
                    ++j;
                }
                ++j;
                
            }
        }
        ans = max((int)S.size() - j, ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends
