//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.

    vector<int> subarraySum(const vector<int>& arr, int n, long long S)
    {
        // Your code here
        int i = 0, j = 0;
        long long t = 0;
        while(j < n && t != S) {
            if (t < S) {
                t += arr[j++];
            } else {
                t -= arr[i++];
            }
            if (t == S) {
                return vector<int>{i+1, j};
            }
        }
        while(i < n && t > S) {
            t -= arr[i++];
            if (t == S) {
                return vector<int>{i+1, j};
            }
        }
        
        return vector<int>{-1};
    }
};

//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends
