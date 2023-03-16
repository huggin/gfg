//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
 public:
  long long maxScore(vector<int> &cardPoints, int N, int k) {
    // code here
    vector<long long> prefix(k + 1), suffix(k + 1);
    for (int i = 0; i < k; ++i) {
      prefix[i + 1] = cardPoints[i] + prefix[i];
      suffix[i + 1] = cardPoints[N - 1 - i] + suffix[i];
    }
    long long ans = 0;
    for (int i = 0; i <= k; ++i) {
      ans = max(ans, prefix[i] + suffix[k - i]);
    }
    return ans;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int N, k;
    cin >> N >> k;

    vector<int> cardPoints(N);
    for (int i = 0; i < N; i++) cin >> cardPoints[i];

    Solution obj;
    cout << obj.maxScore(cardPoints, N, k) << endl;
  }
  return 0;
}
// } Driver Code Ends
