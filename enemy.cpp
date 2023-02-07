//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
        int largestArea(int n,int m,int k,vector<vector<int>> &enemy)
        {
            //  code here
            if (k == 0) return n * m;
            
            vector<int> v1(k+1), v2(k+1);
            for(int i = 0; i < k; ++i) {
                v1[i] = enemy[i][0];
                v2[i] = enemy[i][1];
            }
            v1[k] = n+1;
            v2[k] = m+1;
            sort(v1.begin(), v1.end());
            sort(v2.begin(), v2.end());
            
            int x = 0, y = 0;
            for(int i = 0; i < k+1; ++i) {
                if (i == 0) {
                    x = max(x, v1[0] - 1);
                } else {
                    x = max(x, v1[i] - v1[i-1] - 1);
                }
            }

            for(int j = 0; j < k+1; ++j) {
                if (j == 0) {
                    y = max(y, v2[0] - 1);
                } else {
                    y = max(y, v2[j] - v2[j-1] - 1);
                }
            }
            
            return x * y;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int k;
        cin>>k;
        vector<vector<int>> e(k,vector<int>(2));
        for(int i=0;i<k;i++)
            cin>>e[i][0]>>e[i][1];
        Solution a;
        cout<<a.largestArea(n,m,k,e)<<endl;
    }
    return 0;
}
// } Driver Code Ends
