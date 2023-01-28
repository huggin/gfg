//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution{
    
    int calc1(vector<int>& a, int pi, int i, vector<int>& b, int pj, int j) {
        int ans = 0;
        if (pi>= 0) {
            ans = max(ans, a[i] - a[pi]);
        } else if (i>=0) {
            ans = max(ans, a[i]);
        }
        if (pj>= 0) {
            ans = max(ans, b[j] - b[pj]);
        } else if (j>=0) {
            ans = max(ans, b[j]);
        }
        return ans;
    }
    
    public:
    /*You are required to complete this method*/
     int max_path_sum(int A[], int B[], int l1, int l2)
    {
    
        //Your code here
        vector<int> a1(l1), a2(l1);
        vector<int> b1(l2), b2(l2);
        a1[0] = A[0];
        for(int i = 1; i < l1; ++i) {
            a1[i] = a1[i-1] + A[i];
        }
        a2[l1-1] = A[l1-1];
        for(int i=l1-2; i>=0; --i) {
            a2[i] = a2[i+1] + A[i];
        }
        b1[0] = B[0];
        for(int i = 1; i < l2; ++i) {
            b1[i] = b1[i-1] + B[i];
        }
        b2[l2-1] = B[l2-1];
        for(int i=l2-2; i>=0; --i) {
            b2[i] = b2[i+1] + B[i];
        }
        int ans = 0;
        int i = 0, j = 0;
        int pi = -1, pj = -1;
        while(i < l1 && j < l2) {
            if (A[i] == B[j]) {
                ans += calc1(a1, pi, i-1, b1, pj, j-1) + A[i];
                pi = i;
                pj = j;
                ++i;
                ++j;
            } else if (A[i] < B[j]) {
                ++i;
            } else {
                ++j;
            }
        }
        a2.push_back(0);
        b2.push_back(0);
        ans += max(a2[pi+1], b2[pj+1]);
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;

    while(T--)
    {
        int N,M;
        cin>>N>>M;
        fflush(stdin);
        int a[N],b[M];
        for(int i=0;i<N;i++)
            cin>>a[i];
        for(int i=0;i<M;i++)
            cin>>b[i];
        Solution obj;
        int result = obj.max_path_sum(a,b,N,M);
        cout<<result<<endl;
    }
}


// } Driver Code Ends
