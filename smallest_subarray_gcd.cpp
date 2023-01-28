//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{  
    vector<int> st;
    
    void buildTree(int arr[], int n) {
        st.assign(2*n-1, 0);
        for(int i = 0; i < n; ++i) {
            st[i+n] = arr[i];
        }
        for(int i = n-1; i>=1; --i) {
            st[i] = __gcd(st[i*2], st[i*2+1]);
        }
    }
    
    int queryTree(int l, int r, int n) {
        int ans = 0;
        l += n, r += n;
        while(l < r) {
            if (l&1) ans = __gcd(ans, st[l++]);
            if (r&1) ans = __gcd(ans, st[--r]);
            l/=2, r/=2;
        }
        return ans;
    }
public:
    int findSmallestSubArr(int arr[], int n, int g) {
        // code here
        for(int i = 0; i < n; ++i) {
            if (arr[i] == g) return 1;
        }
        buildTree(arr, n);
        int ans = INT_MAX;
        for(int i = 0; i < n-1; ++i) {
            int l=2, r=n-i;
            while(l<=r) {
                int mid = l+(r-l)/2;
                int v = queryTree(i, i+mid, n);
                if (v == g) {
                    ans = min(ans, mid);
                    r = mid - 1;
                } else if (v < g) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
        }
        return ans==INT_MAX ? -1:ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, g;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> g;
        Solution ob;
        auto ans = ob.findSmallestSubArr(arr, n, g);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
