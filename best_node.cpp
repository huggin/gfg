//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
 public:
  template <class T>
  static void input(vector<T> &A, int n) {
    for (int i = 0; i < n; i++) {
      scanf("%d ", &A[i]);
    }
  }

  template <class T>
  static void print(vector<T> &A) {
    for (int i = 0; i < A.size(); i++) {
      cout << A[i] << " ";
    }
    cout << endl;
  }
};

// } Driver Code Ends
class Solution {
  long long ans;

  pair<long long, long long> dfs(int k, vector<int> c[], const vector<int> &A) {
    if (c[k].size() == 0) {
      ans = max(ans, (long long)A[k]);
      return make_pair(A[k], A[k]);
    }
    long long mi = LLONG_MAX, ma = LLONG_MIN;
    for (auto w : c[k]) {
      auto temp = dfs(w, c, A);
      mi = min(mi, temp.second);
      ma = max(ma, temp.first);
      ans = max(A[k] - mi, ans);
    }
    return make_pair(A[k] - mi, A[k] - ma);
  }

 public:
  long long bestNode(int N, vector<int> &A, vector<int> &P) {
    // code here
    vector<int> children[N];
    for (int i = 1; i < N; ++i) {
      children[P[i] - 1].push_back(i);
    }

    ans = LLONG_MIN;
    dfs(0, children, A);
    return ans;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  scanf("%d ", &t);
  while (t--) {
    int N;
    scanf("%d", &N);

    vector<int> A(N);
    Array::input(A, N);

    vector<int> P(N);
    Array::input(P, N);

    Solution obj;
    long long res = obj.bestNode(N, A, P);

    cout << res << endl;
  }
}

// } Driver Code Ends
