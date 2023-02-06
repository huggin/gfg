//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    int sumofdigit(long long n) {
        int ans = 0;
        while(n) {
            ans += n % 10;
            n /= 10;
        }
        return ans;
    }
public:
    long long int getCount(long long N, long long D)
    {
        // your code here
        long long lo = 9, hi = N;
        long long ans = 0;
        while(lo <= hi) {
            long long mid = lo+(hi-lo)/2;
            int s = sumofdigit(mid);
            if (mid - s >= D) {
                ans = mid;
                hi = mid-1;
            } else {
                lo = mid+1;
            }
        }
        if (ans == 0) return 0;
        return N - ans + 1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N,D;

        cin>>N>>D;

        Solution ob;
        cout << ob.getCount(N,D) << endl;
    }
    return 0;
}
// } Driver Code Ends
