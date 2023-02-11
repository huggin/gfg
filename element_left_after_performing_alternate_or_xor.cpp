//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  vector<int> st;
  int build(int a[], int l, int r, int i, int op) {
    if (l == r) {
      st[i] = a[l];
      return st[i];
    }
    int m = (l + r) >> 1;
    int lv = build(a, l, m, i * 2 + 1, 1 - op);
    int rv = build(a, m + 1, r, i * 2 + 2, 1 - op);
    if (op) {
      st[i] = lv | rv;
    } else {
      st[i] = lv ^ rv;
    }
    return st[i];
  }

  void update(int pos, int v, int l, int r, int i, int op) {
    if (pos < l || pos > r) return;
    if (l == r) {
      st[i] = v;
      return;
    }
    int m = (l + r) >> 1;
    update(pos, v, l, m, i * 2 + 1, 1 - op);
    update(pos, v, m + 1, r, i * 2 + 2, 1 - op);
    if (op)
      st[i] = st[i * 2 + 1] | st[i * 2 + 2];
    else
      st[i] = st[i * 2 + 1] ^ st[i * 2 + 2];
  }

 public:
  vector<int> left(int N, int A[], int q, vector<pair<int, int>> query) {
    // code here
    st.assign(N * 2 - 1, 0);
    int op = ((int)log2(N)) % 2;
    build(A, 0, N - 1, 0, op);
    vector<int> ans;

    for (auto& q : query) {
      if (q.first >= N) {
        ans.push_back(-1);
        continue;
      }
      update(q.first, q.second, 0, N - 1, 0, op);
      ans.push_back(st[0]);
    }
    return ans;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int N, q;
    cin >> N;
    int A[N];
    for (int i = 0; i < N; i++) cin >> A[i];
    cin >> q;
    vector<pair<int, int>> query(q);
    int x, y;
    for (int i = 0; i < q; i++) {
      cin >> x >> y;
      query[i] = {x, y};
    }

    Solution ob;
    vector<int> ans = ob.left(N, A, q, query);
    for (int u : ans) cout << u << "\n";
  }
  return 0;
}
// } Driver Code Ends
