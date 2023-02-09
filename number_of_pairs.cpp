//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    int id[100001];
    int count[100001];
    
    int find(int i) {
        while(i != id[i]) {
            id[i] = id[id[i]];
            i = id[i];
        }
        return i;
    }
    
    bool same(int i, int j) {
        return find(i) == find(j); 
    }
    
    void merge(int i, int j) {
        i = find(i);
        j = find(j);
        if (count[i] >= count[j]) {
            id[j] = i;
            count[i] += count[j];
        } else {
            id[i] = j;
            count[j] += count[i];
        }
    }
    public:
        long long int numberOfPairs(vector<vector<int>> &pairs,int p,int n)
        {
            // code here
            for(int i = 0; i < n; ++i) {
                id[i] = i;
                count[i] = 1;
            }
            for(int i = 0; i < p; ++i) {
                if (!same(pairs[i][0], pairs[i][1])) {
                    merge(pairs[i][0], pairs[i][1]);
                }
            }
            vector<long long> v;
            long long ans = 0;
            int k = 1;
            for(int i = 0; i < n; ++i) {
                if (id[i] == i) {
                    if (count[i] == 1) {
                        ans += n-k;
                        ++k;
                    }
                    else v.push_back(count[i]);
                }
            }
            
            for(int i = 0; i < v.size(); ++i) {
                for(int j = i+1; j < v.size(); ++j) {
                    ans += v[i] * v[j];
                }
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
        int n,p;
        cin>>n>>p;
        vector<vector<int>> pairs(p,vector<int>(2));
        for(auto &i:pairs)
            for(auto &j:i)
                cin>>j;
        Solution a;
        cout<<a.numberOfPairs(pairs,p,n)<<endl;
    }
}
// } Driver Code Ends
