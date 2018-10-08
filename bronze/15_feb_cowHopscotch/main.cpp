#include <bits/stdc++.h>
using namespace std;

int gR, gC;
vector<vector<char> > gBoard;


int f(int x, int y) {
    int total = 0;
    if (x == gC - 1 && y == gR - 1) {
        return 1;
    }
    for (int i = x+1; i < gC; i++) {
        for (int j = y+1; j < gR; j++) {
            if (gBoard[i][j] != gBoard[x][y]) {
                total += f(i, j);
            }
        }
    }
    return total;
}


int main() {
    ifstream fIn("hopscotch.in");
    ofstream fOut("hopscotch.out");

    // solution comes here
    fIn >> gR >> gC;
    gBoard.resize(gC, vector<char>(gR));

    for (int i = 0; i < gC; i++) {
        for (int j = 0; j < gR; j++) {
            fIn >> gBoard[i][j];
        }
    }

    int total = f(0, 0);

    fOut << total;

    fIn.close();
    fOut.close();
}