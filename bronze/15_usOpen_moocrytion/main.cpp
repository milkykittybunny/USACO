#include <bits/stdc++.h>
using namespace std;

map<string, int> gMap;
int rows, columns;

void amount_in(vector<vector<char> > puzzleBoard) {
    string sMOO;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns - 2; j++) {
            sMOO = "";
            if (puzzleBoard[i][j+1] == puzzleBoard[i][j+2]
            && puzzleBoard[i][j+1] != puzzleBoard[i][j]) {
                sMOO += puzzleBoard[i][j];
                sMOO += puzzleBoard[i][j+1];
                sMOO += puzzleBoard[i][j+2];
            }
            else if (puzzleBoard[i][j] == puzzleBoard[i][j+1]
            && puzzleBoard[i][j] != puzzleBoard[i][j+2]) {
                sMOO += puzzleBoard[i][j+2];
                sMOO += puzzleBoard[i][j+1];
                sMOO += puzzleBoard[i][j];
            }
            if (sMOO != "") {
                if (gMap.count(sMOO) == 0) {
                    gMap[sMOO] = 1;
                } else {
                    gMap[sMOO]++;
                }
            }
        }
    }

    for (int i = 0; i < rows - 2; i++) {
        for (int j = 0; j < columns; j++) {
            sMOO = "";
            if (puzzleBoard[i+1][j] == puzzleBoard[i+2][j]
                && puzzleBoard[i+1][j] != puzzleBoard[i][j]) {
                sMOO += puzzleBoard[i][j];
                sMOO += puzzleBoard[i+1][j];
                sMOO += puzzleBoard[i+2][j];
            }
            else if (puzzleBoard[i][j] == puzzleBoard[i+1][j]
                     && puzzleBoard[i][j] != puzzleBoard[i+2][j]) {
                sMOO += puzzleBoard[i+2][j];
                sMOO += puzzleBoard[i+1][j];
                sMOO += puzzleBoard[i][j];
            }
            if (sMOO != "") {
                if (gMap.count(sMOO) == 0) {
                    gMap[sMOO] = 1;
                } else {
                    gMap[sMOO]++;
                }
            }
        }
    }

    for (int i = 0; i < rows - 2; i++) {
        for (int j = 0; j < columns - 2; j++) {
            sMOO = "";
            if (puzzleBoard[i+1][j+1] == puzzleBoard[i+2][j+2]
                && puzzleBoard[i+1][j+1] != puzzleBoard[i][j]) {
                sMOO += puzzleBoard[i][j];
                sMOO += puzzleBoard[i+1][j+1];
                sMOO += puzzleBoard[i+2][j+2];
            }
            else if (puzzleBoard[i][j] == puzzleBoard[i+1][j+1]
                     && puzzleBoard[i][j] != puzzleBoard[i+2][j+2]) {
                sMOO += puzzleBoard[i+2][j+2];
                sMOO += puzzleBoard[i+1][j+1];
                sMOO += puzzleBoard[i][j];
            }
            if (sMOO != "") {
                if (gMap.count(sMOO) == 0) {
                    gMap[sMOO] = 1;
                } else {
                    gMap[sMOO]++;
                }
            }
        }
    }

    for (int i = 0; i < rows - 2; i++) {
        for (int j = 2; j < columns; j++) {
            sMOO = "";
            if (puzzleBoard[i+1][j-1] == puzzleBoard[i+2][j-2]
                && puzzleBoard[i+1][j-1] != puzzleBoard[i][j]) {
                sMOO += puzzleBoard[i][j];
                sMOO += puzzleBoard[i+1][j-1];
                sMOO += puzzleBoard[i+2][j-2];
            }
            else if (puzzleBoard[i][j] == puzzleBoard[i+1][j-1]
                     && puzzleBoard[i][j] != puzzleBoard[i+2][j-2]) {
                sMOO += puzzleBoard[i+2][j-2];
                sMOO += puzzleBoard[i+1][j-1];
                sMOO += puzzleBoard[i][j];
            }
            if (sMOO != "") {
                if (gMap.count(sMOO) == 0) {
                    gMap[sMOO] = 1;
                } else {
                    gMap[sMOO]++;
                }
            }
        }
    }
}

int main() {
    ifstream fIn("moocrypt.in");
    ofstream fOut("moocrypt.out");

    // solution comes here
    fIn >> rows >> columns;

    /*
    if (rows < 3 || columns < 3) {

    }*/
    vector<vector<char> > puzzleBoard(rows, vector<char>(columns));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            fIn >> puzzleBoard[i][j];
        }
    }

    amount_in(puzzleBoard);

    int greatest = 0;
    for (auto x : gMap) {
        if (x.second > greatest) {
            greatest = x.second;
        }
    }

    fOut << greatest;

    fIn.close();
    fOut.close();
}