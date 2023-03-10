//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
 public:
  vector<int> solveQueries(int N, int num, vector<int> &A,
                           vector<vector<int>> &Q) {
    // code here
    vector<int> v[N];
    v[N - 1].push_back(A[N - 1]);
    for (int i = N - 2; i >= 0; --i) {
      merge(v[i + 1].begin(), v[i + 1].end(), A.begin() + i, A.begin() + i + 1,
            back_inserter(v[i]));
    }

    vector<int> ans;
    for (auto &q : Q) {
      int t = 0;
      for (int i = q[0]; i <= q[1]; ++i) {
        auto it = equal_range(v[i].begin(), v[i].end(), A[i]);
        if (it.second - it.first == q[2]) ++t;
      }
      ans.push_back(t);
    }
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
    int num;
    cin >> num;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
      cin >> A[i];
    }
    vector<vector<int>> Q(num, vector<int>(3));
    for (int i = 0; i < num; i++) {
      for (int j = 0; j < 3; j++) {
        cin >> Q[i][j];
      }
    }
    Solution obj;
    vector<int> res = obj.solveQueries(N, num, A, Q);

    for (auto ele : res) {
      cout << ele << " ";
    }
    cout << endl;
  }
}

// } Driver Code Ends
