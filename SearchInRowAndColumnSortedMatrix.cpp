#include <bits/stdc++.h>
using namespace std;
//Search an element in an row and column wise sorted matrix

// } Driver Code Ends

class Solution {
  public:
    // Function to search a given number in row-column sorted matrix.
    bool search(vector<vector<int> > &matrix, int n, int m, int x) {
        
        // starting from the top right cornor
        int i = 0, j = m-1;
        
        if(n == 0) return false; // if matrix is empty
        
        bool ans;
        
        while(i<n && j>=0){
            if(matrix[i][j] == x ){
                ans = true;
                return ans;
            }
            else if(matrix[i][j] <x){
                i++; //going to the next row
            }
            else if(matrix[i][j] > x){
                j--;// moving to the previous column
            }
            else{
                ans =  false;
            }
        }
        
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {

        int n, m;
        cin >> n >> m;
        vector<vector<int> > matrix(n);

        for (int i = 0; i < n; i++) {
            matrix[i].assign(m, 0);
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }

        int x;
        cin >> x;
        Solution obj;
        if (obj.search(matrix, n, m, x))
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}