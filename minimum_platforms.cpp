//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	vector<pair<int, int>> t;
    	for(int i = 0; i < n; ++i) {
    	    t.push_back(make_pair(dep[i], arr[i]));
    	}
    	sort(t.begin(), t.end(), [](pair<int, int> left, pair<int, int> right) { 
    	   if (left.second < right.second) return 1;
    	   if (left.second > right.second) return 0;
    	   if (left.first < right.first) return 1;
    	   return 0;
    	});
    	
    	priority_queue<
    	    pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>
    	> P;
    	P.push(t[0]);
    	int ans = 1;
    	for(int i = 1; i < n; ++i) {
    	    auto temp = P.top();
    	    if (temp.first < t[i].second) {
    	       P.pop();
    	       --ans;
    	    } 
    	    P.push(t[i]);
    	    ++ans;
    	}
    	return ans;
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends
