//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<int> countMultiples(int arr[], int q[], int n, int m);

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, i, m;
    cin >> n >> m;
    int q[m], arr[n];
    for (i = 0; i < n; i++) {
      cin >> arr[i];
    }
    for (i = 0; i < m; i++)
      cin >> q[i];

    vector<int> answering = countMultiples(arr, q, n, m);
    for (auto it : answering)
      cout << it << " ";
    cout << "\n";
  }
  return 0;
}

// } Driver Code Ends

vector<int> countMultiples(int A[], int Q[], int N, int M) {
  // Your code goes here
  int ma = *max_element(A, A + N);
  vector<int> nums(ma + 1);
  for (int i = 0; i < N; ++i) {
    nums[A[i]]++;
  }
  vector<int> ans(M);
  unordered_map<int, int> m;

  for (int i = 2; i <= ma; ++i) {
    m[i] = nums[i];
    for (int j = i + i; j <= ma; j += i) {
      m[i] += nums[j];
    }
  }

  for (int i = 0; i < M; ++i) {
    if (Q[i] == 1)
      ans[i] = N;
    else
      ans[i] = m[Q[i]];
  }
  return ans;
}
