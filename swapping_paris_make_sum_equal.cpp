//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int findSwapValues(int A[], int n, int B[], int m)
	{
        // Your code goes here
        sort(A, A+n);
        sort(B, B+m);
        int ta = accumulate(A, A+n, 0);
        int tb = accumulate(B, B+m, 0);
        //cout << ta << ' ' << tb << endl;
        if ((abs(ta - tb)) % 2 == 1) return -1;
        int t = (ta - tb) / 2;

        for(int i = 0; i < n; ++i) {
            //cout << i << ' ' << A[i] - t << endl;
            if (binary_search(B, B+m, A[i] - t)) return 1;
        }
        return -1;
	}

};

//{ Driver Code Starts.

int main() 
{
   	
   	int t;
    cin >> t;
    while (t--)
    {
    	int n,m;
        cin>>n>>m;
        int a[n];
        int b[m];
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<m;i++)
            cin>>b[i];
        

        Solution ob;
        cout <<  ob.findSwapValues(a, n, b, m);
	    cout << "\n";
	     
    }
    return 0;
}






// } Driver Code Ends
