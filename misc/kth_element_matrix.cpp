//{ Driver Code Starts
// kth largest element in a 2d array sorted row-wise and column-wise
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);
// driver program to test above function
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        cin >> mat[i][j];
    int r;
    cin >> r;
    cout << kthSmallest(mat, n, r) << endl;
  }
  // cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
  return 0;
}

// } Driver Code Ends

int kthSmallest(int mat[MAX][MAX], int n, int k) {
  // Your code here
  priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                 greater<tuple<int, int, int>>>
      Q;

  vector<vector<int>> v(n, vector<int>(n));
  Q.emplace(mat[0][0], 0, 0);
  v[0][0] = 1;
  int count = 0;
  while (!Q.empty()) {
    auto c = Q.top();
    if (++count == k)
      return get<0>(c);
    Q.pop();
    int x = get<1>(c);
    int y = get<2>(c);
    if (x + 1 < n && v[x + 1][y] == 0) {
      Q.emplace(mat[x + 1][y], x + 1, y);
      v[x + 1][y] = 1;
    }
    if (y + 1 < n && v[x][y + 1] == 0) {
      Q.emplace(mat[x][y + 1], x, y + 1);
      v[x][y + 1] = 1;
    }
  }
  return -1;
}
