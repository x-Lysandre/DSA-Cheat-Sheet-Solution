#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &matrix) {
       vector<int> ans;
       
       int n = matrix.size();
       
       if(n==0) return ans;
       
       int m = matrix[0].size();
       
    //   Total elements of the matrix
       int k = n*m;
       
       int r = 0;
       int c = 0;
       
    //   How many times the loop runs
        int l = 0;
       
    //   traversing all the elements of the matrix
       while(k>0){
           
        //   traversing the first row of the matrix
        while(c<m-l && k>0){
            ans.push_back(matrix[r][c]);
            c++;
            k--;
        }
        r++,c--;
        
        // for the last column
        while(r<n-l && k>0 ){
            ans.push_back(matrix[r][c]);
            k--;
            r++;
        }
        c--,r--;
        
        // traversing the last row
        while(c>=0+l && k>0 ){
            ans.push_back(matrix[r][c]);
            k--;
            c--;
        }
        r--,c++;
        
        // traversing the first columnn
        while(r>0+l && k>0 ){
            ans.push_back(matrix[r][c]);
            k--;
            r--;
        }
        c++,r++;
        l++;
       }
       return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c, 0));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}