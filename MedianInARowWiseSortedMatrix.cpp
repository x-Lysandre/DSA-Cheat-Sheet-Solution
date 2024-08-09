//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int median(vector<vector<int>> &matrix, int r, int c){
        // code here       
        
        // First finding the maximum and minimum element in the matrix
        int min = INT_MAX;
        int max = INT_MIN;
        
        for(int i=0;i<r;i++){
            if(matrix[i][0] < min){
                min = matrix[i][0];
            }
            
            if(matrix[i][c-1] > max){
                max = matrix[i][c-1];
            }
        }
        // the half elements either on the right or left side of the median value
        int desired = (r*c)/2;
        
        // Applying the binary search algorithm
        while(min <max){
            // Finding the mid 
            int mid = min + (max-min)/2;
            
            int count = 0;
            
            // Looping through each row
            for(int i =0;i<r;i++){
                // Counting the number of elements smaller than the mid
                count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            // here matrix[i] is used because of the upper_cound functions characeristics]
            }
            
            if(count > desired){
                max = mid ;
            }else{
                min = mid + 1;
            }
        }
        return min;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends