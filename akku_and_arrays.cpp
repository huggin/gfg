//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
    vector<pair<int, int>> st;
    
    pair<int, int> build(const vector<int>& a, int tl, int tr, int i) {
        if (tl == tr) {
            st[i] = {1, 1};
            return st[i];
        }
        int mid = tl + (tr - tl) / 2;
        auto lv = build(a, tl, mid, i*2+1);
        auto rv = build(a, mid+1, tr, i*2+2);
        st[i] = {0, 0};
        if (a[mid] <= a[mid+1]) {
            st[i].first = lv.first && rv.first;
        }
        if (a[mid] >= a[mid+1]) {
            st[i].second = lv.second && rv.second;
        }
        return st[i];
    }
    
    void update(vector<int>& a, 
        int tl, int tr, int v, int pos, int val) {
        
        if (tl == tr) {
            a[pos] = val;
        } else {
            int mid = tl + (tr - tl) / 2;
            if (pos <= mid)
                update(a, tl, mid, v*2+1, pos, val);
            else
                update(a, mid+1, tr, v*2+2, pos, val);
            
            st[v] = {0, 0};
            if (a[mid] <= a[mid+1])
                st[v].first = st[v*2+1].first && st[v*2+2].first;
            if (a[mid] >= a[mid+1])
                st[v].second = st[v*2+1].second && st[v*2+2].second;
        }
    }
    
    pair<int, int> query(const vector<int>& a, 
        int tl, int tr, int l, int r, int v) {
        
        if (l > r) return {0, 0};
        if (l == tl && r == tr) {
            return st[v];
        }
        int mid = tl + (tr - tl) / 2;
        auto lv = query(a, tl, mid, l, min(r, mid), v*2+1);
        auto rv = query(a, mid+1, tr, max(l, mid+1), r, v*2+2);
        pair<int, int> ans{0, 0};
        if (r <= mid) {
            ans = lv;
        } else if (l >= mid + 1) {
            ans = rv;
        } else {
            if (a[mid] <= a[mid+1]) {
                ans.first = lv.first && rv.first;
            }
            if (a[mid] >= a[mid+1]) {
                ans.second = lv.second && rv.second;
            }
        }
        return ans;
    }
    
public:
    vector<int>solveQueries(vector<int>nums, vector<vector<int>>Queries){
        // Code here
        int n = nums.size();
        st.assign(4*n, {0, 0});
        build(nums, 0, n-1, 0);
        
        vector<int> ans;
        for(auto& q : Queries) {
            if (q[0] == 1) {
                update(nums, 0, n-1, 0, q[1]-1, q[2]);
            } else {
                pair<int, int> t = query(nums, 0, n-1, q[1]-1, q[2]-1, 0);
                if (t.first == t.second) ans.push_back(-1);
                else if (t.first == 1) ans.push_back(0);
                else if (t.second == 1) ans.push_back(1);
            }
        }
        return ans;
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
		for(int i = 0; i < n; i++)cin >> nums[i];
		int q;
		cin >> q;
		vector<vector<int>>Queries;
		for(int i = 0; i < q; i++){
			int x, y, z;
			cin >> x >> y >> z;
			Queries.push_back({x,y,z});
		}
		Solution obj;
		vector<int>ans = obj.solveQueries(nums, Queries);
		for(auto i: ans)cout << i << "\n";
	}
	return 0;
}
// } Driver Code Ends
