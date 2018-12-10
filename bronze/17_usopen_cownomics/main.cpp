#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fIn("cownomics.in");
    ofstream fOut("cownomics.out");

    // solution comes here
    int n, m;
    fIn >> n >> m;

    vector<vector<char> > spotted(n, vector<char> (m));
    vector<vector<char> > plain(n, vector<char> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fIn >> spotted[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fIn >> plain[i][j];
        }
    }

    int count = 0;
    for (int i = 0; i < m; i++) {
        set<char> sSpotted;
        set<char> sPlain;
        bool flag = true;
        for (int j = 0; j < n; j++) {
            sSpotted.insert(spotted[j][i]);
            sPlain.insert(plain[j][i]);
        }
        for (auto it = sSpotted.begin(); it != sSpotted.end(); it++) {
            if (sPlain.find(*it) != sPlain.end()) {
                flag = false;
            }
        }
        if (flag) {
            count++;
        }
    }


    fOut << count;

    fIn.close();
    fOut.close();
}