//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long int nthFibonacci(long long int n){
        // code here
        vector<long long> v(n+1);
        v[1] = 1;
        v[2] = 1;
        for(int i=3; i<=n; ++i) {
            v[i] = (v[i-2] + v[i-1]) % 1000000007;
        }
        return v[n];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends
