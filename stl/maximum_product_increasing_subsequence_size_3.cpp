//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Function to find the max product subsequence of size 3
// arr: given input array
// n: size of array
// res: array which contains the output
void maxProductSubsequence(int *arr, int n, int *res) {
  // Your code here
  set<int> left;
  vector<int> right(n);
  left.insert(arr[0]);
  right[n - 1] = arr[n - 1];
  for (int i = n - 2; i >= 0; --i) {
    right[i] = max(arr[i], right[i + 1]);
  }
  long long ans = -1;
  for (int i = 1; i < n - 1; ++i) {
    auto it = left.lower_bound(arr[i]);
    if (it != left.begin())
      --it;
    if (*it < arr[i] && right[i + 1] > arr[i]) {
      long long d = 1LL * (*it) * arr[i] * right[i + 1];
      if (ans <= d) {
        ans = d;
        res[0] = *it;
        res[1] = arr[i];
        res[2] = right[i + 1];
      }
    }

    left.insert(arr[i]);
  }
}

//{ Driver Code Starts.

// Driver Program
int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);

  int T;
  cin >> T;
  while (T--) {
    int num;
    cin >> num;
    int arr[num];
    for (int i = 0; i < num; ++i)
      cin >> arr[i];

    int res[3] = {0};
    maxProductSubsequence(arr, num, res);

    if (res[0] == 0)
      cout << "-1" << endl;
    else {
      for (int i = 0; i < 3; ++i)
        cout << res[i] << " ";
      cout << endl;
    }
  }
}

// } Driver Code Ends
