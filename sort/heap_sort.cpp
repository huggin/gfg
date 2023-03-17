//{ Driver Code Starts
// C++ program for implementation of Heap Sort
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// The functions should be written in a way that array become sorted
// in increasing order when heapSort() is called.

class Solution {
 public:
  // Heapify function to maintain heap property.
  void heapify(int arr[], int n, int i) {
    // Your Code Here
    while (2 * i + 1 < n) {
      int j = 2 * i + 1;
      if (j + 1 < n && arr[j] < arr[j + 1]) ++j;
      if (arr[i] < arr[j]) {
        swap(arr[i], arr[j]);
        i = j;
      } else {
        break;
      }
    }
  }

 public:
  // Function to build a Heap from array.
  void buildHeap(int arr[], int n) {
    // Your Code Here
    for (int i = n / 2; i >= 0; --i) {
      heapify(arr, n, i);
    }
  }

 public:
  // Function to sort an array using Heap Sort.
  void heapSort(int arr[], int n) {
    // code here
    buildHeap(arr, n);
    while (n > 1) {
      swap(arr[0], arr[n - 1]);
      --n;
      heapify(arr, n, 0);
    }
  }
};

//{ Driver Code Starts.

/* Function to print an array */
void printArray(int arr[], int size) {
  int i;
  for (i = 0; i < size; i++) printf("%d ", arr[i]);
  printf("\n");
}

// Driver program to test above functions
int main() {
  int arr[1000000], n, T, i;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &arr[i]);
    Solution ob;
    ob.heapSort(arr, n);
    printArray(arr, n);
  }
  return 0;
}

// } Driver Code Ends
