//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{
    
    public:
    int maxCandy(int height[], int n) 
    { 
        // Your code goes here
        int ans = 0;
        int i = 0, j = n - 1;
        while(i < j) {
            ans = max(ans, min(height[i], height[j]) * (j - i - 1));
            if (height[i] < height[j]) {
                ++i;
            } else if (height[i] > height[j]) {
                --j;
            } else {
                ++i;
                --j;
            }
        }
        return ans;
    }   
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	int height[n];
    	for (int i = 0; i < n; ++i)
    	{
    		cin>>height[i];
    	}
    	
    	Solution obj;
    	
    	cout << obj.maxCandy(height,n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
