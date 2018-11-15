#include <bits/stdc++.h>

using namespace std;

int N = 3;
vector<vector<int> > result;
vector<int> x(N);

void generate(vector<int> current) {
    auto it = find(x.begin(), x.end(), 0);
    if (it == x.end()) {
        result.push_back(current);
    }
    else {
        for (int i = 0; i < N; i++) {
            if (x[i] == 0) {
                x[i] = 1;
                current.push_back(i);
                generate(current);
                current.pop_back();
                x[i] = 0;
            }
        }
    }
}

int main() {
    vector<int> current;
    generate(current);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < N; j++) {
            cout << result[i][j] << ", ";
        }
        cout << endl;
    }
}