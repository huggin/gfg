//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    long countSubarrays(int a[], int n, int L, int R)
    {
        // Complete the function
        long ans = 0;
        int i = 0, j = 0;
        int window = 0;
        while(i < n) {
            if (a[i] >= L && a[i] <= R) {
                window = i - j + 1;
            } else if (a[i] > R) {
                window = 0;
                j = i+1;
            }
            ans += window;
            ++i;
        }
        return ans;
    }
};

//{ Driver Code Starts.
// driver program
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        
        int n ,l,r;
        cin >> n>>l>>r;
        int a[n];
        for(int i=0;i<n;i++)
        cin >> a[i];
        Solution ob;
    	cout << ob.countSubarrays(a, n, l, r)<<endl;
    }
	return 0;
}

// } Driver Code Ends
