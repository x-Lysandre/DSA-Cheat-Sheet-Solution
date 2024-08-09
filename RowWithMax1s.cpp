//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int> > &arr) {
        // code here
        // Total rows
        int r = arr.size();
        // Total columns
        int c = arr[0].size();
        
        int max_1s =INT_MIN;
        int max_row = -1;
        
        for(int i = 0;i<r;i++){
            int j =0;
            while(j<c){
                if(arr[i][j]==0){
                    j++;
                }
                else{
                   if(max_1s<c-j){
                       max_1s = c-j;
                       max_row = i;
                   } 
                   break;
                }
            }
        }
        return max_row;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends