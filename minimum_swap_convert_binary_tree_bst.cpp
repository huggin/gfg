//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    vector<int> a;
    int ans;
    void inOrder(const vector<int>& A, int i, int n) {
        if (i >=  n) return;
        inOrder(A, i*2+1, n);
        a.push_back(A[i]);
        inOrder(A, i*2+2, n);
    }
    
    void dfs(int v, unordered_map<int, int>& m, vector<int>& marked, int count) {
        marked[v] = 1;
        ++count;
        if (!marked[m[a[v]]]) {
            dfs(m[a[v]], m, marked, count);
        } else {
            ans += count - 1;
        }
    }
  public:
    int minSwaps(vector<int>&A, int n){
        //Write your code here
        inOrder(A, 0, n);
        
        unordered_map<int, int> m;
        for(int i = 0; i < n; ++i) {
            m[A[i]] = i;
        }
        vector<int> marked(n);
        ans = 0;
        for(int i = 0; i < n; ++i) {
            if (!marked[i]) {
                int count = 0;
                dfs(i, m, marked, count);
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
	    vector<int>A(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> A[i];
	    }
	    Solution ob;
	    int ans = ob.minSwaps(A, n);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends
