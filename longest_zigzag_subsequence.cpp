//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
	int ZigZagMaxLength(vector<int>&nums){
		vector<int> dp[2];
		int n = nums.size();
		dp[0].resize(n);
		dp[1].resize(n);
		dp[0][0] = 1;
		dp[1][0] = 1;
		for(int i = 1; i < n; ++i) {
		    if (nums[i] > nums[i-1]) {
		        dp[0][i] = dp[1][i-1] + 1;
		        dp[1][i] = dp[1][i-1];
		    } else if (nums[i] < nums[i-1]) {
		        dp[1][i] = dp[0][i-1] + 1;
		        dp[0][i] = dp[0][i-1];
		    } else {
		        dp[1][i] = dp[1][i-1];
		        dp[0][i] = dp[0][i-1];
		    }
		}
		return max(dp[0][n-1], dp[1][n-1]);
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.ZigZagMaxLength(nums);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
