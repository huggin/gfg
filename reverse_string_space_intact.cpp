//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
  public:
  
    string reverseWithSpacesIntact (string s)
    {
        //code here.
        int n = s.size();
        for(int i = 0, j = n-1; i < j;) {
            while(s[i]==' ') ++i;
            while(s[j]==' ') --j;
            if (i >= j) break;
            swap(s[i], s[j]);
            ++i;
            --j;
        }
        return s;
    }
      

};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    cin.ignore ();
    while (t--)
    {
        string s;
        getline (cin, s);
        Solution ob;
        cout << ob.reverseWithSpacesIntact (s) << endl;
    }
    return 0;
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
