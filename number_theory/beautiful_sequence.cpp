//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
  vector<int> FindSequenece(int N) {
    vector<int> ans{1};
    for (int i = 2; i * i <= N; ++i) {
      while (N % i == 0) {
        ans.push_back(i);
        N /= i;
      }
    }
    if (N != 1)
      ans.push_back(N);
    for (int i = 1; i < ans.size(); ++i) {
      ans[i] *= ans[i - 1];
    }
    return ans;
  }
};

//{ Driver Code Starts.

int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int N;
    cin >> N;
    Solution obj;
    vector<int> ans = obj.FindSequenece(N);
    bool x = 1;

    for (int i = 1; i < ans.size(); i++)
      if (ans[i] <= ans[i - 1] || ans[i - 1] == 0 || ans[i] % ans[i - 1] != 0) {
        x = 0;
        break;
      }

    if (ans.back() != N)
      x = 0;

    cout << ans.size() << " " << x << "\n";
  }
  return 0;
}
// } Driver Code Ends
