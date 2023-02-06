//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    string isBalanced(int a[],int n,int x)
    {
        auto it = lower_bound(a, a+n, x);
        //cout << *it << endl;
        if (it != a+n) {
            if (it == a || it == a+n || *it == x || x - *(it-1) == *it - x)
                return "Balanced";
        }
        return "Not Balanced";
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,x;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    cin>>x;
	Solution ob;
	cout <<ob.isBalanced(arr, n, x)<<endl;
	}
	return 0;	 
}
// } Driver Code Ends
