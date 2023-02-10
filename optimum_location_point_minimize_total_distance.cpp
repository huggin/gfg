//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
//User function Template for C++
class Solution{
    double distance(tuple<int, int, int>& l, vector<pair<int, int>>& p, int n, double x) {
        double a = get<0>(l);
        double b = get<1>(l);
        double c = get<2>(l);
        double y = (-c - a*x) / b;
        double total = 0;
        for(auto e : p) {
            total += sqrt((e.first - x) * (e.first -x) + (e.second - y) * (e.second - y));
        }
        return total;
    }
public:
    double findOptimumCost(tuple<int,int,int>l, vector<pair<int,int>>p, int n){
	    //Write your code here
	    double lo = -3000, hi = 3000;
	    double eps = 1e-6;
	    
	    while(hi - lo > eps) {
	        double x1 = lo + (hi - lo) / 3;
	        double x2 = hi - (hi - lo) / 3;
	        double d1 = distance(l, p, n, x1);
	        double d2 = distance(l, p, n, x2);
	        if (d1 < d2) {
	            hi = x2;
	        } else if (d1 > d2) {
	            lo = x1;
	        } else {
	            lo = x1;
	            hi = x2;
	        }
	    }
	    return distance(l, p, n, lo);
    }
};



//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    tuple<int,int,int>line;
	    int a, b, c;
	    cin >> a >> b >> c;
	    line = make_tuple(a, b, c);
	    int n;
	    cin >> n;
	    vector<pair<int,int>>points;
	    for(int i = 0 ; i < n; i++){
	        int x, y;
	        cin >> x >> y;
	        points.push_back({x, y});
	    }

	    Solution ob;
	    double ans = ob.findOptimumCost(line, points, n);

	    cout << fixed << setprecision(2) << ans << endl;
	}
	return 0;
}

// } Driver Code Ends
