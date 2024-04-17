#include <bits/stdc++.h>
using namespace std;
//Finding the max and min element in an array.

class Solution {
public:
    pair<long long, long long> getMinMax(long long a[], int n) {
        
        long long max_element = a[0];
        long long min_element = a[0];
        pair<long long, long long> ans;
        for(int i =1; i<n;i++){
            max_element = max(max_element, a[i]);
            min_element = min(min_element, a[i]);
        }
        ans = make_pair(min_element, max_element);
        return ans;
        
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) 
    {
        int n;
        cin >> n;
        long long a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        
        Solution ob;
        pair<long long, long long> pp = ob.getMinMax(a, n);
        
        cout << pp.first << " " << pp.second << endl;
    }
    return 0;
}