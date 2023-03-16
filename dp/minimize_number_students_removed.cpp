//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
 public:
  int removeStudents(int H[], int N) {
    // code here
    vector<int> ans;
    for (int i = 0; i < N; ++i) {
      if (ans.empty() || ans.back() < H[i]) {
        ans.push_back(H[i]);
      } else {
        auto it = lower_bound(ans.begin(), ans.end(), H[i]);
        if (it != ans.end()) *it = H[i];
      }
    }
    return N - ans.size();
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int N;
    cin >> N;

    int H[N];
    for (int i = 0; i < N; i++) cin >> H[i];

    Solution ob;
    cout << ob.removeStudents(H, N) << endl;
  }
  return 0;
}
// } Driver Code Ends
