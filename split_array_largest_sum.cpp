//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    bool ok(int arr[], int N, int k , int mi) {
        int t = 0;
        for(int i = 0; i < N; ++i) {
            t += arr[i];
            if (t > mi) {
                if (--k == 0) return false;
                t = arr[i];
            }
        }
        return true;
    }
  public:
    int splitArray(int arr[] ,int N, int K) {
        // code here
        int hi = accumulate(arr, arr+N, 0);
        int lo = *max_element(arr, arr+N);
        int ans = -1;
        while(lo <= hi) {
            int mi = lo + (hi - lo) / 2;
            if (ok(arr, N, K, mi)) {
                ans = mi;
                hi = mi - 1;
            } else {
                lo = mi + 1;
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
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends
