//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  vector<int> st;

  int construct(int a[], int l, int r, int i) {
    if (l == r) {
      st[i] = a[l];
      return st[i];
    }
    int mid = l + (r - l) / 2;
    int lv = construct(a, l, mid, i * 2 + 1);
    int rv = construct(a, mid + 1, r, i * 2 + 2);
    st[i] = lv ^ rv;
    return st[i];
  }

  void construct(int a[], int N) {
    int sz = 2;
    for (; sz <= N; sz *= 2)
      ;
    sz = 2 * sz - 1;
    st.assign(sz, 0);
    construct(a, 0, N - 1, 0);
  }

  int read(int l, int r, int qs, int qe, int i) {
    if (qs > qe)
      swap(qs, qe);
    if (qs <= l && qe >= r)
      return st[i];
    if (qs > r || qe < l)
      return 0;
    int mid = l + (r - l) / 2;
    int lv = read(l, mid, qs, qe, i * 2 + 1);
    int rv = read(mid + 1, r, qs, qe, i * 2 + 2);
    return lv ^ rv;
  }

public:
  vector<int> specialXor(int N, int Q, int a[], vector<int> query[]) {
    // code here
    construct(a, N);

    vector<int> ans;
    for (int i = 0; i < Q; ++i) {
      ans.push_back(read(0, N - 1, query[i][0] - 1, query[i][1] - 1, 0));
    }
    for (int &e : ans) {
      e = e ^ st[0];
    }
    return ans;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int N, Q;
    cin >> N >> Q;
    int a[N];
    for (int i = 0; i < N; i++)
      cin >> a[i];
    int l, r;
    vector<int> query[Q];
    for (int i = 0; i < Q; i++) {
      cin >> l >> r;
      query[i].push_back(l);
      query[i].push_back(r);
    }

    Solution ob;
    vector<int> ans = ob.specialXor(N, Q, a, query);
    for (int u : ans)
      cout << u << "\n";
  }
  return 0;
}
// } Driver Code Ends
