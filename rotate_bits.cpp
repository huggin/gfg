//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    uint16_t rotl16 (uint16_t n, unsigned int c)
    {
        const unsigned int mask = (CHAR_BIT*sizeof(n) - 1);  // assumes width is a power of 2.

        c &= mask;
        return (n<<c) | (n>>( (-c)&mask ));
    }

    uint16_t rotr16 (uint16_t n, unsigned int c)
    {
        const unsigned int mask = (CHAR_BIT*sizeof(n) - 1);

        c &= mask;
        return (n>>c) | (n<<( (-c)&mask ));
    }
  public:
        vector <int> rotate (int n, int d)
        {
            //code here.
            d %= 16;

            return vector<int>{rotl16(n, d), rotr16(n, d)};
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        
        int n, d; cin >> n >> d;
        Solution ob;
        vector <int> res = ob.rotate (n, d);
        cout << res[0] << endl << res[1] << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
