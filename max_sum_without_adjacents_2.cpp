//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

int dp[1000001][3];
class Solution{
    vector<int> A;
    int n;
    
    int solve(int i, int u) {
        if (i == n) return 0;
        if (dp[i][u] != -1) return dp[i][u];
        int &ans = dp[i][u];
        ans = solve(i+1, 0);
        if (u != 2) {
            ans = max(ans, A[i] + solve(i+1, u+1));
        } 
        return ans;
    }
  public:
  int findMaxSum(vector<int>& a){
      //Code Here
      memset(dp, -1, sizeof(dp));
      A = a;
      n = a.size();
      return solve(0, 0);
  }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        Solution ob;
        int ans = ob.findMaxSum(a);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends
