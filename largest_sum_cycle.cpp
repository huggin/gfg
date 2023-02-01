//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    vector<int> marked;
    int n;
    int ans;
    vector<int> onStack;

    void dfs(const vector<int>& e, int k) {
        onStack[k] = 1;
        marked[k] = 1;
        int w = e[k];
        if (w == -1) {
            onStack[k] = 0;
            return;
        }

        if (!marked[w]) {
            dfs(e, w);
        } else if (onStack[w]) {
            int temp = 0;
            for(int i = w; i != k; i = e[i]) temp += i;
            temp += k;
            ans = max(ans, temp);
        }
        onStack[k] = 0;
    }
public:
  long long largestSumCycle(int N, vector<int> Edge)
  {
    // code here
    n = N;
    marked.assign(N, 0);
    onStack.assign(N, 0);
    ans = -1;
    for(int i = 0; i < N; ++i) {
        if (!marked[i]) {
            dfs(Edge, i);
        }
    }
    return ans;
  }
};

//{ Driver Code Starts.
signed main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      long long ans=obj.largestSumCycle(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends
