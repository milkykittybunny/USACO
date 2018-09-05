//C++ template for all USACO codes
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> myvector;

    for (int i = 1; i <= 3; i++) {
        myvector.push_back(i);
    }

    //vector iteration
    for (auto it = myvector.begin(); it != myvector.end(); it++) {
        cout << *it;
    }
    cout << endl;
    // vector reverse iteration
    for (auto it = myvector.rbegin(); it != myvector.rend(); it++) {
        cout << *it;
    }
    cout << endl;

    // vector insertion
    myvector.insert(myvector.begin() + 2, 4);
    for (auto it = myvector.begin(); it != myvector.end(); it++) {
        cout << *it;
    }
    cout << endl;
    myvector.erase(myvector.begin() + 2);
    for (auto it = myvector.begin(); it != myvector.end(); it++) {
        cout << *it;
    }
    cout << endl;

    // vector search find
    auto it = find(myvector.begin(), myvector.end(), 2);
    cout << it - myvector.begin();
}