//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        // code here
        unordered_map<int, int> m;
        unordered_map<int, int> v;
        for(int i = 0; i<n; ++i) {
            m[arr[i]]++;
        }
        int ans = 0;

        for(auto it=m.begin(); it!=m.end(); ++it) {
            if (v[it->first]) continue;
            if (it->first == k - it->first) {
                ans += it->second * (it->second - 1) /2;
                v[it->first] = 1;
            } else {
                if (m.find(k-it->first) != m.end()) {
                    ans += it->second * m[k-it->first];
                }
                v[it->first] = 1;
                v[k-it->first] = 1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }
    
    return 0;
}
// } Driver Code Ends
