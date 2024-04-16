#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    string reverseWord(string str)
    {
        // Your code goes here
        int n = str.length()-1;
        int i =0;
        while(i<=n/2){
            swap(str[i], str[n-i]);
            i++;
        }
        
        return str;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>> s;
        Solution ob;
        cout<<ob.reverseWord(s) << endl;
    }
}
