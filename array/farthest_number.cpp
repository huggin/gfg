//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
public:
  vector<int> farNumber(int N, vector<int> Arr) {
    // code here
    vector<int> ans(N, -1);
    vector<int> suf(Arr);
    for (int i = N - 2; i >= 0; --i)
      suf[i] = min(suf[i + 1], Arr[i]);

    for (int i = 0; i < N; ++i) {
      int idx = lower_bound(suf.begin(), suf.end(), Arr[i]) - suf.begin() - 1;
      ans[i] = idx <= i ? -1 : idx;
    }
    return ans;
  }
};

//{ Driver Code Starts.
signed main() {
  int t;
  cin >> t;
  while (t--) {
    int N;
    cin >> N;
    vector<int> Arr(N);
    for (int i = 0; i < N; i++)
      cin >> Arr[i];
    Solution obj;
    vector<int> answer = obj.farNumber(N, Arr);
    for (auto i : answer)
      cout << i << " ";
    cout << endl;
  }
}
// } Driver Code Ends
