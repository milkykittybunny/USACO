#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fIn("cow.in");
    ofstream fOut("cow.out");

    // solution comes here
    int n;
    fIn >> n;

    vector<char> text(n);
    for (int i = 0; i < n; i++) {
        fIn >> text[i];
    }

    long long lC = 0, lO = 0, lW = 0;

    for (int i = 0; i < n; i++) {
        if (text[i] == 'C') {
            lC++;
        }
        else if (text[i] == 'O') {
            lO += lC;
        }
        else if (text[i] == 'W') {
            lW += lO;
        }
    }
    fOut << lW;

    fIn.close();
    fOut.close();
}