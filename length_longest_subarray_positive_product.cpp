//{ Driver Code Starts
//Initial Template for C++



#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
        // Function to return the length of the
        //longest subarray with ppositive product
    int maxLength(vector<int> &arr,int n){
        //code here
        int j = 0;
        int i = 0;
        int ans = 0;
        int sign = 0;
        for(int i = 0; i < n; ++i) {
            if (arr[i] == 0) {
                if (sign < 0) {
                    while(j < i && arr[j++] > 0);
                    ans = max(ans, i - j);
                }
                sign = 0;
                j = i+1;
            } else if (arr[i] < 0) {
                sign = sign == 0?-1:-sign;
            } else {
                sign = sign == 0?1:sign;
            }

            if (sign>0) {
                ans = max(ans, i - j + 1);
            }
        }
        if (sign < 0) {
            while(j < n && arr[j++] > 0);
            ans = max(ans, n - j);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> arr(n);
	    for(int i = 0;i<n;i++){
	        cin>>arr[i];
	    }
	    Solution ob;
	    int res = ob.maxLength(arr,n);
	    cout<<res<<"\n";
	}
	return 0;
}
// } Driver Code Ends
