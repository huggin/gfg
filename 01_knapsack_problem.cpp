//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    int mem[1001][1001];
    int len;
    
    int dp(int w, int wt[], int val[], int k) {
        if (k == len) {
            return 0;
        }
        if (mem[w][k] != -1) {
            return mem[w][k];
        }
        int& ans = mem[w][k];
        ans = dp(w, wt, val, k+1);
        if (w >= wt[k]) {
            ans = max(ans, dp(w-wt[k], wt, val, k+1) + val[k]);
        }
        return ans;
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       memset(mem, -1, sizeof(mem));
       len = n;
       return dp(W, wt, val, 0);
    }
};


//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends
