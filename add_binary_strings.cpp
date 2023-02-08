//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	string addBinary(string A, string B)
	{
	    // your code here
	    reverse(A.begin(), A.end());
	    reverse(B.begin(), B.end());
	    string ans;
	    int more = 0;
	    int i = 0;
	    for(; i < A.size() && i < B.size(); ++i) {
	        if (A[i] - '0' + B[i] - '0' + more == 0) {
	            ans += '0';
	            more = 0;
	        } else if (A[i] - '0' + B[i] - '0' + more  == 1) {
	            ans += '1';
	            more = 0;
	        } else {
	            ans += A[i] - '0' + B[i] - '0' + more - 2 + '0';
	            more = 1;
	        }
	    }
	    while(i < A.size()) {
	        if (A[i] - '0' + more == 0) {
	            ans += '0';
	            more = 0;
	        } else if (A[i] - '0' + more == 1) {
	            ans += '1';
	            more = 0;
	        } else {
	            ans += A[i] - '0' + more - 2 + '0';
	            more = 1;
	        }
	        ++i;
	    }
	    while(i < B.size()) {
	        if (B[i] - '0' + more == 0) {
	            ans += '0';
	            more = 0;
	        } else if (B[i] - '0' + more == 1) {
	            ans += '1';
	            more = 0;
	        } else {
	            ans += B[i] - '0' + more - 2 + '0';
	            more = 1;
	        }
	        ++i;
	    }
	    if (more) {
	        ans += '1';
	    }
	    while(ans[ans.size() - 1] == '0') {
	        ans.resize(ans.size() - 1);
	    }
	    reverse(ans.begin(), ans.end());
	    return ans;
	}
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		string A, B; cin >> A >> B;
		Solution ob;
		cout << ob.addBinary (A, B);
		cout << "\n";
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends
