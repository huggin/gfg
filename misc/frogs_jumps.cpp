//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int unvisitedLeaves(int N, int leaves, int frogs[]) {
        // Code here
        vector<int> marked(leaves+1);
        sort(frogs, frogs+N);
        for(int i = 0; i < N; ++i) {
            if (frogs[i] > leaves || marked[frogs[i]]) continue;
            for(int j = frogs[i]; j <= leaves; j += frogs[i]) {
                marked[j] = 1;
            }
        }
        return count(marked.begin() + 1, marked.end(), 0);
    }
};


//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, leaves;
        cin >> N >> leaves;
        int frogs[N];
        for (int i = 0; i < N; i++) {
            cin >> frogs[i];
        }

        Solution ob;
        cout << ob.unvisitedLeaves(N, leaves, frogs) << endl;
    }
}
// } Driver Code Ends
