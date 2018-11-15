#include <bits/stdc++.h>

using namespace std;

int N = 5;
vector<set<int> > result;

void generate(int k, set<int> current) {
    if (k == N) {
        result.push_back(current);
    }
    else {
        generate(k+1, current);
        current.insert(k);
        generate(k+1, current);
    }
}

int main() {
    set<int> current;
    generate(0, current);
    for (int i = 0; i < result.size(); i++) {
        for (auto it = result[i].begin(); it != result[i].end(); it++) {
            cout << *it << ", ";
        }
        cout << endl;
    }
}