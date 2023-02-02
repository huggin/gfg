//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{
    int sum(int bit[], int idx) {
        int ans = 0;
        for(++idx; idx > 0; idx -= idx & -idx) {
            ans += bit[idx];
        }
        return ans;
    }
    
    void update(int bit[], int idx, int n, int value) {
        for (++idx; idx <= n; idx += idx & -idx) {
            bit[idx] += value;
        }
    }
public:
    vector<int> greaterLesser(vector<int>A, int N){
        // code here 
        int bit[N+1] = {0};
        map<int, int> m;
        for(int i = 0; i < N; ++i) {
            m[A[i]] = i;
        }
        int rank = 1;
        for(auto& it : m) {
            A[it.second] = rank++;
        }
        
        vector<int> left(N), right(N);
        for(int i = N-1; i>=0; --i) {
            right[i] = sum(bit, A[i]-1);
            update(bit, A[i], N, 1);
        }
        
        for(int& a : A) {
            a = N + 1 - a;
        }
        
        memset(bit, 0, sizeof(bit));
        for(int i = 0; i < N; ++i) {
            left[i] = sum(bit, A[i]-1);
            update(bit, A[i], N, 1);
        }
        vector<int> ans(N);
        for(int i = 0; i < N; ++i) {
            ans[i] = abs(left[i]-right[i]);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        vector<int>A(N);
        for(int i = 0; i < N; i++)
            cin >> A[i];
        
        Solution ob;
        vector<int>ans(N);
        ans=ob.greaterLesser(A, N);
        for(int i = 0; i < N; i++)
            cout << ans[i] << " ";
        cout << endl;
    }
    return 0; 
} 

// } Driver Code Ends
