//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define N 1000

// } Driver Code Ends
// you are required to complete this function
// function should print the required range
class Solution {
 public:
  pair<int, int> findSmallestRange(int KSortedArray[][N], int n, int k) {
    // code here
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>> Q;
    int ma = INT_MIN, mi = INT_MAX;
    for (int i = 0; i < k; ++i) {
      Q.emplace(KSortedArray[i][0], i);
      ma = max(ma, KSortedArray[i][0]);
    }
    vector<int> index(k);
    int sz = -1;
    int ans_ma = -1, ans_mi = -1;
    while (!Q.empty()) {
      auto c = Q.top();
      Q.pop();
      int mi = c.first;
      int line = c.second;
      if (sz == -1 || ma - mi < sz) {
        sz = ma - mi;
        ans_ma = ma;
        ans_mi = mi;
      }

      if (index[line] == n - 1) break;
      Q.emplace(KSortedArray[line][index[line] + 1], line);
      if (KSortedArray[line][index[line] + 1] > ma) {
        ma = KSortedArray[line][index[line] + 1];
      }
      index[line]++;
    }
    return make_pair(ans_mi, ans_ma);
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    int arr[N][N];
    pair<int, int> rangee;
    for (int i = 0; i < k; i++)
      for (int j = 0; j < n; j++) cin >> arr[i][j];
    Solution obj;
    rangee = obj.findSmallestRange(arr, n, k);
    cout << rangee.first << " " << rangee.second << "\n";
  }
  return 0;
}

// } Driver Code Ends
