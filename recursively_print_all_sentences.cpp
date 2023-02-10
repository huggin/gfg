//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    vector<vector<string>> ans;
    int n;
    void go(vector<vector<string>>&list, int k, vector<string>& t) {
        if (k == n) {
            ans.push_back(t);
            return;
        }
        for(int i=0; i<list[k].size(); ++i) {
            t.push_back(list[k][i]);
            go(list, k+1, t);
            t.pop_back();
        }
    }
    public:
    vector<vector<string>> sentences(vector<vector<string>>&list){
        //Write your code here
        ans.clear();
        n = list.size();
        vector<string> t;
        go(list, 0, t);
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
	int t = 1;
	//cin>>t;
	while(t--)
	{
	    int m, n;
	    cin >> m >> n;
	    vector<vector<string>>list(m, vector<string>(n));
	    for(int i = 0 ; i < m; i++){
	        for(int j = 0; j < n; j++){
	            cin >> list[i][j];
	        }
	    }
	    Solution ob;
	    vector<vector<string>>ans = ob.sentences(list);
	    for(auto it : ans){
	        for(auto it1 : it){
	            cout << it1 << " ";
	        }
	        cout << endl;
	    }
	}
	return 0;
}

// } Driver Code Ends
