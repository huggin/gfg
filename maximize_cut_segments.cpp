//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution
{
    int mem[10001][3];
    int oo = 1000000;
    
    int dp(int n, int k, const vector<int>& v) {
        if (n == 0) {
            return 0;
        }
        if (k == 3) {
            return -oo;
        }
        if (mem[n][k] != -1) {
            return mem[n][k];
        }
        int& ans = mem[n][k];
        ans = dp(n, k+1, v);
        
        if (n >= v[k]) {
            ans = max(ans, dp(n-v[k], k, v) + 1);
        }
        return ans;
    }
    
public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        memset(mem, -1, sizeof(mem));
        vector<int> v{x, y, z};

        int ans = dp(n, 0, v);
        if (ans < 0) return 0;
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends
