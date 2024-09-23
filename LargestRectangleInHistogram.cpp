#include <bits/stdc++.h>
using namespace std;
//Finding the max area from a histogram with heights given.
// Example = {2,1,5,6,2,3} ans is 10 as 5*2 = 10

vector<int> PreviousSmaller(vector<int> v, int n){
    stack<int> s;
    vector<int> ans;

    for(int i =0;i<n;i++){
        while(!s.empty() && v[s.top()] >= v[i]){
            s.pop();
        }
        // If stack is empty push the element onto it
        if(s.empty()){
            s.push(i);
            ans.push_back(-1);
        }
        // If the top of the stack is smaller the element 
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

    for(int i = n-1;i>=0;i--){
        // If the top of stack is greater than the element
        while(!s.empty() && v[s.top()] >= v[i]){
            s.pop();
        }
        // If stack is empty
        if(s.empty()){
            s.push(i);
            ans.push_back(n);
        }
        // If the top of stack is smaller than the elemen
        else{
            ans.push_back(s.top());
            s.push(i);
        }
        
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int MaxAreaHistogram(vector<int> v, int n){
    vector<int> ps = PreviousSmaller(v, n);
    vector<int> ns = NextSmaller(v, n);

    vector<int> area;

    for(int i = 0;i< n;i++){
        int cal = (ns[i] - ps[i] -1)*v[i];
        area.push_back(cal);
        cout<<cal<<endl;
    }
    auto max_a = max_element(area.begin(), area.end());
    int max_area = *max_a;
    return max_area;
}
int main(){
    vector<int> v = {2,1,5,6,2,3};
    auto ans = MaxAreaHistogram(v, v.size());
    cout<<"The Max area in the histogram is :"<< ans;



    return 0;
}