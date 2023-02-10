//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

int g[11][11];
const int N=11;

void subMatrix(int mat[N][N], int temp[N][N], int p, int q, int n) {
   int i = 0, j = 0;
   // filling the sub matrix
   for (int row = 0; row < n; row++) {
      for (int col = 0; col < n; col++) {
         // skipping if the current row or column is not equal to the current
         // element row and column
         if (row != p && col != q) {
            temp[i][j++] = mat[row][col];
            if (j == n - 1) {
               j = 0;
               i++;
            }
         }
      }
   }
}

int determinantOfMatrix(int matrix[N][N], int n) {
   int determinant = 0;
   if (n == 1) {
      return matrix[0][0];
   }
   if (n == 2) {
      return (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
   }
   int temp[N][N], sign = 1;
   for (int i = 0; i < n; i++) {
      subMatrix(matrix, temp, 0, i, n);
      determinant += sign * matrix[0][i] * determinantOfMatrix(temp, n - 1);
      sign = -sign;
   }
   return determinant;
}

class Solution{
    public:
    int countSpanningTrees(vector<vector<int>>&graph, int n, int k){
        //Write your code here
        memset(g, 0, sizeof(g));
        for(int i = 0; i < graph.size(); ++i) {
            g[graph[i][0]][graph[i][1]] = -1;
            g[graph[i][1]][graph[i][0]] = -1;
        }
        
        for(int i = 0; i < n; ++i) {
            g[i][i] = count(g[i], g[i]+n, -1);
        }

        return determinantOfMatrix(g, n-1);
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, m;
	    cin >> n >> m;
	    vector<vector<int>>graph(m, vector<int>(2, 0));
	    for(int i = 0 ; i < m; i++){
	        cin >> graph[i][0] >> graph[i][1];
	    }
	    Solution ob;
	    int ans = ob.countSpanningTrees(graph, n, m);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends
