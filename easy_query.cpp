//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

struct Vertex {
    Vertex *l, *r;
    int sum;

    Vertex(int val) : l(nullptr), r(nullptr), sum(val) {}
    Vertex(Vertex *l, Vertex *r) : l(l), r(r), sum(0) {
        if (l) sum += l->sum;
        if (r) sum += r->sum;
    }
};

class Solution {
    const int MAX_VALUE = 15000;
    
    Vertex* build(int tl, int tr) {
        if (tl == tr)
            return new Vertex(0);
        int tm = (tl + tr)>>1;
        return new Vertex(build(tl, tm), build(tm+1, tr));
    }
    
    Vertex* update(Vertex* v, int tl, int tr, int pos) {
        if (tl == tr)
            return new Vertex(v->sum+1);
        int tm = (tl + tr)>>1;
        if (pos <= tm)
            return new Vertex(update(v->l, tl, tm, pos), v->r);
        else
            return new Vertex(v->l, update(v->r, tm+1, tr, pos));
    }
    
    int find_kth(Vertex* vl, Vertex *vr, int tl, int tr, int k) {
        if (tl == tr)
            return tl;
        int tm = (tl + tr)>>1, left_count = vr->l->sum - vl->l->sum;
        if (left_count >= k)
            return find_kth(vl->l, vr->l, tl, tm, k);
        return find_kth(vl->r, vr->r, tm+1, tr, k-left_count);
    }
public:
	vector<int>FindQuery(vector<int>nums, vector<vector<int>>Query){
	    // Code here
	    int tl = 0, tr = MAX_VALUE + 1;
        std::vector<Vertex*> roots;
        roots.push_back(build(tl, tr));
        for (int i = 0; i < nums.size(); i++) {
            roots.push_back(update(roots.back(), tl, tr, nums[i]));
        }

        vector<int> ans;
        for(auto& q: Query) {
            ans.push_back(find_kth(roots[q[0]-1], roots[q[1]], tl, tr, q[2]));
        }
        return ans;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, q;
		cin >> n >> q;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		vector<vector<int>>Query;
		for(int i = 0; i < q; i++){
			int l, r, k;
			cin >> l >> r >> k;
			Query.push_back({l, r, k});
		}
		Solution obj;
		vector<int>ans = obj.FindQuery(nums, Query);
		for(auto i: ans)
			cout << i << "\n";
	}
	return 0;
}
// } Driver Code Ends
