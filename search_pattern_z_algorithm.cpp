//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    vector<int> z_function(const string& s) {
        int n = (int) s.length();
        vector<int> z(n);
        for (int i = 1, l = 0, r = 0; i < n; ++i) {
            if (i <= r)
                z[i] = min (r - i + 1, z[i - l]);
            while (i + z[i] < n && s[z[i]] == s[i + z[i]])
                ++z[i];
            if (i + z[i] - 1 > r)
                l = i, r = i + z[i] - 1;
        }
        return z;
    }

    public:
    vector <int> search(string pat, string txt)
    {
        //code hee.
        string combined = pat + "$" + txt;
        vector<int> z = z_function(combined);
        vector<int> ans;
        int plen = pat.size();
        for (int i = 0; i < z.size(); i++) {
            if (z[i] == plen) ans.push_back(i - plen);
        }
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
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if(res.size()==0)
            cout<<"-1 ";
        else
            for (int i : res)
                cout << i << " ";
        cout << endl;
    }
    return 0;
}


// } Driver Code Ends
