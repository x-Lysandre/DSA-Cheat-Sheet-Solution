#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:

    void Transpose(vector<vector<int>> & matrix, int n){
        for(int i = 0;i<n-1;i++){
            for(int j = i+1;j<n;j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }

    void rotateby90(vector<vector<int>> & matrix, int n){
        Transpose(matrix, n);

        for(int i =0;i<n;i++){
            swap(matrix[0][i], matrix[n-1][i]);
        }
    }
};

int main(){
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(n, 0);
            for( int j=0; j<n; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        ob.rotateby90(matrix, n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cout<<matrix[i][j]<<" ";
            cout<<endl;
    }
    return 0;
}