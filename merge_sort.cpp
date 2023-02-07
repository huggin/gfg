//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    void merge(int arr[], int l, int m, int r)
    {
         // Your code here
        int aux[r-l+1];
        int k = 0;
        int i = l;
        int j = m+1;
        while(k < r-l+1) {
            if (i == m+1) {
                aux[k++] = arr[j++];
            } else if (j == r+1) {
                aux[k++] = arr[i++];
            } else if (arr[i] <= arr[j]) {
                aux[k++] = arr[i++];
            } else {
                aux[k++] = arr[j++];
            }
        }
        memcpy(arr+l, aux, sizeof(int)*(r-l+1));
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        if (l >= r) return;
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends
