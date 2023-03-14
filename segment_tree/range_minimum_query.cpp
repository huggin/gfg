//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int *constructST(int arr[], int n);

int RMQ(int st[], int n, int a, int b);
int main() {
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    int A[N];
    for (int i = 0; i < N; i++) cin >> A[i];
    int Q;
    cin >> Q;

    int *segTree = constructST(A, N);

    for (int i = 0; i < Q; i++) {
      int start, e;

      cin >> start >> e;
      if (start > e) {
        swap(start, e);
      }
      cout << RMQ(segTree, N, start, e) << " ";
    }
    cout << endl;
  }
}

// } Driver Code Ends

int construct(int arr[], int l, int r, int *st, int i) {
  if (l == r) {
    st[i] = arr[l];
    return st[i];
  }
  int mid = l + (r - l) / 2;
  int lv = construct(arr, l, mid, st, i * 2 + 1);
  int rv = construct(arr, mid + 1, r, st, i * 2 + 2);
  st[i] = min(lv, rv);
  return st[i];
}

/* The functions which
builds the segment tree */
int *constructST(int arr[], int n) {
  // Your code here
  int sz = 2;
  for (sz = 2; sz <= n; sz *= 2)
    ;
  sz = sz * 2 - 1;
  int *segtree = new int[sz];
  construct(arr, 0, n - 1, segtree, 0);
  return segtree;
}

int RMQ(int *st, int l, int r, int a, int b, int i) {
  if (a <= l && b >= r) return st[i];
  if (a > r || b < l) return INT_MAX;
  int mid = l + (r - l) / 2;
  int lv = RMQ(st, l, mid, a, b, i * 2 + 1);
  int rv = RMQ(st, mid + 1, r, a, b, i * 2 + 2);
  return min(lv, rv);
}

/* The functions returns the
 min element in the range
 from a and b */
int RMQ(int st[], int n, int a, int b) {
  // Your code here
  return RMQ(st, 0, n - 1, a, b, 0);
}
