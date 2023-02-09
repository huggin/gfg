//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    int *a;
    int n;
    vector<vector<int>> mem;
    int dp(int k, int t) {
        if (t == 0) {
            return 1;
        }
        if (k == n) {
            return 0;
        }
        if (mem[k][t] != -1) {
            return mem[k][t];
        }
        int& ans = mem[k][t];
        ans = dp(k+1, t-a[k]) || dp(k+1, t);
        return ans;
    }
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum = accumulate(arr, arr+N, 0);
        if (sum % 2 == 1) {
            return 0;
        }
        sort(arr, arr+N);
        a = arr;
        n = N;
        mem.resize(n);
        for(int i=0; i<n; ++i) {
            mem[i].assign(sum/2+1, -1);
        }
        return dp(0, sum/2);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends
