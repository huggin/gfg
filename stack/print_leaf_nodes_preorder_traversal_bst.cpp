//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
 public:
  vector<int> leafNodes(int arr[], int N) {
    // code here
    vector<int> ans;
    stack<int> s;
    for (int i = 0; i < N; ++i) {
      if (s.empty() || arr[i] < s.top()) {
        s.push(arr[i]);
      } else {
        int t = s.top();
        int j = 0;
        while (!s.empty() && s.top() < arr[i]) {
          s.pop();
          ++j;
        }
        s.push(arr[i]);
        if (j > 1) ans.push_back(t);
      }
    }
    ans.push_back(s.top());
    return ans;
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int N;
    cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++) cin >> arr[i];
    Solution ob;
    vector<int> ans = ob.leafNodes(arr, N);
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    cout << endl;
  }
  return 0;
}
// } Driver Code Ends
