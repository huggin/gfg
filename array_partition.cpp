//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    vector<int> dp;
    int n, m, k;
    vector<int> a;
    
    int solve(int i) {
        if (i >= n) return 1;
        if (dp[i] != -1) return dp[i];
        
        dp[i] = 0;
        if (i+k-1 >= n || a[i+k-1] - a[i] > m) return dp[i];
        for(int j = i+k-1; j<n; ++j) {
            if (a[j] - a[i] <= m) {
                dp[i] |= solve(j+1);
                if (dp[i]) return dp[i];
            } else {
                break;
            }
        }
        return dp[i];
    }
    
    public:
    bool partitionArray(int N, int K, int M, vector<int> &A){
        // code here
        dp.assign(N, -1);
        a = A;
        sort(a.begin(), a.end());
        
        n = N;
        m = M;
        k = K;
        return solve(0);
    }
};

//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, K, M;
        cin >> N >> K >> M;
        vector<int> A(N);
        for(int i = 0; i < N; i++){
            cin >> A[i];
        }
        Solution obj;
        bool ans = obj.partitionArray(N, K, M, A);
        if(ans){
            cout << "YES\n";
        }
        else{
            cout<< "NO\n";
        }
    }
}

// } Driver Code Ends
