//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    int days(int a[], int n, int cap) {
        int total = 0;
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            if (total + a[i] > cap) {
                ++ans;
                total = a[i];
            } else {
                total += a[i];
            }
        }
        return ans + 1;
    }
  public:
    int leastWeightCapacity(int arr[], int N, int D) {
        // code here
        int lo = 0, hi = 0;
        for(int i = 0; i < N; ++i) {
            lo = max(arr[i], lo);
            hi += arr[i];
        }
        int ans = -1;
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int d = days(arr, N, mid);
            if (d > D) lo = mid + 1;
            else {
                ans = mid;
                hi = mid - 1;
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
        int N,D;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr,N,D) << endl;
    }
    return 0;
}
// } Driver Code Ends
