//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends

class Solution {
  vector<tuple<int, int, int>> v;
  int dp[601];

 public:
  /*The function takes an array of heights, width and
  length as its 3 arguments where each index i value
  determines the height, width, length of the ith box.
  Here n is the total no of boxes.*/
  int maxHeight(int h[], int w[], int l[], int n) {
    // Your code here
    for (int i = 0; i < n; ++i) {
      v.emplace_back(h[i], w[i], l[i]);
      v.emplace_back(h[i], l[i], w[i]);
      v.emplace_back(w[i], h[i], l[i]);
      v.emplace_back(w[i], l[i], h[i]);
      v.emplace_back(l[i], w[i], h[i]);
      v.emplace_back(l[i], h[i], w[i]);
    }
    sort(v.begin(), v.end(), greater<tuple<int, int, int>>());
    auto it = unique(v.begin(), v.end());
    v.erase(it, v.end());
    memset(dp, -1, sizeof(dp));
    int ans = 0;
    dp[0] = get<2>(v[0]);
    for (int i = 1; i < v.size(); ++i) {
      dp[i] = get<2>(v[i]);
      for (int j = i - 1; j >= 0; --j) {
        if (get<0>(v[j]) > get<0>(v[i]) && get<1>(v[j]) > get<1>(v[i])) {
          dp[i] = max(dp[i], dp[j] + get<2>(v[i]));
        }
      }
    }
    for (int i = 0; i < v.size(); ++i) {
      ans = max(ans, dp[i]);
    }
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

    int A[105], B[105], C[105];
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int j = 0; j < n; j++) cin >> B[j];
    for (int k = 0; k < n; k++) cin >> C[k];
    Solution ob;
    cout << ob.maxHeight(A, B, C, n) << endl;
  }

  return 0;
}

// } Driver Code Ends
