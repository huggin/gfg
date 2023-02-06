//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int search(int A[], int l, int h, int key){
        // l: The starting index
        // h: The ending index, you have to search the key in this range
        
        if (l > h) {
            return -1;
        }
        int mi = l + (h - l) / 2;
        if (A[mi] == key) {
            return mi;
        }
        if (A[mi] < key && A[l] < A[mi]) {
            return search(A, mi + 1, h, key);
        } else if (A[mi] > key && A[mi] < A[h]) {
            return search(A, l, mi - 1, key);
        } 
        int t = search(A, l, mi - 1, key);
        if (t != -1) {
            return t;
        }
        return search(A, mi + 1, h, key);
    }
};

//{ Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}
// } Driver Code Ends
