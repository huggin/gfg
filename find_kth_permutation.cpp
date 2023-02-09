//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    string kthPermutation(int n, int k)
    {
        // code here
        --k;
        vector<int> dp(n);
        dp[0] = 1;
        for(int i = 1; i < n; ++i) {
            dp[i] = dp[i-1] * i;
        }
        set<char> s;
        for(int i = 1; i <= n; ++i) {
            s.insert(i);
        }
        string ans;
        int i = n-1;
            for(int i = n-1; i>=0; --i) {
                int t = k / dp[i];
                k = k % dp[i];
                for(auto it=s.begin(); it != s.end(); ++it) {
                    if (t-- == 0) {
                        ans += (*it) + '0';
                        s.erase(it);
                        break;
                    }
                }
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
        int n, k;
        cin >> n >> k;
        Solution ob;
        string ans = ob.kthPermutation(n, k);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
