//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

//Back-end complete function Template for C++
double round(double var)
{
    double value = (int)(var * 100 + .5);
    return (double)value / 100;
}

class Solution{
    public:
    vector<double>averageTimes(vector<int>arrivalTime, vector<int>burstTime, int n){
        //Write your code here
        using PQ = priority_queue<
                        tuple<int, int, int>,
                        vector<tuple<int, int, int>>,
                        greater<tuple<int, int, int>>>;
        PQ q;
        vector<pair<int, int>> V(n);
        vector<double> ans(2);

        for(int i = 0; i < n; ++i) {
            V[i].first = arrivalTime[i];
            V[i].second = burstTime[i];
        }
        sort(V.begin(), V.end());
        vector<int> s(n), f(n);
        int k = 0;
        int current = 0;
        while(!q.empty() || k < n) {
            if (q.empty()) {
                q.emplace(V[k].second, V[k].first, k);
                k++;
            }
            auto c = q.top();
            q.pop();
            //cout << get<0>(c) << ' ' << get<1>(c) << ' ' << get<2>(c) << endl;
            s[get<2>(c)] = max(current, get<1>(c));
            current = get<0>(c) + s[get<2>(c)];
            f[get<2>(c)] = current;
            int i = 0;
            for(i = k; i < n; ++i) {
                if (V[i].first <= current) {
                    q.emplace(V[i].second, V[i].first, i);
                } else {
                    break;
                }
            }
            k = i;
        }
        for(int i = 0; i < n; ++i) {
            ans[0] += s[i] - V[i].first;
            ans[1] += f[i] - V[i].first;
        }
        ans[0] = round(ans[0] / n);
        ans[1] = round(ans[1] / n);

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
	    vector<int>arrivalTime(n), burstTime(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> arrivalTime[i];
	    }
	    for(int i = 0 ; i < n; i++){
	        cin >> burstTime[i];
	    }
	    Solution ob;
	    vector<double> ans = ob.averageTimes(arrivalTime, burstTime, n);
	    for(auto it : ans){
	        cout << it <<" ";
	    }
	    cout << endl;
	}
	return 0;
}

// } Driver Code Ends
