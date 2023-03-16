//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
 public:
  vector<int> coinsGame(int N, int K) {
    // Code Here
    vector<int> ans(K);
    int curr = 0;
    for (int i = 1; i < K; ++i) {
      ans[i] = curr;
      curr = 1 - curr;
      N -= ans[i];
    }
    ans[0] = N;
    return ans;
  }
};

//{ Driver Code Starts.

int main() {
  // code
  ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    int N, K;
    cin >> N >> K;
    Solution obj;
    vector<int> ans;
    ans = obj.coinsGame(N, K);
    for (int i : ans) cout << i << " ";
    cout << endl;
  }
  return 0;
}
// } Driver Code Ends
