//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum inverting factor
int findMinimumInvertingFactor(int arr[], int N);

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
      cin >> arr[i];

    cout << findMinimumInvertingFactor(arr, n);

    cout << endl;
  }
}

// } Driver Code Ends

int findMinimumInvertingFactor(int arr[], int N) {
  // Complete the function
  transform(arr, arr + N, arr, [](int a) {
    int ans = 0;
    while (a) {
      ans = ans * 10 + a % 10;
      a /= 10;
    }
    return ans;
  });
  sort(arr, arr + N);
  int ans = INT_MAX;
  for (int i = 1; i < N; ++i) {
    ans = min(ans, arr[i] - arr[i - 1]);
  }
  return ans;
}
