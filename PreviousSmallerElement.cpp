#include <bits/stdc++.h>
using namespace std;

// Function to find the previous smaller elements for all elements in the vector.
vector<int> PreviousSmaller(vector<int> v) {
    vector<int> ans;
    stack<int> s;

    for (auto i : v) {
        // Pop elements from the stack until we find a smaller element.
        while (!s.empty() && s.top() >= i) {
            s.pop();
        }

        // If the stack is empty, no previous smaller element exists.
        if (s.empty()) {
            ans.push_back(-1);
        }
        // Otherwise, the top of the stack is the previous smaller element.
        else {
            ans.push_back(s.top());
        }

        // Push the current element onto the stack.
        s.push(i);
    }
    return ans;
}

int main() {
    vector<int> v = {0,1,1,0};  // Sample vector
    vector<int> result;

    result = PreviousSmaller(v);

    // Print the result
    for (auto i : result) {
        cout << i << " ";
    }

    return 0;
}
