//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
  vector<int> maxMeetings(int N, vector<int> &S, vector<int> &F) {
    vector<tuple<int, int, int>> v(N);
    for (int i = 0; i < N; ++i) {
      v[i] = make_tuple(F[i], i + 1, S[i]);
    }
    sort(v.begin(), v.end());
    vector<int> ans{get<1>(v[0])};
    int current = get<0>(v[0]);
    for (int i = 1; i < N; ++i) {
      if (get<2>(v[i]) > current) {
        ans.push_back(get<1>(v[i]));
        current = get<0>(v[i]);
      }
    }
    sort(ans.begin(), ans.end());
    return ans;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> S(n), F(n);
    for (int i = 0; i < n; i++) {
      cin >> S[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> F[i];
    }
    Solution ob;
    vector<int> ans = ob.maxMeetings(n, S, F);
    for (int i = 0; i < ans.size(); i++) {
      cout << ans[i];
      if (i != ans.size() - 1) {
        cout << " ";
      }
    }
    cout << endl;
  }
  return 0;
}
// } Driver Code Ends
