#include<bits/stdc++.h>
//n = 4, m = 4
// M[][] = {{0 1 1 0},
//          {1 1 1 1},
//          {1 1 1 1},
//          {1 1 0 0}}
// Output: 8
// Explanation: For the above test case the
// matrix will look like
// 0 1 1 0
// 1 1 1 1
// 1 1 1 1
// 1 1 0 0
// the max size rectangle is 
// 1 1 1 1
// 1 1 1 1
// and area is 4 *2 = 8.

using namespace std;

vector<int> PreviousSmaller(vector<int> v, int n){
    stack<int> s;
    vector<int> ans;
    for(int i =0;i<n;i++){
        //if the top of the stack is greater than the element
        while(!s.empty() && v[s.top()] >= v[i]){
            s.pop();
        }

        // If the stack is empty 
        if(s.empty()){
            s.push(i);
            ans.push_back(-1);
        }

        // If the top of the stack is samller than the element 
        else{
            ans.push_back(s.top());
            s.push(i);
        }

    }
    
    return ans;    
}

vector<int> NextSmaller(vector<int> v, int n){
    stack<int> s;
    vector<int> ans;

    for(int i = n-1;i>-1;i--){
        //If the top element is greater than the element
        while(!s.empty() && v[s.top()] >= v[i]){
            s.pop();
        }
        //If stack is empty 
        if(s.empty()){
            s.push(i);
            ans.push_back(n);
        }
        //If the top of the stack is samller than the element
        else{
            ans.push_back(s.top());
            s.push(i);
        }

    }
    reverse(ans.begin(), ans.end());
        
    return ans;
}

int Area_51(vector<int> a, vector<int> b, vector<int> v){
    int x;
    vector<int> area;
    for(int i = 0;i< a.size() ;i++){
        x = (b[i] - a[i] -1)*v[i];
        area.push_back(x);
    }
    for(auto i: area){
        cout <<i;
    }
    cout<<endl;
    auto max_area = max_element(area.begin(), area.end());
    int max = *max_area;
    cout<<max<<endl;
    return max;   
}

int maxArea(vector<vector<int>> M, int n, int m) {
    vector<int> height(m,0);
    int maxarea = 0;
    for(int i =0;i< n;i++){
        for (int j = 0; j < m; j++) {
            height[j] = (M[i][j] == 0) ? 0 : height[j] + 1;
        }
        vector<int> ps = PreviousSmaller(height, m);;
        vector<int> ns = NextSmaller(height, m);;
       
        
        maxarea = max(maxarea, Area_51(ps, ns, height));        
    }
    return maxarea;
}

int main(){
    vector<vector<int>> M = {{0, 1, 1, 0},
         {1, 1, 1, 1},
         {1, 1, 1, 1},
        {1, 1, 0, 0}};
    int ans; 
    ans = maxArea(M, M.size(), M[0].size());
    cout<<"The Max area in the binary matrix is: "<< ans;    

    return 0;
}