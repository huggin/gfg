//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
        vector <int> rearrange(vector <int> &a,int n)
        {
            // code here
            auto it = partition(a.begin(), a.end(), [](int x){ return x == 1;});
            sort(it, a.end(), greater<int>());
            if (n == 2 && a[n-2] == 3 && a[n-1] == 2 ||
                n > 2 && a[n-2] == 3 && a[n-1] == 2 && a[n-3] == 1) {
                swap(a[n-2], a[n-1]);
            }
            return a;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> a(n);
        for(auto &j:a)
            cin>>j;
        Solution s;
        vector<int> ans=s.rearrange(a,n);
        for(auto j:ans)
            cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
