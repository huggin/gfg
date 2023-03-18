//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
 public:
  // arr[]: Input Array
  // N : Size of the Array arr[]
  // Function to count inversions in the array.
  long long merge(long long arr[], int lo, int mi, int hi) {
    int i = lo, j = mi + 1, k = 0;
    vector<long long> b(hi - lo + 1);
    long long ans = 0;
    while (i <= mi && j <= hi) {
      if (arr[i] <= arr[j]) {
        b[k++] = arr[i++];
      } else {
        b[k++] = arr[j++];
        ans += (mi - i + 1);
      }
    }
    while (i <= mi) {
      b[k++] = arr[i++];
    }
    while (j <= hi) {
      b[k++] = arr[j++];
    }
    for (i = lo, k = 0; i <= hi; ++i, ++k) {
      arr[i] = b[k];
    }
    return ans;
  }
  long long mergeSort(long long arr[], int lo, int hi) {
    if (lo >= hi) {
      return 0;
    }
    int mi = lo + (hi - lo) / 2;
    long long l = mergeSort(arr, lo, mi);
    long long r = mergeSort(arr, mi + 1, hi);
    return l + r + merge(arr, lo, mi, hi);
  }
  long long int inversionCount(long long arr[], long long N) {
    // Your Code Here
    long long ans = mergeSort(arr, 0, N - 1);

    return ans;
  }
};

//{ Driver Code Starts.

int main() {
  long long T;
  cin >> T;

  while (T--) {
    long long N;
    cin >> N;

    long long A[N];
    for (long long i = 0; i < N; i++) {
      cin >> A[i];
    }
    Solution obj;
    cout << obj.inversionCount(A, N) << endl;
  }

  return 0;
}

// } Driver Code Ends
