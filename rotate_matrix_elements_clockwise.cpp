//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void doit(int i, int j, int i2, int j2, vector<vector<int>>& Mat) {
        if (i + 1 > i2 || j + 1 > j2) return;
        int temp = Mat[i][j];
        for(int k = i+1; k <= i2; ++k) {
            Mat[k-1][j] = Mat[k][j];
        }
        for(int k = j; k + 1 <= j2; ++k) {
            Mat[i2][k] = Mat[i2][k+1];
        }
        for(int k = i2; k - 1 >= i; --k) {
            Mat[k][j2] = Mat[k-1][j2];
        }
        for(int k = j2; k - 1 >= j; --k) {
            Mat[i][k] = Mat[i][k-1];
        }
        Mat[i][j+1] = temp;
    }
  public:
    vector<vector<int>> rotateMatrix(int M, int N, vector<vector<int>> Mat) {
        // code here
        for(int i = 0, j = 0; i < M/2 && j < N/2; ++i, ++j) {
            doit(i, j, M - 1 - i, N - 1 - j, Mat);
        }
        return Mat;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, i, j;
        cin >> N >> M;
        vector<vector<int>> Mat(N, vector<int>(M));
        for (i = 0; i < N; i++)
            for (j = 0; j < M; j++) cin >> Mat[i][j];
        Solution ob;
        vector<vector<int>> ans = ob.rotateMatrix(N, M, Mat);
        for (i = 0; i < N; i++) {
            for (j = 0; j < M; j++) cout << ans[i][j] << " ";
            cout << "\n";
        }
    }
}
// } Driver Code Ends
