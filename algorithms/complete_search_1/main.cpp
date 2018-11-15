#include <bits/stdc++.h>

using namespace std;

vector<set<int> > complete_set(int n) {
    vector<set<int> > result;
    unsigned int x = 1 << n;
    for (unsigned int i = 0; i < x; i++) {
        set<int> s;
        for (unsigned int j = 0; j < n; j++) {
            unsigned int t = i & (1 << j);
            if (t != 0) {
                s.insert(j);
            }
        }
        result.push_back(s);
    }
    return result;
}

int main() {
    vector<set<int> > result = complete_set(5);
    for (int i = 0; i < result.size(); i++) {
        for (auto it = result[i].begin(); it != result[i].end(); it++) {
            cout << *it << ", ";
        }
        cout << endl;
    }
}