//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    vector<vector<int>> ans;
    vector<int> v;
    int N;
    
    vector<vector<int>> b;

    void solve(int k) {
        //cout << k << endl;
        if (k == N+1) {
            ans.push_back(v);
            return;
        }
        for(int i = 1; i <= N; ++i) {
            if (!b[i][k]) {
                auto backup = b;
                b[i][k] = 1;
                for(int j = 1; j <= N; ++j) {
                    b[i][j] = 1;
                }
                for(int ii = i, kk = k; ii >= 1 && kk <= N; --ii, ++kk) {
                    b[ii][kk] = 1;
                }
                for(int ii = i, kk = k; ii <= N && kk <= N; ++ii, ++kk) {
                    b[ii][kk] = 1;
                }
                v.push_back(i);
                solve(k+1);
                v.pop_back();
                b = backup;
            }
        }
    }
public:
    vector<vector<int>> nQueen(int n) {
        // code here
        b.assign(n+1, vector<int>(n+1));
        N = n;
        solve(1);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends
