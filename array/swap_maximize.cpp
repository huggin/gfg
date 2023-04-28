//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
long long int maxSum(int arr[], int n);

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
      cin >> arr[i];
    cout << maxSum(arr, n) << endl;
  }
  return 0;
}
// } Driver Code Ends

long long int maxSum(int arr[], int n) {
  sort(arr, arr + n);
  long long ans = 0;
  bool flag = true;
  int i = 0, j = n - 1;
  for (; i < j; flag = !flag) {
    ans += abs(arr[i] - arr[j]);
    if (flag) {
      ++i;
    } else {
      --j;
    }
  }
  if (flag)
    ans += abs(arr[0] - arr[i]);
  else
    ans += abs(arr[0] - arr[j]);
  return ans;
}
