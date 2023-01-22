//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    void sortHalves (int arr[], int n)
    {
        // your code here
        int j = -1;
        for(int i = 1; i < n; ++i) {
            if (arr[i] < arr[i-1]) {
                j = i;
                break;
            }
        }
        if (j == -1) return;
        
        int a[n];
        int i = 0;
        int m = j;
        int k = 0;
        while(i < m || j < n) {
            if (i == m) a[k++] = arr[j++];
            else if (j == n) a[k++] = arr[i++];
            else if (arr[i] <= arr[j]) a[k++] = arr[i++];
            else a[k++] = arr[j++];
            
        }
        
        memcpy(arr, a, sizeof(a));
    }
};

//{ Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
		int arr[n];

		for (int i = 0; i < n; ++i)
			cin >> arr[i];
        
        Solution ob;
        
		ob.sortHalves (arr, n);
		for (int i = 0; i < n; ++i)
			cout << arr[i] << " ";
		cout << endl;
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends
