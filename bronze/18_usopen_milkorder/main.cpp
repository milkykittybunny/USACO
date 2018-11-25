#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fIn("milkorder.in");
    ofstream fOut("milkorder.out");

    // solution comes here
    int n, m, k;
    fIn >> n >> m >> k;

    vector<int> mlst;
    vector<int> corder(n);

    for (int i = 0; i < m; i++) {
        fIn >> mlst[i];
    }

    for (int i = 0; i < k; i++) {
        int cow, place;
        fIn >> cow >> place;
        corder[place - 1] = cow;
    }

    for (int i = 0; i < corder.size() - 1; i++) {
        if (corder[i]
    }

    fIn.close();
    fOut.close();
}
