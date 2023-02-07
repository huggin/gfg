//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
        //code here.
        unordered_map<string, int> m;
        for(int i = 0; i < n; ++i) {
            m[arr[i]]++;
        }
        
        map<int, string> m2;
        for(auto item : m) {
            m2[item.second] = item.first;
        }
        auto it = m2.rbegin();
        ++it;
        if (it == m2.rend()) return "";
        return it->second;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent (arr, n) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
