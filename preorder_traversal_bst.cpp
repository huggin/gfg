//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
    vector<int> dp;
    
    int solve(int a[], int i, int j, int hi, int lo) {
        if (i > j) return 1;
        if (i == j) return a[i] > lo && a[i] < hi;
        if (a[i] < lo || a[i] > hi) return 0;
        
        if (dp[i] == -1) {
            return solve(a, i+1, j, a[i], lo);
        }
        
        return solve(a, i+1, dp[i]-1, a[i], lo) && solve(a, dp[i], j, hi, a[i]);
    }
  public:
    int canRepresentBST(int arr[], int N) {
        // code here
        dp.assign(N, -1);
        stack<int> S;
        S.push(N-1);
        for(int i = N-2; i>=0; --i) {
            while (!S.empty() && arr[i] > arr[S.top()]) {
                S.pop();
            } 
            if (S.empty()) {
                dp[i] = -1;
            } else {
                dp[i] = S.top();
            }
            S.push(i);
        }
        
        return solve(arr, 0, N-1, INT_MAX, INT_MIN);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];
        Solution ob;
        cout << ob.canRepresentBST(arr, N) << endl;
    }
    return 0;
}
// } Driver Code Ends
