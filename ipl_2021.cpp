//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        // your code here
        queue<int> Q1;
        deque<int> Q2;
        for(int i = 0; i < k; ++i) {
            Q1.push(arr[i]);
            while (!Q2.empty() && arr[i] > Q2.back()) {
                Q2.pop_back();
            }
            Q2.push_back(arr[i]);
        }
        vector<int> ans;
        ans.push_back(Q2.front());
        for(int i = k; i < n; ++i) {
            if (Q1.front() == Q2.front()) {
                Q2.pop_front();
            }
            Q1.pop();
            Q1.push(arr[i]);
            while (!Q2.empty() && arr[i] > Q2.back()) {
                Q2.pop_back();
            }
            Q2.push_back(arr[i]);
            ans.push_back(Q2.front());
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends
