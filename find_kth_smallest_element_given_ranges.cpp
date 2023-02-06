//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    vector<int>kthSmallestNum(vector<vector<int>>&range, vector<int>queries){
        //Write your code here
        sort(range.begin(), range.end());
        vector<vector<int>> r;
        for(int i = 0; i < range.size(); ++i) {
            if (r.empty()) {
                r.push_back(range[i]);
                continue;
            }
            auto current = range[i];
            while(!r.empty()) {
                auto c = r[r.size()-1];
                if (c[0] >= current[0] && c[0] <= current[1]
                    || c[1] >= current[0] && c[1] <= current[1]
                    || current[0] >= c[0] && current[0] <= c[1]
                    || current[1] >= c[1] && current[1] <= c[1]) {
                        current[0] = min(c[0], current[0]);
                        current[1] = max(c[1], current[1]);
                        r.pop_back();
                } else {
                    break;
                }
            }
            
            r.push_back(current);
        }
        vector<int> ans;
        for(int q : queries) {
            for(int j = 0; j < r.size(); ++j) {
                if (q <= r[j][1]-r[j][0]+1) {
                    ans.push_back(r[j][0] + q - 1);
                    q = -1;
                    break;
                } else {
                    q -= r[j][1]-r[j][0]+1;
                }
            }
            if (q != 0 && q!=-1) {
                ans.push_back(-1);
            }
        }
        return ans;
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
	    cin >> n;
	    vector<vector<int>>range(n, vector<int>(2, 0));
	    for(int i = 0 ; i < n; i++){
	        cin >> range[i][0] >> range[i][1];
	    }
	    int q;
	    cin >> q;
	    vector<int>queries;
	    for(int i = 0 ; i < q; i++){
	        int x;
            cin >> x;
	        queries.push_back(x);
	    }
	    Solution ob;
	    vector<int>ans = ob.kthSmallestNum(range, queries);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout << endl;
	}
	return 0;
}

// } Driver Code Ends
